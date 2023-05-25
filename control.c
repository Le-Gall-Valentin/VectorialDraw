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
    printf("Available orders :\n\n");
    printf("point x y\n");
    printf("line x1 y1 x2 y2\n");
    printf("circle x y rayon\n");
    printf("square x y length\n");
    printf("rectangle x y width height\n");
    printf("polygon x1, y1, x(n), x(n+1)\n");
    printf("erase (delete all forms)\n");
    printf("plot (display forms)\n");
    printf("clear (clear screen)\n");
    printf("list (list of all forms + ID)\n");
    printf("delete ID (delete 1 form with her id)\n");
    printf("exit (quit)\n");
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



