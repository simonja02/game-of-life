#ifndef MAPEXPORT_H
#define MAPEXPORT_H

#include "Cell.h"
#include "CellMap.h"

// FUNCTION PROTOTYPES
void exportMapToConsole(Cell [][MAP_SIZE_Y]);
int exportMapToFile(Cell [][MAP_SIZE_Y], char*);

#endif
