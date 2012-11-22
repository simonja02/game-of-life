/* Allow for maps to be imported into the program
 */

#include <stdio.h>
#include "CellMap.h"
#include "Cell.h"
#include "GameLogic.h"

void importMapFromFile(Cell map[][MAP_SIZE_Y], char* filename) {
    // TODO: Add verification that file exists, read permission
    FILE* input = fopen(filename, "r");

    // Load the file format
    // MAP_WIDTH MAP_HEIGHT
    // Xn Yn

    int width, height; // ignored for now
    fscanf(input, "%d %d\n", &width, &height);
   
    createMap(map); 
    int x, y; 
    while (fscanf(input, "%d %d\n", &x, &y) != EOF) {
        bringToLife(map, x, y);
    } 
    fclose(input);
}
