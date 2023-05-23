//
// Created by Le Gall on 24/03/2023.
//
#include "point.h"

// Crée et initialise une instance de la structure Point avec les coordonnées spécifiées
Point *createPoint(int x, int y)
{
    // Allouer de la mémoire pour la structure Point
    Point *point = (Point*)malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

// Libère la mémoire allouée pour un objet Point
void deletePoint(Point *point){
    free(point);
    point = NULL;
}

// Affiche les coordonnées d'un point sur la console
void printPoint(Point *p){
    printf("(Points) point : (%d, %d)", p->x, p->y);
}
