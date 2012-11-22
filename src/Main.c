#include<stdio.h>
#include<time.h>
#include "Main.h"
#include "Cell.h"
#include "CellMap.h"
#include "MapExport.h"
#include "GameLogic.h"

int main( void ) {
    Cell map[MAP_SIZE_X][MAP_SIZE_Y];
    createMap(map);

    time_t delay = 1;

    // TEST CASES: Oscillator in top left
    bringToLife(map, 2, 2);
    bringToLife(map, 2, 3);
    bringToLife(map, 2, 4);

    // Beacon
    bringToLife(map, 2, 10);
    bringToLife(map, 3, 10);
    bringToLife(map, 2, 11);
    bringToLife(map, 5, 12);
    bringToLife(map, 4, 13);
    bringToLife(map, 5, 13);

    int i;
    int j;
    for (i = 0; i < MAP_SIZE_X; i++) {
        for (j = 0; j < MAP_SIZE_Y; j++) {
            nextGen( getCellPointer(map, i, j) ); 
        }
    }

    exportMapToConsole(map);
    sleep(delay); 

    while(1) {
        nextGeneration(map);
        exportMapToConsole(map);
        sleep(delay);
    }
}


