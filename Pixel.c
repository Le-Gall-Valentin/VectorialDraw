//
// Created by Le Gall on 22/04/2023.
//

#include "Pixel.h"

Pixel *create_pixel(int px, int py) {
    Pixel *pixel = (Pixel *) malloc(sizeof(Pixel));
    pixel->x = px;
    pixel->y = py;
    return pixel;
}

void delete_pixel(Pixel *pixel) {
    free(pixel);
}

void pixel_point(Point *point, CellOfPixels **pixels) {
    addCellOfPixelInArray(pixels, create_pixel(point->x, point->y));
}

void pixel_line(Line *line, CellOfPixels **pixels){
    Point point2 = *(line->point2);
    Point point1 = *(line->point1);
    int dx = abs(point2.x - point1.x);
    int dy = abs(point2.y - point1.y);
    int sx, sy;
    if (point1.x < point2.x) {
        sx = 1;
    } else {
        sx = -1;
    }
    if (point1.y < point2.y) {
        sy = 1;
    } else {
        sy = -1;
    }
    int err = dx - dy;
    while (point1.x != point2.x || point1.y != point2.y) {
        Pixel *p = create_pixel(point1.x, point1.y);
        addCellOfPixelInArray(pixels, p);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err = err - dy;
            point1.x = point1.x + sx;
        }
        if (e2 < dx) {
            err = err + dx;
            point1.y = point1.y + sy;
        }
    }
    Pixel *p = create_pixel(point2.x, point2.y);
    addCellOfPixelInArray(pixels, p);
}

void pixel_circle(Circle *circle, CellOfPixels **pixels) {
    Point center = *(circle->center);
    int radius = (circle->radius);
    int x = 0;
    int y = radius;
    int delta = radius - 1;
    while (y >= x) {
        addCellOfPixelInArray(pixels, create_pixel(center.x + x, center.y + y));
        addCellOfPixelInArray(pixels,create_pixel(center.x + y, center.y + x));
        addCellOfPixelInArray(pixels,create_pixel(center.x - x, center.y + y));
        addCellOfPixelInArray(pixels,create_pixel(center.x - y, center.y + x));
        addCellOfPixelInArray(pixels,create_pixel(center.x + x, center.y - y));
        addCellOfPixelInArray(pixels,create_pixel(center.x + y, center.y - x));
        addCellOfPixelInArray(pixels,create_pixel(center.x - x, center.y - y));
        addCellOfPixelInArray(pixels,create_pixel(center.x - y, center.y - x));
        if (delta >= (2 * x)) {
            delta -= (2 * x) + 1;
            x++;
        } else if (delta < 2 * (radius - y)) {
            delta += (2 * y) - 1;
            y--;
        } else {
            delta += (2 * (y - x - 1));
            y--;
            x++;
        }
    }
}

void pixel_square(Square *square, CellOfPixels **pixels) {
    for (int i = 0; i < square->length; ++i) {
        addCellOfPixelInArray(pixels,create_pixel(square->point->x, (square->point->y) + i));
        addCellOfPixelInArray(pixels,create_pixel((square->point->x) + (square->length) - 1, (square->point->y) + i));
        addCellOfPixelInArray(pixels,create_pixel((square->point->x) + i, (square->point->y) + (square->length) - 1));
        addCellOfPixelInArray(pixels,create_pixel((square->point->x) + i, square->point->y));
    }
}

void pixel_rectangle(Rectangle *rectangle, CellOfPixels **pixels) {
    for (int i = 0; i < rectangle->width; ++i) {
        addCellOfPixelInArray(pixels, create_pixel(rectangle->point->x, (rectangle->point->y) + i));
        addCellOfPixelInArray(pixels,create_pixel((rectangle->point->x) + (rectangle->height) - 1,
                                                  (rectangle->point->y) + i));
    }
    for (int i = 0; i < rectangle->height; ++i) {
        addCellOfPixelInArray(pixels,create_pixel((rectangle->point->x) + i, (rectangle->point->y) + (rectangle->width) - 1));
        addCellOfPixelInArray(pixels,create_pixel((rectangle->point->x) + i, rectangle->point->y));
    }
}

void pixel_polygon(Polygon *polygon, CellOfPixels **pixels) {
    for (int i = 0; i < polygon->n; ++i) {
        if (i == (polygon->n) - 1) {
            Line *line = create_line(create_point(polygon->points[i]->x, polygon->points[i]->y), create_point(polygon->points[0]->x, polygon->points[0]->y));
            pixel_line(line, pixels);
            delete_line(line);
        } else {
            Line *line = create_line(create_point(polygon->points[i]->x, polygon->points[i]->y), create_point(polygon->points[i+1]->x, polygon->points[i+1]->y));
            pixel_line(line, pixels);
            delete_line(line);
        }
    }
}

CellOfPixels *create_shape_to_pixel(Shape* shape){
    CellOfPixels* pixels = NULL;
    switch (shape->type) {
        case cmdLine:
            pixel_line((Line*)(shape->realForm), &pixels);
            break;
        case cmdPoint:
            pixel_point((Point*)(shape->realForm), &pixels);
            break;
        case cmdCircle:
            pixel_circle((Circle *)(shape->realForm), &pixels);
            break;
        case cmdPolygon:
            pixel_polygon((Polygon *)(shape->realForm), &pixels);
            break;
        case cmdRectangle:
            pixel_rectangle((Rectangle *)(shape->realForm), &pixels);
            break;
        case cmdSquare:
            pixel_square((Square *)(shape->realForm), &pixels);
            break;
        default:
            break;
    }
    return pixels;
}

CellOfPixels *createCellOfPixels(Pixel *pixel) {
    CellOfPixels *cell = (CellOfPixels *) malloc(sizeof(CellOfPixels));
    cell->pixel = pixel;
    cell->next = NULL;
    return cell;
}

void addCellOfPixelInArray(CellOfPixels **Array, Pixel *pixel) {
    if (*Array == NULL) {
        *Array = createCellOfPixels(pixel);
    } else {
        CellOfPixels *newCell = createCellOfPixels(pixel);
        newCell->next = *Array;
        *Array = newCell;
    }
}

void delete_pixel_shape(CellOfPixels *pixels){
    if(pixels != NULL){
        delete_pixel_shape(pixels->next);
        delete_pixel(pixels->pixel);
        free(pixels);
        pixels = NULL;
    }
}

int lenOfLLCPixels(CellOfPixels* pixels){
    if(pixels != NULL){
        return 1 + lenOfLLCPixels(pixels->next);
    }else{
        return 0;
    }
}

void addLLCOfPixelsInMatrixOfInts(CellOfPixels* pixels, int** matrix){
    CellOfPixels *temp = pixels;
    for (int i = 0; temp != NULL; i++) {
        Pixel *p = temp->pixel;
        matrix[p->y][p->x]++;
        temp = temp->next;
    }
    delete_pixel_shape(pixels);
}

void removeLLCOfPixelsInMatrixOfInts(CellOfPixels* pixels, int** matrix){
    CellOfPixels *temp = pixels;
    for (int i = 0; temp != NULL; i++) {
        Pixel *p = temp->pixel;
        matrix[p->y][p->x]--;
        temp = temp->next;
    }
    delete_pixel_shape(pixels);
}