//
// Created by Le Gall on 24/03/2023.
//

#include "circle.h"
Circle *create_circle(Point * center, int radius){
    Circle *circle = (Circle*) malloc(sizeof (Circle));
    circle->center = center;
    circle->radius = radius;
    return circle;
}
void delete_circle(Circle * circle){
    delete_point(circle->center);
    free(circle);
    circle = NULL;
}
void print_circle(Circle * circle){
    printf("(Circle) center : (%d, %d) | radius : %d", circle->center->x, circle->center->y, circle->radius);
}