/* Map Export
 * Contains various functions to export the map in various formats
 * Does not include GUI functions which will belong to their own files.
 */

#include <stdio.h>
#include "MapExport.h"

void exportMapToConsole(Cell map[][MAP_SIZE_Y]) {
    int i;
    int j;

    for (i = 0; i < MAP_SIZE_X; i++) {
        for (j = 0; j < MAP_SIZE_Y; j++) {
            printf("%d ", map[i][j].alive); 
        }
        printf("\n");
    }
}

void exportMapToFile(Cell map[][MAP_SIZE_Y], char* filename) {
    // To be implemented
}
