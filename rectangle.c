//
// Created by Le Gall on 24/03/2023.
//

#include "rectangle.h"
Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle *rectangle = (Rectangle*) malloc(sizeof (Rectangle));
    rectangle->point = point;
    rectangle->height = height;
    rectangle->width = width;
    return rectangle;
}
void delete_rectangle(Rectangle *rectangle){
    delete_point(rectangle->point);
    free(rectangle);
    rectangle = NULL;

}
void print_rectangle(Rectangle * rectangle){
    printf("(Rectangle) point : (%d, %d) | width : %d | height : %d", rectangle->point->x, rectangle->point->y, rectangle->width, rectangle->height);
}