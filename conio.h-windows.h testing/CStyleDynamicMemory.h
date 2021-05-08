#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Allocating_main() {

    char name[100];
    char* description;


    strcpy_s(name, "Zara Ali");

    /* allocate memory dynamically */
    description = (char*)malloc(200 * sizeof(char));

    if (description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else {
        description = _strdup("Zara ali a DPS student in class 10th.");
        //strcpy_s(description, "Zara ali a DPS student in class 10th");
    }

    printf("Name = %s\n", name);
    printf("Description: %s\n", description);
    return 0;
}

int ResizingReleasing_main() {

    char name[100];
    char* description;

    strcpy_s(name, "Zara Ali");

    /* allocate memory dynamically */
    description = (char*)malloc(30 * sizeof(char));

    if (description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else {
        description = _strdup("Zara ali a DPS student.");
        //strcpy_s(description, "Zara ali a DPS student.");
    }

    /* suppose you want to store bigger description */
    description = (char*)realloc(description, 100 * sizeof(char));

    if (description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else {
        //strncat_s(description, "She is in class 10th", 21);
    }

    printf("Name = %s\n", name);
    printf("Description: %s\n", description);

    /* release memory using free() function */
    free(description);
    return 0;
}