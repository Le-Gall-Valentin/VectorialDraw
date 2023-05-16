//
// Created by Le Gall on 24/03/2023.
//

#include "line.h"
Line* create_line(Point *p1,Point *p2){
    Line * line = (Line*)malloc(sizeof(Line));
    line->point1 = p1;
    line->point2 = p2;
    return line;
}
void delete_line(Line * line){
    delete_point(line->point1);
    delete_point(line->point2);
    free(line);
    line = NULL;
}
void print_line(Line * line){
    printf("(Line) point : (%d, %d) | point : (%d, %d)", (line->point1)->x, (line->point1)->y, (line->point2)->x, (line->point2)->y);
}
