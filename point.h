//
// Created by Le Gall on 24/03/2023.
//

#ifndef VECT_POINT_H
#define VECT_POINT_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}Point;

Point *createPoint(int x, int y);
void deletePoint(Point *point);
void printPoint(Point *p);

#endif //VECT_POINT_H
