//
// Created by Le Gall on 21/04/2023.
//

#ifndef DESSIN6_CELLOFFORMS_H
#define DESSIN6_CELLOFFORMS_H
#include "Shape.h"

typedef struct CellOfForms{
    Shape *value;
    struct CellOfForms *next;
}CellOfForms;

void addCellOfFormsInArray(CellOfForms **Array, Shape *form);
void deleteCellOfForms(CellOfForms **array, CellOfForms *cell);
void deleteAllCells(CellOfForms **array);

#endif //DESSIN6_CELLOFFORMS_H
