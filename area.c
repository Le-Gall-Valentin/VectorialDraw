#include "area.h"

int **createMatrix(unsigned int width, unsigned int height) {
    // Alloue un tableau dynamique de pointeurs vers des entiers
    int **matrix = (int **) malloc(width * sizeof(int *));

    for (int i = 0; i < width; ++i) {
        // Alloue un tableau dynamique d'entiers pour chaque pointeur
        matrix[i] = (int *) malloc(height * sizeof(int));

        for (int j = 0; j < height; ++j) {
            // Initialise chaque élément de la matrice à 0
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

Area *createArea(unsigned int width, unsigned int height) {
    // Alloue un espace mémoire pour une structure Area
    Area *area = (Area *) malloc(sizeof(Area));

    area->width = width;
    area->height = height;

    // Crée une matrice et l'assigne à la structure Area
    area->matrix = createMatrix(width, height);

    area->forms = NULL;
    area->nbForms = 0;

    return area;
}

void addShapeToArea(Area **area, Shape *shape) {
    // Ajoute la forme à la liste des formes de l'aire
    addCellOfFormsInArray(&((*(area))->forms), shape);

    // Ajoute les pixels de la forme à la matrice d'entiers de l'aire
    addLLCOfPixelsInMatrixOfInts(createShapeToPixel(shape), (*area)->matrix, (*area)->width, (*area)->height);

    // Incrémente le nombre de formes dans l'aire
    (*(area))->nbForms++;
}

void clearArea(Area *area) {
    deleteAllCells(&(area->forms));
    // Réinitialise tous les éléments de la matrice à 0
    for (int i = 0; i < area->width; ++i) {
        for (int j = 0; j < area->height; ++j) {
            area->matrix[i][j] = 0;
        }
    }
}

void deleteMatrixOfArea(Area *area) {
    // Libère la mémoire allouée pour chaque ligne de la matrice
    for (int i = 0; i < area->width; ++i) {
        free(area->matrix[i]);
    }

    // Libère la mémoire allouée pour le tableau de pointeurs
    free(area->matrix);
}

void eraseArea(Area *area) {
    // Efface toutes les formes de l'aire et libère la mémoire associée
    clearArea(area);

    CellOfForms *temp = area->forms;
    for(int i = 0; i < area->nbForms; ++i) {
        deleteForm(temp->value);
        deleteCellOfForms(&(area->forms), temp);
        temp = area->forms;
    }

    area->nbForms = 0;
}

void deleteArea(Area *area) {
    // Supprime complètement l'aire, y compris toutes les formes et la matrice
    eraseArea(area);
    deleteMatrixOfArea(area);
    free(area);
}

void printArea(Area *area) {
    system("cls"); // Efface l'écran pour un affichage propre

    // Parcours de la matrice et affichage des éléments
    for (int i = 0; i < area->height; i++) {
        for (int j = 0; j < area->width; j++) {
            if (area->matrix[i][j] == 0) {
                printf(". "); // Affiche un point pour une case vide
            } else {
                printf("# "); // Affiche un hashtag pour une case occupée
            }
        }
        printf("\n"); // Passe à la ligne suivante pour chaque ligne de la matrice
    }
}

void deleteFormInAreaMatrix(Area** area, CellOfForms* form){
    // Supprime les pixels de la forme de la matrice de l'aire
    removeLLCOfPixelsInMatrixOfInts(createShapeToPixel(form->value), (*area)->matrix);

    // Décrémente le nombre de formes dans l'aire
    (*(area))->nbForms--;
}
