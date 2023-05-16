//
// Created by Le Gall on 24/03/2023.
//
#include "point.h"

Point *create_point(int x, int y)
{
    Point *point = (Point*)malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}
void delete_point(Point *point){
    free(point);
    point = NULL;
}
void print_point(Point *p){
    printf("(Points) point : (%d, %d)", p->x, p->y);
}
