/* Allow for maps to be imported into the program
 */

#include <stdio.h>
#include <string.h>
#include "CellMap.h"
#include "Cell.h"
#include "GameLogic.h"
#include "Main.h"

#define MAX_LINE_SIZE 100

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

    int width = -1, height = -1; // ignored for now
    char buffer[MAX_LINE_SIZE];

    int x, y; 
    while (fgets(buffer, sizeof(buffer), input) != NULL) {
        char* cp = strchr(buffer, '#');
        if (cp) { *cp = '\0'; }

        sscanf(buffer, "%d %d\n", &x, &y);

        if (width == -1 && height == -1) {
            width = x;
            height = y;
        } else {
          // Ensure cell isn't already alive
          Cell* c = getCellPointer(map, x, y);
          if (!(*c).nextGenAlive) {
              changeAliveStatus(map, ALIVE, x, y);
          }
        }
    } 
    fclose(input);
    return 0;
}
