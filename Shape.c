//
// Created by Le Gall on 26/03/2023.
//

#include "Shape.h"

unsigned int getNewFormId(){
    static unsigned int id = 0;
    return ++id;
}

Shape *createForm(typeOfCommand type, void* RealForm){
    Shape* form = (Shape*) malloc(sizeof(Shape));
    form->id = getNewFormId();
    form->type = type;
    form->realForm = RealForm;
    return form;
}

void printForm(Shape* form){
    switch (form->type) {
        case cmdPoint:{
            print_point((Point*) (form->realForm));
            break;
        }case cmdLine:{
            print_line((Line*) (form->realForm));
            break;
        }case cmdCircle:{
            print_circle((Circle*) (form->realForm));
            break;
        }case cmdSquare:{
            print_square((Square*) (form->realForm));
            break;
        }case cmdRectangle:{
            print_rectangle((Rectangle*) (form->realForm));
            break;
        }case cmdPolygon: {
            print_polygon((Polygon*) (form->realForm));
            break;
        }
        default:
            break;
    }
    printf(" | ID = %d", form->id);
    printf("\n");
}

void* createFormPoint(StringArray command){
    return create_point(convertStringToDigit(command.array[1]), convertStringToDigit(command.array[2]));
}

void* createFormLine(StringArray command){
    Point *point1 = create_point(convertStringToDigit(command.array[1]), convertStringToDigit(command.array[2]));
    Point *point2 = create_point(convertStringToDigit(command.array[3]), convertStringToDigit(command.array[4]));
    return create_line(point1, point2);
}

void* createFormCircle(StringArray command){
    Point *radius = create_point(convertStringToDigit(command.array[1]), convertStringToDigit(command.array[2]));
    return create_circle(radius, convertStringToDigit(command.array[3]));
}

void* createFormRectangle(StringArray command){
    Point *point = create_point(convertStringToDigit(command.array[1]), convertStringToDigit(command.array[2]));
    return create_rectangle(point, convertStringToDigit(command.array[3]), convertStringToDigit(command.array[4]));
}

void* createFormSquare(StringArray command){
    Point *point = create_point(convertStringToDigit(command.array[1]), convertStringToDigit(command.array[2]));
    return create_square(point, convertStringToDigit(command.array[3]));
}

void* createFormPolygon(StringArray command){
    Polygon *polygon = create_polygon((command.size-1)/2);
    for (int i = 1; i < command.size; i+=2) {
        (polygon->points)[(i-1)/2] = create_point(convertStringToDigit(command.array[i]), convertStringToDigit(command.array[i+1]));
    }
    return polygon;
}

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

void deleteForm(Shape* form){
    if (form != NULL) {
        switch (form->type) {
            case cmdPoint:
                delete_point((Point *) (form->realForm));
                break;
            case cmdRectangle:
                delete_rectangle((Rectangle *) (form->realForm));
                break;
            case cmdCircle:
                delete_circle((Circle *) (form->realForm));
                break;
            case cmdSquare:
                delete_square((Square *) (form->realForm));
                break;
            case cmdLine:
                delete_line((Line *) (form->realForm));
                break;
            case cmdPolygon:
                delete_polygon((Polygon *) (form->realForm));
                break;
            default:
                break;
        }
    }
    free(form);
}

