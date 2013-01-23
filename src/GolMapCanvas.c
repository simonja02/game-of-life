#include "GolMapCanvas.h"
#include <stdio.h>

void createMapCanvas(GtkWidget* map, gpointer gameData) {
    gtk_widget_set_size_request(map, 204, 204);
    g_signal_connect(G_OBJECT(map), "draw", G_CALLBACK(draw_callback), gameData);
}

gboolean draw_callback(GtkWidget* canvas, cairo_t* cr, gpointer data) {
    GameData gameData = *((GameData*) data);
    int i, j;
    for(i=0; i<MAP_SIZE_X; i++) {
        for(j=0; j<MAP_SIZE_Y; j++) {
            cairo_set_source_rgb(cr, 0, 0, 0);
            cairo_set_line_width(cr, 2);
            cairo_rectangle(cr, 2+j*10, 2+i*10, 10, 10);
            cairo_stroke_preserve(cr);

            Cell* c = getCellPointer(gameData.map, i, j);
            if (isAlive(c)) {
                cairo_set_source_rgb(cr, 0.10, 0.58, 1);
            } else {
                cairo_set_source_rgb(cr, 1, 1, 1);
            }
            cairo_fill(cr);
         }
    }

    return TRUE;
}

