#include "GolWindow.h"
#include <sys/time.h>

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
    GtkWidget* btnPause;
    GtkWidget* btnRun; 
    GtkWidget* hbxButtonBox;
    GtkWidget* windowLayout;
    gtk_init(argc, argv); 

    GameData gameData = *data;

    // Initialize the window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Game of Life");
    gtk_widget_set_size_request(window, 205, 205);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);

    // Add the Play / Pause control buttons
    hbxButtonBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    windowLayout = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gameData.window = windowLayout;

    btnRun = gtk_button_new_with_label("Run");
    btnPause = gtk_button_new_with_label("Pause");

    g_signal_connect(G_OBJECT(btnPause), "clicked", G_CALLBACK(pauseGame), data);
    g_signal_connect(G_OBJECT(btnRun), "clicked", G_CALLBACK(run), data);

    gtk_box_set_spacing(GTK_BOX(hbxButtonBox), 5);
    gtk_box_pack_start(GTK_BOX(hbxButtonBox), btnRun, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbxButtonBox), btnPause, FALSE, FALSE, 0);
    gtk_widget_set_halign(hbxButtonBox, GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(hbxButtonBox, 100, 15);

    mapCanvas = gtk_drawing_area_new(); 
    createMapCanvas(mapCanvas, (gpointer) data);
    //mapCanvas = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(gameData.window), mapCanvas);
    gtk_container_add(GTK_CONTAINER(gameData.window), hbxButtonBox);

    gtk_container_add(GTK_CONTAINER(window), gameData.window);
    // Add the timeout
    g_timeout_add(5, (GSourceFunc) runNextGeneration, (gpointer) data);
    g_timeout_add(50, (GSourceFunc) redraw, window);
 
    // Show the window
    gtk_widget_show_all(window);
    gtk_main();
}

void pauseGame(GtkWidget* widget, gpointer data) {
    GameData* gData = (GameData*) data;
    gData->isRunning = 0;
}

void run(GtkWidget* widget, gpointer data) {
    GameData* gData = (GameData*) data;
    gData->isRunning = 1;
}

gboolean runNextGeneration(gpointer data) {
    GameData* gData = (GameData*) data;

    if (gData->isRunning == 0)
        return 1;

    struct timeval now;
    gettimeofday(&now, NULL);

    double timediff = (double) (now.tv_sec - gData->lastGenerationTime.tv_sec) * 1000 + (now.tv_usec - gData->lastGenerationTime.tv_usec) / 1000;

    if (timediff >= gData->delay_ms) {
      //printf("%f\n", timediff);
      nextGeneration((GameData*) data);
      gData->lastGenerationTime = now;
    }
    return 1;
}
