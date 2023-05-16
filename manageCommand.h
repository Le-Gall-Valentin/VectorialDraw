//
// Created by Le Gall on 26/03/2023.
//

#ifndef DESSIN1_MANAGECOMMAND_H
#define DESSIN1_MANAGECOMMAND_H
#define FORM 1
#define CONTROL 0
#include <string.h>
#include "manageString.h"
#include "point.h"
#include "circle.h"
#include "line.h"
#include "polygon.h"
#include "rectangle.h"
#include "square.h"
#include "manageString.h"

typedef enum{
    cmdClear, cmdQuit, cmdPoint, cmdLine, cmdCircle, cmdSquare, cmdRectangle, cmdPolygon, cmdPlot, cmdList, cmdDelete, cmdErase, cmdHelp , badCommand
}typeOfCommand;



typeOfCommand returnTypeOfCommand(char* command);
int returnFormOrControl(StringArray command);
int checkCommand(StringArray command);
int checkArguments(StringArray command);
#endif //DESSIN1_MANAGECOMMAND_H
