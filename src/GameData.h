#ifndef GAME_DATA_H
#define GAME_DATA_H
#include "Cell.h"
#include "CellMap.h"
#include <gtk/gtk.h>
typedef struct {
    unsigned int xSize;
    unsigned int ySize;
    Cell map[MAP_SIZE_X][MAP_SIZE_Y];
    GtkWidget* window;
} GameData;
#endif
