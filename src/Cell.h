#ifndef CELL_H
#define CELL_H

typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned char alive;
    unsigned char nextGenAlive;
    unsigned char neighbours;
    unsigned char nextGenNeighbours;
} Cell;

// FUNCTION PROTOTYPES
Cell newBlankCell(unsigned int x, unsigned int y);
void nextGen( Cell* );
void setAlive ( Cell* );
unsigned char isAlive(Cell*);
void setDead ( Cell* );
void addNeighbour ( Cell* );
void removeNeighbour ( Cell* );

#endif
