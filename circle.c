//
// Created by Le Gall on 24/03/2023.
//

#include "circle.h"

Circle *createCircle(Point * center, int radius){
    // Alloue un espace mémoire pour une structure Circle
    Circle *circle = (Circle*) malloc(sizeof(Circle));

    circle->center = center;
    circle->radius = radius;

    return circle;
}

void deleteCircle(Circle * circle){
    // Supprime le point du centre du cercle
    deletePoint(circle->center);

    free(circle);
    circle = NULL;
}

void printCircle(Circle * circle){
    // Affiche les informations du cercle (centre et rayon)
    printf("(Circle) center : (%d, %d) | radius : %d", circle->center->x, circle->center->y, circle->radius);
}
