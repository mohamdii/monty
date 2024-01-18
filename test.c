#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main() {
    Stack stack;
    initialize(&stack);
    FILE *file;
    
    file = fopen("monty_script.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    processMontyScript(file, &stack);

    /* Close the file */
    fclose(file);

    return 0;
}

