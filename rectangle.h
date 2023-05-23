//
// Created by Le Gall on 24/03/2023.
//

#ifndef VECT_RECTANGLE_H
#define VECT_RECTANGLE_H
#include "point.h"

typedef struct{
    Point *point;
    int width;
    int height;
}Rectangle;
Rectangle *createRectangle(Point * point, int width, int height);
void deleteRectangle(Rectangle * rectangle);
void printRectangle(Rectangle * rectangle);

#endif //VECT_RECTANGLE_H
