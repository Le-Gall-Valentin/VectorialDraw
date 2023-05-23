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
Pixel *createPixel(int px, int py);
void deletePixel(Pixel * pixel);
void pixelLine(Line *line, CellOfPixels **pixels);
void pixelPoint(Point *point, CellOfPixels **pixels);
void pixelCircle(Circle * circle, CellOfPixels** pixels);
void pixelSquare(Square * square, CellOfPixels** pixels);
void pixelRectangle(Rectangle * rectangle, CellOfPixels ** pixels);
void pixelPolygon(Polygon * polygon, CellOfPixels **pixels);
CellOfPixels *createShapeToPixel(Shape* shape);
void deletePixelShape(CellOfPixels *pixels);
int lenOfLLCPixels(CellOfPixels* pixels);
void addLLCOfPixelsInMatrixOfInts(CellOfPixels* pixels, int** matrix, unsigned int width, unsigned int height);
void removeLLCOfPixelsInMatrixOfInts(CellOfPixels* pixels, int** matrix);




#endif //DESSIN7_PIXEL_H
