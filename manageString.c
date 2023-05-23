//
// Created by Le Gall on 24/03/2023.
//

#include "manageString.h"

unsigned int countStringArrayElements(const char *array, const char *delimiter) {
    // Compte le nombre d'éléments dans un tableau de chaînes de caractères en utilisant un délimiteur
    unsigned int count = 1;
    size_t delimiterLength = strlen(delimiter);
    char const *temporary = array;
    while (*temporary != '\0') {
        if (strncmp(temporary, delimiter, delimiterLength) == 0) {
            count++;
            temporary += delimiterLength;
        } else {
            temporary++;
        }
    }
    return count;
}

void copySubString(char *destination, const char *source, size_t length) {
    // Copie une sous-chaîne de caractères dans une autre chaîne de caractères
    for (int i = 0; i < length; i++) {
        destination[i] = source[i];
    }
    destination[length] = '\0';
}

StringArray splitStringToArray(const char *stringToSplit, const char *delimiter) {
    // Divise une chaîne de caractères en un tableau de chaînes de caractères en utilisant un délimiteur
    StringArray result;
    size_t delimiterLength = strlen(delimiter);

    result.size = countStringArrayElements(stringToSplit, delimiter);
    result.array = (char **) malloc(sizeof(char *) * result.size);
    if (result.array == NULL) {
        result.size = 0;
    } else {
        unsigned int lineIndex = 0;
        const char *temporary = stringToSplit;
        const char *temporaryStart = stringToSplit;
        while ((*temporary != '\0') && (lineIndex < result.size)) {
            if (strncmp(temporary, delimiter, delimiterLength) == 0) {
                size_t subStringLength = temporary - temporaryStart;
                result.array[lineIndex] = (char *) malloc(sizeof(char) * (subStringLength + 1));
                copySubString(result.array[lineIndex], temporaryStart, subStringLength);
                lineIndex++;
                temporary += delimiterLength;
                temporaryStart = temporary;
            } else {
                temporary++;
            }
        }
        if (lineIndex < result.size) {
            size_t subStringLength = temporary - temporaryStart;
            result.array[lineIndex] = (char *) malloc(sizeof(char) * (subStringLength + 1));
            copySubString(result.array[lineIndex], temporaryStart, subStringLength);
        }
    }

    return result;
}

int isDigit(char* string){
    // Vérifie si une chaîne de caractères ne contient que des chiffres
    int digit = TRUE;
    if(((string[0] < '0') || (string[0] > '9')) && (string[0] != '-')){
        digit = FALSE;
    }
    for(int i = 1; i < strlen(string); i++){
        if((string[i] < '0') || (string[i] > '9')){
            digit = FALSE;
        }
    }
    return digit;
}

int convertStringToDigit(char* string) {
    // Convertit une chaîne de caractères en entier
    if(isDigit(string)){
        return atoi(string);
    }
    return 0;
}
