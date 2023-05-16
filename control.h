//
// Created by Le Gall on 27/03/2023.
//

#ifndef DESSIN4_CONTROL_H
#define DESSIN4_CONTROL_H
#include "manageCommand.h"
#include "Shape.h"
#include "CellOfForms.h"
#include "manageID.h"
#include "area.h"

void executeControl(StringArray command, Area *area, int* stats);
void delete(unsigned int id, Area* area);
void clear();
void quit(int* stats);
void list(CellOfForms *forms);
void help();


#endif //DESSIN4_CONTROL_H
