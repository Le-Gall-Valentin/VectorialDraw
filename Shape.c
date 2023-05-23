//
// Created by Le Gall on 26/03/2023.
//

#include "Shape.h"

// Fonction interne pour obtenir un nouvel identifiant unique pour une forme
unsigned int getNewFormId(){
    static unsigned int id = 0;
    return ++id;
}

// Crée et initialise une instance de la structure Shape avec le type et le formulaire réel spécifiés
Shape *createForm(typeOfCommand type, void* RealForm){
    Shape* form = (Shape*) malloc(sizeof(Shape));
    form->id = getNewFormId();
    form->type = type;
    form->realForm = RealForm;
    return form;
}

// Affiche les informations d'une forme sur la console
void printForm(Shape* form){
    switch (form->type) {
        case cmdPoint:{
            printPoint((Point *) (form->realForm));
            break;
        }case cmdLine:{
            printLine((Line *) (form->realForm));
            break;
        }case cmdCircle:{
            printCircle((Circle *) (form->realForm));
            break;
        }case cmdSquare:{
            printSquare((Square *) (form->realForm));
            break;
        }case cmdRectangle:{
            printRectangle((Rectangle *) (form->realForm));
            break;
        }case cmdPolygon: {
            printPolygon((Polygon *) (form->realForm));
            break;
        }
        default:
            break;
    }
    printf(" | ID = %d", form->id);
    printf("\n");
}

// Crée un objet Point à partir d'une commande spécifiée
void* createFormPoint(StringArray command){
    return createPoint(convertStringToDigit(command.array[1]), convertStringToDigit(command.array[2]));
}

// Crée un objet Line à partir d'une commande spécifiée
void* createFormLine(StringArray command){
    Point *point1 = createPoint(convertStringToDigit(command.array[1]), convertStringToDigit(command.array[2]));
    Point *point2 = createPoint(convertStringToDigit(command.array[3]), convertStringToDigit(command.array[4]));
    return createLine(point1, point2);
}

// Crée un objet Circle à partir d'une commande spécifiée
void* createFormCircle(StringArray command){
    Point *radius = createPoint(convertStringToDigit(command.array[1]), convertStringToDigit(command.array[2]));
    return createCircle(radius, convertStringToDigit(command.array[3]));
}

// Crée un objet Rectangle à partir d'une commande spécifiée
void* createFormRectangle(StringArray command){
    Point *point = createPoint(convertStringToDigit(command.array[1]), convertStringToDigit(command.array[2]));
    return createRectangle(point, convertStringToDigit(command.array[3]), convertStringToDigit(command.array[4]));
}

// Crée un objet Square à partir d'une commande spécifiée
void* createFormSquare(StringArray command){
    Point *point = createPoint(convertStringToDigit(command.array[1]), convertStringToDigit(command.array[2]));
    return createSquare(point, convertStringToDigit(command.array[3]));
}

// Crée un objet Polygon à partir d'une commande spécifiée
void* createFormPolygon(StringArray command){
    Polygon *polygon = createPolygon((command.size - 1) / 2);
    for (int i = 1; i < command.size; i+=2) {
        (polygon->points)[(i-1)/2] = createPoint(convertStringToDigit(command.array[i]),
                                                 convertStringToDigit(command.array[i + 1]));
    }
    return polygon;
}

// Crée un objet Shape en fonction de la commande spécifiée
void* createFormWithHerStruct(StringArray command){
    switch (returnTypeOfCommand(command.array[0])) {
        case cmdPoint:{
            return createFormPoint(command);
        }
        case cmdRectangle:{
            return createFormRectangle(command);
        }
        case cmdCircle:{
            return createFormCircle(command);
        }
        case cmdSquare:{
            return createFormSquare(command);
        }
        case cmdLine:{
            return createFormLine(command);
        }
        case cmdPolygon:{
            return createFormPolygon(command);
        }
        default:
            return NULL;
    }
}

// Supprime un objet Shape et libère la mémoire associée
void deleteForm(Shape* form){
    if (form != NULL) {
        switch (form->type) {
            case cmdPoint:
                deletePoint((Point *) (form->realForm));
                break;
            case cmdRectangle:
                deleteRectangle((Rectangle *) (form->realForm));
                break;
            case cmdCircle:
                deleteCircle((Circle *) (form->realForm));
                break;
            case cmdSquare:
                deleteSquare((Square *) (form->realForm));
                break;
            case cmdLine:
                deleteLine((Line *) (form->realForm));
                break;
            case cmdPolygon:
                deletePolygon((Polygon *) (form->realForm));
                break;
            default:
                break;
        }
    }
    free(form);
}


