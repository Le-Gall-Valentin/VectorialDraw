//
// Created by Le Gall on 24/03/2023.
//

#include "square.h"
Square *create_square(Point * point, int length){
    Square *square = (Square*)malloc(sizeof(Square));
    square->length = length;
    square->point = point;
    return square;
}


void delete_square(Square * square){
    delete_point(square->point);
    free(square);
    square = NULL;
}
void print_square(Square * square){
    printf("(Square) point : (%d, %d) | length : %d",(square->point)->x,(square->point)->y, square->length);

}