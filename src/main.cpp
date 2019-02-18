#include "main.h"

int main(int argc, char ** argv) {
    return gtk_magenta_main(argc, argv);
}

int gtk_magenta_main(int argc, char ** argv) {
    GtkApplication * gtkApplication = GTK_APPLICATION(gtk_application_new("ru.magenta.browser", G_APPLICATION_FLAGS_NONE));
    g_signal_connect(G_OBJECT(gtkApplication), "activate", G_CALLBACK(load_gtk), NULL);

    int status = g_application_run (G_APPLICATION (gtkApplication), argc, argv);
    g_object_unref(gtkApplication);

    return status;
}

void load_gtk() {
    GtkWindow * mainWindow = magenta_create_main_window();

    g_signal_connect(G_OBJECT(mainWindow), "destroy", gtk_main_quit, NULL);
    gtk_widget_show_all(GTK_WIDGET(mainWindow));
    gtk_main();
}