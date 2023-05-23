//
// Created by Le Gall on 24/03/2023.
//

#ifndef LOGVECT_MANAGESTRING_H
#define LOGVECT_MANAGESTRING_H
#include <string.h>
#include "stdlib.h"
#include "stdio.h"
#include <math.h>
#define TRUE 1
#define FALSE 0

typedef struct {
    char **array;
    unsigned int size;
} StringArray;

unsigned int countStringArrayElements(const char *array, const char *delimiter);
StringArray splitStringToArray(const char *stringToSplit, const char *delimiter);
int isDigit(char* string);
int convertStringToDigit(char* string);


#endif //LOGVECT_MANAGESTRING_H
