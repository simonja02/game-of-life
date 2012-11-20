#include "Cell.h"

void setAlive ( Cell c ) {
    c.alive = 1;
}

void setDead ( Cell c ) {
    c.alive = 0;
}

void addNeighbour ( Cell c ) {
    c.neighbours++;
}

void removeNeighbour ( Cell c ) {
    if (c.neighbours >= 1) {
        c.neighbours--;
    } else {
        c.neighbours = 0;
    }
}
    
