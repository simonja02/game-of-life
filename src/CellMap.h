#ifndef CELLMAP_H
#define CELLMAP_H

#include "Cell.h"

#define MAP_SIZE_X 20
#define MAP_SIZE_Y 20

// FUNCTION PROTOTYPES
Cell* getCellPointer(Cell [][MAP_SIZE_Y], unsigned int, unsigned int);
void createMap(Cell [][MAP_SIZE_Y]);
void resetMap(); 

#endif
