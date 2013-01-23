#include "Cell.h"
#include "GameData.h"
#include <gtk/gtk.h>

void createMapCanvas(GtkWidget*, gpointer);
gboolean draw_callback(GtkWidget*, cairo_t*, gpointer);
