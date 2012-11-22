/* Map Export
 * Contains various functions to export the map in various formats
 * Does not include GUI functions which will belong to their own files.
 */

#include <stdio.h>
#include "MapExport.h"

void exportMapToConsole(Cell map[][MAP_SIZE_Y]) {
    int i;
    int j;

    printf("---------------------------------------\n");
    for (i = 0; i < MAP_SIZE_X; i++) {
        for (j = 0; j < MAP_SIZE_Y; j++) {
            if (map[i][j].alive) { printf("1 "); }
            else { printf("  "); }
            //printf("%d [%d] | ", map[i][j].alive, map[i][j].neighbours); 
        }
        printf("\n");
    }
    printf("---------------------------------------\n");
}

int exportMapToFile(Cell map[][MAP_SIZE_Y], char* filename) {
    FILE* output = fopen(filename, "w");

    if (output == 0) {
        printf("Error opening file to export map data\n");
        return -1;
    }

    // File Format Description
    // (only includes cells to initialize as Alive)
    // MAP_WIDTH MAP_HEIGHT
    // X1 Y1
    // X2 Y2
    // ... 

    int i;
    int j;

    fprintf(output, "%d %d\n", MAP_SIZE_X, MAP_SIZE_Y);

    for (i = 0; i < MAP_SIZE_X; i++) {
        for (j = 0; j < MAP_SIZE_Y; j++) { 
            if (map[i][j].alive == 1) {
                fprintf(output, "%d %d\n", i, j);
            }
        }
    }

    fclose(output);
    return 1;
}
