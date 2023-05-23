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
Line* createLine(Point *p1, Point *p2);
void deleteLine(Line * Line);
void printLine(Line * Line);

#endif //VECT_LINE_H
