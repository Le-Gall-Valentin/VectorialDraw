//
// Created by Le Gall on 24/03/2023.
//

#include "line.h"

Line* createLine(Point *p1, Point *p2){
    // Alloue un espace mémoire pour une structure Line
    Line * line = (Line*)malloc(sizeof(Line));

    line->point1 = p1;
    line->point2 = p2;

    return line;
}

void deleteLine(Line * Line){
    // Supprime les points de la ligne
    deletePoint(Line->point1);
    deletePoint(Line->point2);

    free(Line);
    Line = NULL;
}

void printLine(Line * Line){
    // Affiche les informations de la ligne (points)
    printf("(Line) point : (%d, %d) | point : (%d, %d)", (Line->point1)->x, (Line->point1)->y, (Line->point2)->x, (Line->point2)->y);
}

