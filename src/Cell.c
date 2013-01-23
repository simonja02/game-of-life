#include "Cell.h"

Cell newBlankCell(unsigned int x, unsigned int y) {
    Cell c = { x, y, 0, 0, 0, 0 };
    return c;
}

void nextGen( Cell *c ) {
    // Update the cell to use the next generation's data
    (*c).alive = (*c).nextGenAlive;
    (*c).neighbours = (*c).nextGenNeighbours;
}

void setAlive ( Cell *c ) {
    (*c).nextGenAlive = 1;
}

unsigned char isAlive(Cell* c) {
    return (*c).alive;
}

void setDead ( Cell *c ) {
    (*c).nextGenAlive = 0;
}

void addNeighbour ( Cell *c ) {
    (*c).nextGenNeighbours++;
}

void removeNeighbour ( Cell *c ) {
    if ((*c).neighbours >= 1) {
        (*c).nextGenNeighbours--;
    } else {
        (*c).nextGenNeighbours = 0;
    }
}
    
