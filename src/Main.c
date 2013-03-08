#include "Main.h"

int main( int argc, char* argv[] ) {
    int mapFromFile = 0;
    char* filename;

    printf("%s\n", argv[1]);

    if (argc < 2) {
        printf("No map selected!\n");
        printf("Usage: ./gol -f filename or ./gol -r\n");
        return 0;
    }

    printf("%d\n", strcmp(argv[1], "-f"));
    int isRand = strcmp(argv[1], "-r");

    if (isRand != 0) {
      printf("wants to load from file");
      mapFromFile = 1;
      filename = argv[2];
    }

    GameData gameData;
    createMap(gameData.map);

    gameData.delay_ms = 250;
    gameData.isRunning = 1;
    gettimeofday(&gameData.lastGenerationTime, NULL);

/*
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

    // Toad
    bringToLife(map, 12, 2);
    bringToLife(map, 13, 2);
    bringToLife(map, 14, 2);
    bringToLife(map, 13, 3);
    bringToLife(map, 14, 3);
    bringToLife(map, 15, 3);

    // Boat
    bringToLife(map, 6, 2);
    bringToLife(map, 7, 2);
    bringToLife(map, 6, 3);
    bringToLife(map, 8, 3);
    bringToLife(map, 7, 4); 
*/

    printf("map assignment");
    if (mapFromFile) { importMapFromFile(gameData.map, filename); }
    else { createRandomMap(gameData.map); }

    int i;
    int j;
    for (i = 0; i < MAP_SIZE_X; i++) {
        for (j = 0; j < MAP_SIZE_Y; j++) {
            nextGen( getCellPointer(gameData.map, i, j) ); 
        }
    }
    //exportMapToFile(map, "testmap.map");
    printf("exporting\n");
    exportMapToConsole(gameData.map);
    printf("done exporting\n");
    //sleep(delay); 

    /*while(1) {
        nextGeneration(gameData.map);
        exportMapToConsole(gameData.map);
        sleep(delay);
    }*/
    createWindow(&argc, &argv, &gameData);
}


