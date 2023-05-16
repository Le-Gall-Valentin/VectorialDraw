//
// Created by Le Gall on 24/03/2023.
//

#ifndef VECT_LINE_H
#define VECT_LINE_H
#include "point.h"

typedef struct
{
    Point *point1;
    Point *point2;
}Line;
Line* create_line(Point *p1,Point *p2);
void delete_line(Line * Line);
void print_line(Line * Line);

#endif //VECT_LINE_H
