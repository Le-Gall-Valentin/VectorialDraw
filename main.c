#define maxSizeCommand 100
#include <stdio.h>
#include "manageString.h"
#include "Shape.h"
#include "manageCommand.h"
#include "control.h"

int main() {
    Area* area = create_area(40, 40);
    char command[maxSizeCommand];
    int end = FALSE;
    while(end == FALSE){
        printf(">>");
        gets(command);
        StringArray splitedString = splitStringToArray(command, " ");
        if(checkCommand(splitedString)){
            int type = returnFormOrControl(splitedString);
            if(type == FORM){
                void* formChoice = createFormWithHerStruct(splitedString);
                add_shape_to_area(&area, createForm(returnTypeOfCommand(splitedString.array[0]), formChoice));
            }else{
                executeControl(splitedString, area, &end);
            }
        }else{
            printf("Mauvaise commande faites la commande help pour avoir la liste des commandes\n");
        }
    }
    return 0;
}