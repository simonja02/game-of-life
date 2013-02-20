#include "GameLogic.h"

unsigned char doesNeighbourExist (Cell* c, int dx, int dy) {
    if ((c->x + dx < 0) || (c->x + dx > MAP_SIZE_X)) {
        // X out of bounds
        printf("x out of bounds\n");
        return 0;
    } else if ((c->y + dy < 0) || (c->y + dy > MAP_SIZE_Y)) {
        // y out of bounds
        //printf("y out of bounds; %d + %d = %d\n", c.y, dy, c.y + dy);
        return 0;
    }
    return 1;
}

void nextGeneration(GameData* data) {
    int i;
    int j;

    for (i = 0; i < MAP_SIZE_X; i++) {
        for (j = 0; j < MAP_SIZE_Y; j++) {
            if (checkForDeath(getCellPointer(data->map, i, j))) { 
                changeAliveStatus(data->map, DEAD, i, j);
            } else if (checkForBirth(getCellPointer(data->map, i, j))) {
                changeAliveStatus(data->map, ALIVE, i, j);
            }    
        }
    }

    for (i = 0; i < MAP_SIZE_X; i++) {
        for (j = 0; j < MAP_SIZE_Y; j++) {
            nextGen( getCellPointer(data->map, i, j) );
        }
    }    
}

unsigned char checkForDeath(Cell* c) {
    // By the rules death occurs if neighbours < 2 or > 3
    if ((isAlive(c) == 1) && (getNeighbours(c) < 2 || getNeighbours(c) > 3)) {
        return 1;
    }
    return 0;
}

unsigned char checkForBirth(Cell* c) {
   // By the rules birth occurs if a dead cell has exactly 3 neighbours
   if (isAlive(c) == 0 && getNeighbours(c) == 3) {
       return 1;
    }
    return 0; 
}

unsigned char checkForStatusQuo(Cell* c) {
    if ((isAlive(c) == 1 && getNeighbours(c) == 2 || getNeighbours(c) == 3)) {
        return 1;
    }
    return 0;
}

char changeAliveStatus(Cell map[][MAP_SIZE_Y], unsigned int newStatus, unsigned int x, unsigned int y) {
    // TODO: Refactor and combine bringToLife(...) and killCell(...)
    // Set the cell's Alive status
    Cell* c = getCellPointer(map, x, y);

    if ((newStatus == ALIVE && isAlive(c) == 1) || (newStatus == DEAD && ! isAlive(c))) {
        // Trying to set cell to what it already is
        return 0;
    }

    if (newStatus == ALIVE) {
        setAlive(c);
    } else {
        setDead(c);
    }

    // 'Notify' the neighbouring cells
    int i;
    int j;
  
    for (i=-1; i<2; i++) {
        for (j=-1; j<2; j++) {
            if (doesNeighbourExist(c, i, j) && !(i == 0 && j == 0)) {
                Cell* n = getCellPointer(map, c->x + i, c->y + j);
                if (newStatus == ALIVE) {                    
                    addNeighbour(n);
                } else {
                    removeNeighbour(n);
                }
            } 
        }
    }
    return 1;
}
