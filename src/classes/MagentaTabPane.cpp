#include "MagentaTabPane.h"
#include "engine/WebkitBrowserEngine.h"

MagentaTabPane::MagentaTabPane(GtkWindow * window) {
    gtkWindow = window;
    gtkNotebook = GTK_NOTEBOOK(gtk_notebook_new());
    GtkButton * addButton = GTK_BUTTON(gtk_button_new_from_icon_name("add", GTK_ICON_SIZE_MENU));
    gtk_widget_set_name(GTK_WIDGET(addButton), "tab-add-button");

    g_signal_connect(G_OBJECT(addButton), "clicked", G_CALLBACK(+[](GtkButton * widget, gpointer user_data) {

    }), NULL);

    gtk_notebook_append_page(gtkNotebook, GTK_WIDGET(gtk_button_new()), GTK_WIDGET(addButton));
}

GtkNotebook * MagentaTabPane::gtkNotebookWidget() {
    return gtkNotebook;
}