#include "magenta_window.h"

GtkWindow * magenta_create_styled_window() {
    GtkWindow * window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    GtkHeaderBar * bar = magenta_create_title_bar(window);

    //gtk_window_set_titlebar(window, GTK_WIDGET(bar));

    return window;
}

GtkWindow * magenta_create_main_window() {
    GtkWindow * window = magenta_create_styled_window();
    gtk_window_set_title(window, "Magenta");

    WebKitWebView * view = WEBKIT_WEB_VIEW(webkit_web_view_new());
    webkit_web_view_load_uri(view, "http://newtoo.ru/magenta/ru");

    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(view));

    return window;
}