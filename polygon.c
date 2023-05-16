//
// Created by Le Gall on 24/03/2023.
//
#include "polygon.h"

Polygon *create_polygon(unsigned int n){
    Polygon *polygon = (Polygon*)malloc(sizeof(Polygon));
    polygon->n = n;
    polygon->points =  (Point**)malloc(n*sizeof(Point));
    return polygon;
}

void delete_polygon(Polygon * polygon){
    for(int i=0; i < polygon->n; i++){
        delete_point(polygon->points[i]);
    }
    free(polygon->points);
    polygon->points = NULL;
    free(polygon);
    polygon = NULL;
}


void print_polygon(Polygon * polygon){
    printf("(Polygon) points :%d", polygon->n);
    for(int i=0; i < polygon->n; i++){
        printf(" | point : (%d, %d)", (polygon->points)[i]->x, (polygon->points)[i]->y);
    }
}
