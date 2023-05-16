//
// Created by Le Gall on 21/04/2023.
//

#ifndef DESSIN6_MANAGEID_H
#define DESSIN6_MANAGEID_H
#include "Shape.h"
#include "CellOfForms.h"

CellOfForms *getShapeById(unsigned int id, CellOfForms* array);
Shape *getFormById(unsigned int id, CellOfForms*);

#endif //DESSIN6_MANAGEID_H
