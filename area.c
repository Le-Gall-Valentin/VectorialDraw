//
// Created by Le Gall on 22/04/2023.
//

#include "area.h"

int **create_matrix(unsigned int width, unsigned int height) {
    int **matrix = (int **) malloc(width * sizeof(int *));
    for (int i = 0; i < width; ++i) {
        matrix[i] = (int *) malloc(height * sizeof(int));
        for (int j = 0; j < height; ++j) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

Area *create_area(unsigned int width, unsigned int height) {
    Area *area = (Area *) malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->matrix = create_matrix(width, height);
    area->forms = NULL;
    area->nbForms = 0;
    return area;
}

void add_shape_to_area(Area **area, Shape *shape) {
    addCellOfFormsInArray(&((*(area))->forms), shape);
    addLLCOfPixelsInMatrixOfInts(create_shape_to_pixel(shape), (*area)->matrix);
    (*(area))->nbForms++;
}

void clear_area(Area *area) {
    for (int i = 0; i < area->width; ++i) {
        for (int j = 0; j < area->height; ++j) {
            area->matrix[i][j] = 0;
        }
    }
}


void deleteMatrixOfArea(Area *area) {
    for (int i = 0; i < area->width; ++i) {
        free(area->matrix[i]);
    }
    free(area->matrix);
}

void erase_area(Area *area) {
    clear_area(area);
    CellOfForms *temp = area->forms;
    for(int i = 0; i < area->nbForms; ++i) {
        deleteForm(temp->value);
        deleteCellOfForms(&(area->forms), temp);
        temp = area->forms;
    }
    area->nbForms = 0;
}

void delete_area(Area *area) {
    erase_area(area);
    deleteMatrixOfArea(area);
    free(area);
}

void draw_area(Area *area) {
    CellOfForms *temporaryCell = area->forms;
    while (temporaryCell != NULL) {
//        Pixel **pixelArray = create_shape_to_pixel(temporaryCell->value);
        temporaryCell = temporaryCell->next;
    }
}

void print_area(Area *area) {
    system("cls");
    for (int i = 0; i < area->height; i++) {
        for (int j = 0; j < area->width; j++) {
            if (area->matrix[i][j] == 0) {
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

void deleteFormInAreaMatrix(Area** area, CellOfForms* form){
    removeLLCOfPixelsInMatrixOfInts(create_shape_to_pixel(form->value), (*area)->matrix);
    (*(area))->nbForms--;
}


