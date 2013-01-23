#include "GolWindow.h"

void destroy(GtkWidget *window, gpointer data) {
    gtk_main_quit();
}

void redraw(gpointer windowPtr) {
    GtkWidget* window = (GtkWidget*) windowPtr;
    gtk_widget_queue_draw(window);
}

void createWindow(int* argc, char** argv[], GameData* data) {
    GtkWidget* window;
    GtkWidget* mapCanvas;
    gtk_init(argc, argv); 

    GameData gameData = *data;

    // Initialize the window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gameData.window = window;
    gtk_window_set_title(GTK_WINDOW(gameData.window), "Game of Life");
    gtk_widget_set_size_request(gameData.window, 205, 205);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(G_OBJECT(gameData.window), "destroy", G_CALLBACK(destroy), NULL);

    mapCanvas = gtk_drawing_area_new(); 
    createMapCanvas(mapCanvas, (gpointer) data);
    //mapCanvas = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(gameData.window), mapCanvas);

    // Add the timeout
    g_timeout_add(500, (GSourceFunc) runNextGeneration, (gpointer) data);
    g_timeout_add(500, (GSourceFunc) redraw, window);
 
    // Show the window
    gtk_widget_show_all(gameData.window);
    gtk_main();
}

void runNextGeneration(gpointer data) {
    nextGeneration((GameData*) data);
}
