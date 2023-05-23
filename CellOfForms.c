//
// Created by Le Gall on 21/04/2023.
//

#include "CellOfForms.h"

CellOfForms *createCellOfForms(Shape *form) {
    // Alloue un espace mémoire pour une structure CellOfForms
    CellOfForms *cell = (CellOfForms *) malloc(sizeof(CellOfForms));

    cell->value = form;
    cell->next = NULL;

    return cell;
}

void addCellOfFormsInArray(CellOfForms **Array, Shape *form) {
    if (*Array == NULL) {
        // Si le tableau est vide, crée une nouvelle cellule et l'assigne au tableau
        *Array = createCellOfForms(form);
    } else {
        // Si le tableau n'est pas vide, crée une nouvelle cellule et l'insère au début du tableau
        CellOfForms *newCell = createCellOfForms(form);
        newCell->next = *Array;
        *Array = newCell;
    }
}

void deleteCellOfForms(CellOfForms **array, CellOfForms *cell) {
    if (*array != NULL) {
        CellOfForms *temporaryCell = *array;

        if ((*array) == cell) {
            // Si la cellule à supprimer est la première cellule du tableau
            *array = (*array)->next;
            free(temporaryCell);
        } else {
            CellOfForms *precursor = NULL;

            // Parcours du tableau pour trouver la cellule précédant celle à supprimer
            while (temporaryCell != cell) {
                precursor = temporaryCell;
                temporaryCell = temporaryCell->next;
            }

            // Met à jour les pointeurs pour retirer la cellule du tableau
            precursor->next = temporaryCell->next;
            free(temporaryCell);
        }
    }
}

void deleteAllCells(CellOfForms **array){
    if((*array)->next != NULL){
        deleteAllCells(&((*array)->next));
    }
    deleteForm((*array)->value);
    free(*array);
    *array = NULL;
}