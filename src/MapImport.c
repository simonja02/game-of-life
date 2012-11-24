/* Allow for maps to be imported into the program
 */

#include <stdio.h>
#include "CellMap.h"
#include "Cell.h"
#include "GameLogic.h"
#include "Main.h"

int importMapFromFile(Cell map[][MAP_SIZE_Y], char* filename) {
    FILE* input = fopen(filename, "r");

    createMap(map); 

    if (input == 0) {
        printf("Failed to open input file.\n");
        printf("Starting program with blank map.\n");
        return -1;
    }

    // Load the file format
    // MAP_WIDTH MAP_HEIGHT
    // Xn Yn

    int width, height; // ignored for now
    fscanf(input, "%d %d\n", &width, &height);
   
    int x, y; 
    while (fscanf(input, "%d %d\n", &x, &y) != EOF) {
        // Ensure cell isn't already alive
        Cell* c = getCellPointer(map, x, y);
        if (!(*c).nextGenAlive) {
            changeAliveStatus(map, ALIVE, x, y);
        }
    } 
    fclose(input);
    return 0;
}
