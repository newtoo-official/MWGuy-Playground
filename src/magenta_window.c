#include "magenta_window.h"

GtkWindow * magenta_create_styled_window() {
    GtkWindow * window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    GtkHeaderBar * bar = magenta_create_title_bar(window);

    GdkScreen * screen = gdk_screen_get_default ();
    GtkCssProvider * provider = gtk_css_provider_new ();
    gtk_css_provider_load_from_path(provider, "res/style.css", NULL);
    gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_window_set_titlebar(window, GTK_WIDGET(bar));

    return window;
}

GtkWindow * magenta_create_main_window() {
    GtkWindow * window = magenta_create_styled_window();
    gtk_header_bar_set_custom_title(GTK_HEADER_BAR(gtk_window_get_titlebar(window)), gtk_label_new_with_mnemonic("Magenta"));
    gtk_window_set_position(window, GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(window, 850, 600);

    WebKitWebView * view = WEBKIT_WEB_VIEW(webkit_web_view_new());
    webkit_web_view_load_uri(view, "https://github.com/newtoo-official/Magenta");
    WebKitWebView * view2 = WEBKIT_WEB_VIEW(webkit_web_view_new());
    webkit_web_view_load_uri(view2, "http://newtoo.ru/magenta/ru/");


    GtkNotebook * notebook = GTK_NOTEBOOK(gtk_notebook_new());
    gtk_notebook_append_page(notebook, GTK_WIDGET(view), gtk_label_new_with_mnemonic("Test"));
    gtk_notebook_append_page(notebook, GTK_WIDGET(view2), gtk_label_new_with_mnemonic("Test"));

    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(notebook));

    return window;
}