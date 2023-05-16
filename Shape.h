//
// Created by Le Gall on 26/03/2023.
//

#ifndef DESSIN2_FORM_H
#define DESSIN2_FORM_H
#include "point.h"
#include "square.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include "polygon.h"
#include "manageString.h"
#include "manageCommand.h"

typedef struct Shape {
    unsigned int id;
    typeOfCommand type;
    void* realForm;
}Shape;

unsigned int getNewFormId();
Shape *createForm(typeOfCommand type, void* realForm);
void* createFormWithHerStruct(StringArray command);
void printForm(Shape* form);
void* createFormPoint(StringArray command);
void* createFormLine(StringArray command);
void* createFormCircle(StringArray command);
void* createFormRectangle(StringArray command);
void* createFormSquare(StringArray command);
void* createFormPolygon(StringArray command);
void deleteForm(Shape* form);



#endif //DESSIN2_FORM_H
