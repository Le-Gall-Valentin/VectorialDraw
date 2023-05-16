//
// Created by Le Gall on 24/03/2023.
//

#ifndef VECT_POLYGON_H
#define VECT_POLYGON_H
#include "point.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    unsigned int n;
    Point **points;
}Polygon;


Polygon *create_polygon(unsigned int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

#endif //VECT_POLYGON_H
