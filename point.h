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

Point *create_point(int x, int y);
void delete_point(Point *point);
void print_point(Point *p);

#endif //VECT_POINT_H
