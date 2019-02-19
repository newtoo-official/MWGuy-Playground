#include "magenta_window.h"
#include "classes/MagentaTabPane.h"
#include "classes/MagentaTab.h"
#include "classes/engine/WebkitBrowserEngine.h"

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
    gtk_window_set_default_size(window, 1100, 600);

    MagentaTabPane magentaTabPane(window);
    GtkNotebook * tabPane = magentaTabPane.gtkNotebookWidget();
    MagentaTab mainTab(tabPane, const_cast<char *>("http://newtoo.ru/magenta/ru/"));
    mainTab.open();

    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(tabPane));

    return window;
}