//
// Created by Le Gall on 22/04/2023.
//

#include "Pixel.h"

Pixel *createPixel(int px, int py) {
    // Crée un nouveau pixel avec les coordonnées spécifiées
    Pixel *pixel = (Pixel *) malloc(sizeof(Pixel));
    pixel->x = px;
    pixel->y = py;
    return pixel;
}

void deletePixel(Pixel *pixel) {
    // Libère la mémoire allouée pour un pixel
    free(pixel);
}

void pixelPoint(Point *point, CellOfPixels **pixels) {
    // Convertit un point en pixel et l'ajoute à un tableau de pixels
    addCellOfPixelInArray(pixels, createPixel(point->x, point->y));
}

void pixelLine(Line *line, CellOfPixels **pixels){
    // Convertit une ligne en pixels et les ajoute à un tableau de pixels
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
        Pixel *p = createPixel(point1.x, point1.y);
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
    Pixel *p = createPixel(point2.x, point2.y);
    addCellOfPixelInArray(pixels, p);
}

void pixelCircle(Circle *circle, CellOfPixels **pixels) {
    // Convertit un cercle en pixels et les ajoute à un tableau de pixels
    Point center = *(circle->center);
    int radius = (circle->radius);
    int x = 0;
    int y = radius;
    int delta = radius - 1;
    while (y >= x) {
        addCellOfPixelInArray(pixels, createPixel(center.x + x, center.y + y));
        addCellOfPixelInArray(pixels, createPixel(center.x + y, center.y + x));
        addCellOfPixelInArray(pixels, createPixel(center.x - x, center.y + y));
        addCellOfPixelInArray(pixels, createPixel(center.x - y, center.y + x));
        addCellOfPixelInArray(pixels, createPixel(center.x + x, center.y - y));
        addCellOfPixelInArray(pixels, createPixel(center.x + y, center.y - x));
        addCellOfPixelInArray(pixels, createPixel(center.x - x, center.y - y));
        addCellOfPixelInArray(pixels, createPixel(center.x - y, center.y - x));
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


void pixelSquare(Square *square, CellOfPixels **pixels) {
    // Convertit un carré en pixels et les ajoute à un tableau de pixels
    for (int i = 0; i < square->length; ++i) {
        addCellOfPixelInArray(pixels, createPixel(square->point->x, (square->point->y) + i));
        addCellOfPixelInArray(pixels, createPixel((square->point->x) + (square->length) - 1, (square->point->y) + i));
        addCellOfPixelInArray(pixels, createPixel((square->point->x) + i, (square->point->y) + (square->length) - 1));
        addCellOfPixelInArray(pixels, createPixel((square->point->x) + i, square->point->y));
    }
}

void pixelRectangle(Rectangle *rectangle, CellOfPixels **pixels) {
    // Convertit un rectangle en pixels et les ajoute à un tableau de pixels
    for (int i = 0; i < rectangle->width; ++i) {
        addCellOfPixelInArray(pixels, createPixel(rectangle->point->x, (rectangle->point->y) + i));
        addCellOfPixelInArray(pixels,
                              createPixel((rectangle->point->x) + (rectangle->height) - 1, (rectangle->point->y) + i));
    }
    for (int i = 0; i < rectangle->height; ++i) {
        addCellOfPixelInArray(pixels,
                              createPixel((rectangle->point->x) + i, (rectangle->point->y) + (rectangle->width) - 1));
        addCellOfPixelInArray(pixels, createPixel((rectangle->point->x) + i, rectangle->point->y));
    }
}

void pixelPolygon(Polygon *polygon, CellOfPixels **pixels) {
    // Convertit un polygone en pixels et les ajoute à un tableau de pixels
    for (int i = 0; i < polygon->n; ++i) {
        if (i == (polygon->n) - 1) {
            Line *line = createLine(createPoint(polygon->points[i]->x, polygon->points[i]->y),
                                    createPoint(polygon->points[0]->x, polygon->points[0]->y));
            pixelLine(line, pixels);
            deleteLine(line);
        } else {
            Line *line = createLine(createPoint(polygon->points[i]->x, polygon->points[i]->y),
                                    createPoint(polygon->points[i + 1]->x, polygon->points[i + 1]->y));
            pixelLine(line, pixels);
            deleteLine(line);
        }
    }
}

// Convertit une forme en pixels en fonction de son type et renvoie une liste chaînée de pixels
CellOfPixels *createShapeToPixel(Shape* shape){
    CellOfPixels* pixels = NULL;

    // Sélectionne le type de forme et appelle la fonction correspondante pour convertir la forme en pixels
    switch (shape->type) {
        case cmdLine:
            pixelLine((Line *) (shape->realForm), &pixels);  // Convertit une ligne en pixels
            break;
        case cmdPoint:
            pixelPoint((Point *) (shape->realForm), &pixels);  // Convertit un point en pixels
            break;
        case cmdCircle:
            pixelCircle((Circle *) (shape->realForm), &pixels);  // Convertit un cercle en pixels
            break;
        case cmdPolygon:
            pixelPolygon((Polygon *) (shape->realForm), &pixels);  // Convertit un polygone en pixels
            break;
        case cmdRectangle:
            pixelRectangle((Rectangle *) (shape->realForm), &pixels);  // Convertit un rectangle en pixels
            break;
        case cmdSquare:
            pixelSquare((Square *) (shape->realForm), &pixels);  // Convertit un carré en pixels
            break;
        default:
            break;
    }

    return pixels;  // Retourne la liste chaînée de pixels
}


// Crée et retourne une nouvelle cellule de pixels à partir d'un pointeur vers un pixel
CellOfPixels *createCellOfPixels(Pixel *pixel) {
    CellOfPixels *cell = (CellOfPixels *) malloc(sizeof(CellOfPixels));
    cell->pixel = pixel;
    cell->next = NULL;
    return cell;
}

// Ajoute une cellule de pixels à un tableau de pixels
void addCellOfPixelInArray(CellOfPixels **Array, Pixel *pixel) {
    if (*Array == NULL) {
        // Si le tableau est vide, crée une nouvelle cellule et l'assigne au tableau
        *Array = createCellOfPixels(pixel);
    } else {
        // Si le tableau n'est pas vide, crée une nouvelle cellule et met à jour les pointeurs
        CellOfPixels *newCell = createCellOfPixels(pixel);
        newCell->next = *Array;
        *Array = newCell;
    }
}

// Supprime récursivement toutes les cellules de pixels dans une liste chaînée
void deletePixelShape(CellOfPixels *pixels){
    if(pixels != NULL){
        // Appelle la fonction récursivement pour supprimer les cellules restantes
        deletePixelShape(pixels->next);
        // Supprime le pixel contenu dans la cellule et libère la mémoire de la cellule
        deletePixel(pixels->pixel);
        free(pixels);
        pixels = NULL;
    }
}

// Calcule la longueur de la liste chaînée de pixels
int lenOfLLCPixels(CellOfPixels* pixels){
    if(pixels != NULL){
        // Appelle récursivement la fonction en ajoutant 1 à la longueur pour chaque cellule restante
        return 1 + lenOfLLCPixels(pixels->next);
    }else{
        return 0; // Retourne 0 lorsque la liste est vide
    }
}

// Ajoute les pixels d'une liste chaînée dans une matrice d'entiers
void addLLCOfPixelsInMatrixOfInts(CellOfPixels* pixels, int** matrix, unsigned int width, unsigned int height){
    CellOfPixels *temp = pixels;
    while (temp != NULL) {
        // Récupère les coordonnées du pixel et met à jour la valeur correspondante dans la matrice
        Pixel *p = temp->pixel;
        if((p->y < width) && (p->y >= 0) && (p->x < height) && (p->x >= 0)){
            matrix[p->y][p->x]++;
        }
        temp = temp->next;
    }
    // Supprime la liste chaînée après avoir mis à jour la matrice
    deletePixelShape(pixels);
}

// Supprime les pixels d'une liste chaînée d'une matrice d'entiers
void removeLLCOfPixelsInMatrixOfInts(CellOfPixels* pixels, int** matrix){
    CellOfPixels *temp = pixels;
    while (temp != NULL) {
        // Récupère les coordonnées du pixel et met à jour la valeur correspondante dans la matrice
        Pixel *p = temp->pixel;
        matrix[p->y][p->x]--;
        temp = temp->next;
    }
    // Supprime la liste chaînée après avoir mis à jour la matrice
    deletePixelShape(pixels);
}
