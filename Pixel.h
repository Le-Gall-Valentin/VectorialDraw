//
// Created by Le Gall on 22/04/2023.
//

#ifndef DESSIN7_PIXEL_H
#define DESSIN7_PIXEL_H
#include "Shape.h"

typedef struct{
    int x;
    int y;
}Pixel;

typedef struct CellOfPixels {
    Pixel *pixel;
    struct CellOfPixels* next;
} CellOfPixels;

void addCellOfPixelInArray(CellOfPixels **Array, Pixel *pixel);
Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel * pixel);
void pixel_line(Line *line, CellOfPixels **pixels);
void pixel_point(Point *point, CellOfPixels **pixels);
void pixel_circle(Circle * circle, CellOfPixels** pixels);
void pixel_square(Square * square, CellOfPixels** pixels);
void pixel_rectangle(Rectangle * rectangle, CellOfPixels ** pixels);
void pixel_polygon(Polygon * polygon, CellOfPixels **pixels);
CellOfPixels *create_shape_to_pixel(Shape* shape);
void delete_pixel_shape(CellOfPixels *pixels);
int lenOfLLCPixels(CellOfPixels* pixels);
void addLLCOfPixelsInMatrixOfInts(CellOfPixels* pixels, int** matrix);
void removeLLCOfPixelsInMatrixOfInts(CellOfPixels* pixels, int** matrix);




#endif //DESSIN7_PIXEL_H
