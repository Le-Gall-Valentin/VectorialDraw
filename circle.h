//
// Created by Le Gall on 24/03/2023.
//

#ifndef VECT_CIRCLE_H
#define VECT_CIRCLE_H
#include "point.h"

typedef struct{
    Point *center;
    int radius;
}Circle;
Circle *createCircle(Point * center, int radius);
void deleteCircle(Circle * circle);
void printCircle(Circle * circle);



#endif //VECT_CIRCLE_H
