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
Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);


#endif //VECT_SQUARE_H
