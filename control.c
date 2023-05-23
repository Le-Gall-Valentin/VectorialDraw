//
// Created by Le Gall on 27/03/2023.
//

#include "control.h"

void delete(unsigned int id, Area* area) {
    // Recherche de la forme avec l'ID spécifié dans la liste des formes de l'aire
    CellOfForms *cell = getShapeById(id, area->forms);

    if (cell != NULL) {
        // Suppression de la forme de la matrice de l'aire
        deleteFormInAreaMatrix(&area, cell);

        // Suppression de la forme elle-même
        deleteForm(cell->value);

        // Suppression de la cellule de la liste des formes de l'aire
        deleteCellOfForms(&area->forms, cell);
    }
}

void quit(int *end) {
    printf("Au Revoir !");
    *end = TRUE;
}

void list(CellOfForms *forms) {
    if (forms == NULL) {
        printf("Empty list\n");
    } else {
        CellOfForms *temporaryArray = forms;
        while (temporaryArray != NULL) {
            // Affichage de chaque forme dans la liste
            printForm(temporaryArray->value);
            temporaryArray = temporaryArray->next;
        }
    }
}

void help() {
    printf("Commandes disponibles :\n");
    printf("(point, line,circle,square,rectangle, polygon) + points\n");
    printf("erase \n");
    printf("plot \n");
    printf("clear \n");
    printf("list \n");
    printf("delete ID \n");
    printf("exit \n");
}

void executeControl(StringArray command, Area *area, int *end) {
    switch (returnTypeOfCommand(command.array[0])) {
        case cmdDelete: {
            delete(convertStringToDigit(command.array[1]), area);
            break;
        }
        case cmdErase: {
            clearArea(area);
            break;
        }
        case cmdHelp: {
            help();
            break;
        }
        case cmdList: {
            list(area->forms);
            break;
        }
        case cmdPlot: {
            printArea(area);
            break;
        }
        case cmdClear: {
            system("cls");
            break;
        }
        case cmdQuit: {
            quit(end);
            break;
        }
        default:
            break;
    }
}



