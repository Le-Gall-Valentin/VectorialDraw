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
Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);



#endif //VECT_CIRCLE_H
