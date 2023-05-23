#define maxSizeCommand 100
#include <stdio.h>
#include "manageString.h"
#include "Shape.h"
#include "manageCommand.h"
#include "control.h"

int main() {
    Area* area = createArea(50, 50); // Crée une nouvelle aire de taille 40x40

    char command[maxSizeCommand]; // Déclare une variable pour stocker la commande saisie
    int end = FALSE; // Variable pour vérifier si le programme doit se terminer

    while(end == FALSE){
        printf(">>");
        gets(command); // Récupère la commande saisie par l'utilisateur

        StringArray splitedString = splitStringToArray(command, " "); // Sépare la commande en mots

        if(checkCommand(splitedString)){
            int type = returnFormOrControl(splitedString); // Vérifie le type de la commande (forme ou contrôle)

            if(type == FORM){
                void* formChoice = createFormWithHerStruct(splitedString); // Crée la forme correspondante à la commande saisie
                addShapeToArea(&area, createForm(returnTypeOfCommand(splitedString.array[0]), formChoice)); // Ajoute la forme à l'aire
            }else{
                executeControl(splitedString, area, &end); // Exécute la commande de contrôle correspondante
            }
        }else{
            printf("Mauvaise commande faite. Utilisez la commande 'help' pour obtenir la liste des commandes.\n");
        }
    }
    deleteArea(area);

    return 0;
}
