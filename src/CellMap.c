#include "CellMap.h"

Cell* getCellPointer(Cell map[][MAP_SIZE_Y], unsigned int x, unsigned int y) {
    return &map[x][y]; 
}

void createMap(Cell map[][MAP_SIZE_Y]) {
    int i;
    int j;
     
    for (i=0; i<MAP_SIZE_X; i++) {
        for (j=0; j<MAP_SIZE_Y; j++) {
            map[i][j] = newBlankCell(i, j);
        }
    }
}

void createRandomMap(Cell map[][MAP_SIZE_Y]) {
    int i, j;

    printf("creating random map\n");

    for(i=0; i<MAP_SIZE_X;i++) {
        for(j=0; j<MAP_SIZE_Y;j++) {
            // randomly assign cells to be alive
            if (i == 19 && j < 18) changeAliveStatus(map, 1, i, j);
        }
    }
}

void resetMap(Cell map[][MAP_SIZE_Y]) {
    // Just create a new one, the map will be overwritten
    createMap(map);
}
