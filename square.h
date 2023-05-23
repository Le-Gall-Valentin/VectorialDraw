//
// Created by Le Gall on 24/03/2023.
//

#ifndef VECT_SQUARE_H
#define VECT_SQUARE_H
#include "point.h"

typedef struct{
    Point *point;
    int length;
}Square;
Square *createSquare(Point * point, int length);
void deleteSquare(Square * square);
void printSquare(Square * square);


#endif //VECT_SQUARE_H
