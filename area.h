//
// Created by Le Gall on 22/04/2023.
//

#ifndef DESSIN6_AREA_H
#define DESSIN6_AREA_H
#include "CellOfForms.h"
#include "Pixel.h"

typedef struct{
    unsigned int width;
    unsigned int height;
    int** matrix;
    CellOfForms *forms;
    int nbForms;
}Area;

Area* createArea(unsigned int width, unsigned int height);
int** createMatrix(unsigned int width, unsigned int height);
void addShapeToArea(Area** area, Shape* shape);
void clearArea(Area* area);
void deleteMatrixOfArea(Area* area);
void eraseArea(Area* area);
void deleteArea(Area* area);
void printArea(Area* area);
void deleteFormInAreaMatrix(Area** area, CellOfForms* form);

#endif //DESSIN6_AREA_H
