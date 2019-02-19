#include "MagentaTabPane.h"

MagentaTabPane::MagentaTabPane(GtkWindow * window) {
    gtkWindow = window;
    gtkNotebook = GTK_NOTEBOOK(gtk_notebook_new());
    GtkButton * addButton = GTK_BUTTON(gtk_button_new_from_icon_name("add", GTK_ICON_SIZE_MENU));
    gtk_widget_set_name(GTK_WIDGET(addButton), "tab-add-button");

    g_signal_connect(G_OBJECT(addButton), "clicked", G_CALLBACK(+[](GtkButton * widget, gpointer user_data) {

    }), NULL);

    gtk_notebook_append_page(gtkNotebook, GTK_WIDGET(gtk_button_new()), GTK_WIDGET(addButton));

    // TODO: delete hardcore tab
    WebKitWebView * webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
    webkit_web_view_load_uri(webView, "http://newtoo.ru/magenta/ru/");
    gtk_notebook_insert_page(gtkNotebook, GTK_WIDGET(webView), GTK_WIDGET(gtk_label_new_with_mnemonic("TODO: delete hardcore tab")), 0);
}

GtkNotebook * MagentaTabPane::gtkNotebookWidget() {
    return gtkNotebook;
}

void MagentaTabPane::test() {
    g_print("Hello");
}