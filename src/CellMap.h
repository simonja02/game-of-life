#ifndef CELLMAP_H
#define CELLMAP_H

#include "Cell.h"

#define MAP_SIZE_X 20
#define MAP_SIZE_Y 20

// CELL MAP VARIABLES
Cell map[MAP_SIZE_X][MAP_SIZE_Y];

// FUNCTION PROTOTYPES
void createMap();
void resetMap(); 

#endif
