//
// Created by Le Gall on 24/03/2023.
//
#include "polygon.h"

// Crée et initialise une instance de la structure Polygon avec le nombre de points spécifié
Polygon *createPolygon(unsigned int n){
    // Allouer de la mémoire pour la structure Polygon
    Polygon *polygon = (Polygon*)malloc(sizeof(Polygon));
    polygon->n = n;

    // Allouer de la mémoire pour le tableau de pointeurs de Point
    polygon->points = (Point**)malloc(n * sizeof(Point*));

    return polygon;
}

// Libère la mémoire allouée pour un objet Polygon
void deletePolygon(Polygon *polygon){
    // Parcourir tous les points du polygon et les supprimer
    for(int i=0; i < polygon->n; i++){
        deletePoint(polygon->points[i]);
    }

    // Libérer la mémoire allouée pour le tableau de pointeurs de Point
    free(polygon->points);
    polygon->points = NULL;

    // Libérer la mémoire allouée pour la structure Polygon
    free(polygon);
    polygon = NULL;
}

// Affiche les informations d'un polygon sur la console
void printPolygon(Polygon *polygon){
    printf("(Polygon) points: %d", polygon->n);

    // Parcourir tous les points du polygon et les afficher
    for(int i=0; i < polygon->n; i++){
        printf(" | point : (%d, %d)", polygon->points[i]->x, polygon->points[i]->y);
    }
}
