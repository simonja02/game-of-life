#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include<stdio.h> // Debugging
#include "Cell.h"
#include "CellMap.h"

unsigned char doesNeighbourExist(Cell, int, int);
unsigned char checkForDeath(Cell);
unsigned char checkForBirth(Cell);
unsigned char checkForStatusQuo(Cell);

void nextGeneration(Cell [][MAP_SIZE_Y]); 

char bringToLife(Cell [][MAP_SIZE_Y], unsigned int, unsigned int);
char killCell(Cell [][MAP_SIZE_Y], unsigned int, unsigned int);
#endif
