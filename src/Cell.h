#ifndef CELL_H
#define CELL_H

typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned char alive;
    unsigned char neighbours;
} Cell;

// FUNCTION PROTOTYPES
void setAlive ( Cell );
void setDead ( Cell );
void addNeighbour ( Cell );
void removeNeighbour ( Cell );

#endif
