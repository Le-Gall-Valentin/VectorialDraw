//
// Created by Le Gall on 26/03/2023.
//

#include "manageCommand.h"

typeOfCommand returnTypeOfCommand(char* command){
    if(strcmp(command, "clear") == 0){
        return cmdClear;
    }else if(strcmp(command, "exit") == 0){
        return cmdQuit;
    }else if(strcmp(command, "point") == 0){
        return cmdPoint;
    }else if(strcmp(command, "line") == 0){
        return cmdLine;
    }else if(strcmp(command, "circle") == 0){
        return cmdCircle;
    }else if(strcmp(command, "square") == 0){
        return cmdSquare;
    }else if(strcmp(command, "rectangle") == 0){
        return cmdRectangle;
    }else if(strcmp(command, "polygon") == 0){
        return cmdPolygon;
    }else if(strcmp(command, "plot") == 0){
        return cmdPlot;
    }else if(strcmp(command, "list") == 0){
        return cmdList;
    }else if(strcmp(command, "delete") == 0){
        return cmdDelete;
    }else if(strcmp(command, "erase") == 0){
        return cmdErase;
    }else if(strcmp(command, "help") == 0){
        return cmdHelp;
    }else{
        return badCommand;
    }
}

int checkArguments(StringArray command){
    switch (returnTypeOfCommand(command.array[0])) {
        case cmdDelete:{
            if(command.size != 2){
                return FALSE;
            }return TRUE;
        }
        case cmdPoint:{
            if(command.size != 3){
                return FALSE;
            }return TRUE;
        }
        case cmdCircle:
        case cmdSquare:{
            if(command.size != 4){
                return FALSE;
            }return TRUE;
        }
        case cmdRectangle:
        case cmdLine:{
            if(command.size != 5){
                return FALSE;
            }return TRUE;
        }
        case cmdPolygon:{
            if((command.size-1)%2 != 0){
                return FALSE;
            }return TRUE;
        }
        default:
            if(command.size > 1){
                return FALSE;
            }return TRUE;
    }
}

int checkCommand(StringArray command){
    if(returnTypeOfCommand(command.array[0]) == badCommand){
        return FALSE;
    }
    for(int i =1; i <= command.size-1; i++){
        if(isDigit(command.array[i]) == FALSE){
            return FALSE;
        }
    }return checkArguments(command);
}

int returnFormOrControl(StringArray command) {
    switch (returnTypeOfCommand(command.array[0])) {
        case cmdPolygon:
        case cmdLine:
        case cmdSquare:
        case cmdCircle:
        case cmdRectangle:
        case cmdPoint:
            return FORM;
        default:
            return CONTROL;
    }
}