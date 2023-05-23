//
// Created by Le Gall on 24/03/2023.
//

#include "square.h"

// Crée un objet Square à partir d'un point et d'une longueur spécifiés
Square *createSquare(Point *point, int length){
    Square *square = (Square*)malloc(sizeof(Square));
    square->length = length;
    square->point = point;
    return square;
}

// Supprime un objet Square et libère la mémoire associée
void deleteSquare(Square *square){
    deletePoint(square->point);
    free(square);
    square = NULL;
}

// Affiche les informations d'un objet Square
void printSquare(Square *square){
    printf("(Square) point : (%d, %d) | length : %d", (square->point)->x, (square->point)->y, square->length);
}