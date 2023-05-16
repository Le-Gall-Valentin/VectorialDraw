//
// Created by Le Gall on 21/04/2023.
//

#include "manageID.h"

Shape *getFormById(unsigned int id, CellOfForms* array){
    CellOfForms *temporaryArray = array;
    while (temporaryArray != NULL){
        if(temporaryArray->value->id == id){
            return  temporaryArray->value;
        }
        temporaryArray = temporaryArray->next;
    }
    return NULL;
}

CellOfForms *getShapeById(unsigned int id, CellOfForms* array){
    CellOfForms *temporaryArray = array;
    while (temporaryArray != NULL){
        if(temporaryArray->value->id == id){
            return  temporaryArray;
        }
        temporaryArray = temporaryArray->next;
    }
    return NULL;
}
