#include "Cell.h"

Cell newBlankCell(unsigned int x, unsigned int y) {
    Cell c = { x, y, 0, 0, 0, 0 };
    return c;
}

void nextGen( Cell *c ) {
    (*c).alive = (*c).nextGenAlive;
    (*c).neighbours = (*c).nextGenNeighbours;
}

void setAlive ( Cell *c ) {
    (*c).nextGenAlive = 1;
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
    
