#include "magenta_window_title_bar.h"


GtkHeaderBar * magenta_create_title_bar(GtkWindow * window) {
    GtkHeaderBar * headerBar = GTK_HEADER_BAR(gtk_header_bar_new());
    GtkContainer * buttonContainer = GTK_CONTAINER(gtk_box_new(GtkOrientation::GTK_ORIENTATION_HORIZONTAL, 4));

    GtkButton * close = GTK_BUTTON(gtk_button_new_from_icon_name("window-close-symbolic", GTK_ICON_SIZE_MENU));
    GtkButton * resize = GTK_BUTTON(gtk_button_new_from_icon_name("window-maximize-symbolic", GTK_ICON_SIZE_MENU));
    GtkButton * hide = GTK_BUTTON(gtk_button_new_from_icon_name("window-minimize-symbolic", GTK_ICON_SIZE_MENU));

    g_signal_connect(G_OBJECT(close), "clicked", G_CALLBACK(+[](GtkWidget * widget, gpointer data) {
        gtk_window_close(GTK_WINDOW(data));
    }), window);

    g_signal_connect(G_OBJECT(resize), "clicked", G_CALLBACK(+[](GtkWidget * widget, gpointer data) {
        if (gtk_window_is_maximized(GTK_WINDOW(data)))
            gtk_window_unmaximize(GTK_WINDOW(data));
        else gtk_window_maximize(GTK_WINDOW(data));
    }), window);

    g_signal_connect(G_OBJECT(hide), "clicked", G_CALLBACK(+[](GtkWidget * widget, gpointer data) {
        gtk_window_iconify(GTK_WINDOW(data));
    }), window);

    gtk_container_add(buttonContainer, GTK_WIDGET(hide));
    gtk_container_add(buttonContainer, GTK_WIDGET(resize));
    gtk_container_add(buttonContainer, GTK_WIDGET(close));

    gtk_header_bar_pack_end(headerBar, GTK_WIDGET(buttonContainer));

    return headerBar;
}