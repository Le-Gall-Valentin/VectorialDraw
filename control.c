//
// Created by Le Gall on 27/03/2023.
//

#include "control.h"

void delete(unsigned int id, Area* area) {
    CellOfForms *cell = getShapeById(id, area->forms);
    if (cell != NULL) {
        deleteFormInAreaMatrix(&area, cell);
        deleteForm(cell->value);
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
            clear_area(area);
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
            print_area(area);
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


