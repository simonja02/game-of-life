#include <gtk/gtk.h>
#include "GolMapCanvas.h"

void createWindow();
void pauseGame(GtkWidget*, gpointer);
void run(GtkWidget*, gpointer);
gboolean runNextGeneration(gpointer);
