//
// Created by Le Gall on 24/03/2023.
//

#include "rectangle.h"

// Crée et initialise une instance de la structure Rectangle avec le point, la largeur et la hauteur spécifiés
Rectangle *createRectangle(Point *point, int width, int height){
    // Allouer de la mémoire pour la structure Rectangle
    Rectangle *rectangle = (Rectangle*) malloc(sizeof(Rectangle));
    rectangle->point = point;
    rectangle->height = height;
    rectangle->width = width;
    return rectangle;
}

// Libère la mémoire allouée pour un objet Rectangle
void deleteRectangle(Rectangle *rectangle){
    // Supprimer le point associé au rectangle
    deletePoint(rectangle->point);

    // Libérer la mémoire allouée pour la structure Rectangle
    free(rectangle);
    rectangle = NULL;
}

// Affiche les informations d'un rectangle sur la console
void printRectangle(Rectangle *rectangle){
    printf("(Rectangle) point : (%d, %d) | width : %d | height : %d", rectangle->point->x, rectangle->point->y, rectangle->width, rectangle->height);
}