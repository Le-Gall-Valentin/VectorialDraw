//
// Created by Le Gall on 21/04/2023.
//

#include "CellOfForms.h"

CellOfForms *createCellOfForms(Shape *form) {
    CellOfForms *cell = (CellOfForms *) malloc(sizeof(CellOfForms));
    cell->value = form;
    cell->next = NULL;
    return cell;
}

void addCellOfFormsInArray(CellOfForms **Array, Shape *form) {
    if (*Array == NULL) {
        *Array = createCellOfForms(form);
    } else {
        CellOfForms *newCell = createCellOfForms(form);
        newCell->next = *Array;
        *Array = newCell;
    }
}

void deleteCellOfForms(CellOfForms **array, CellOfForms *cell) {
    if (*array != NULL) {
        CellOfForms *temporaryCell = *array;
        if ((*array) == cell) {
            *array = (*array)->next;
            free(temporaryCell);
        } else {
            CellOfForms *precursor = NULL;
            while (temporaryCell != cell) {
                precursor = temporaryCell;
                temporaryCell = temporaryCell->next;
            }
            precursor->next = temporaryCell->next;
            free(temporaryCell);
        }
    }
}