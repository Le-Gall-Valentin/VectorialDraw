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

Area* create_area(unsigned int width, unsigned int height);
int** create_matrix(unsigned int width, unsigned int height);
void add_shape_to_area(Area** area, Shape* shape);
void clear_area(Area* area);
void deleteMatrixOfArea(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);
void deleteFormInAreaMatrix(Area** area, CellOfForms* form);

#endif //DESSIN6_AREA_H
