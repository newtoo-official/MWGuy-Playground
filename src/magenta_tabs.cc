#include "magenta_tabs.h"

static GtkNotebook * tabs[MAGENTA_TAB_PANE_LIMIT];
static WebKitWebView * pWebKitWebView[MAGENTA_TABS_LIMIT];
static int gtk_tabs[MAGENTA_TABS_LIMIT];

int magenta_tabs_build_tab_pane() {
    static int id = -1;
    id++;

    GtkNotebook * notebook = GTK_NOTEBOOK(gtk_notebook_new());
    tabs[id] = notebook;

    //gtk_notebook_append_page(notebook,
    //                         GTK_WIDGET(gtk_button_new_with_label("Ы")),
    //                         gtk_button_new_from_icon_name("add", GTK_ICON_SIZE_MENU));

    return id;
}

GtkNotebook * magenta_get_tab_pane_widget(int id) {
    return tabs[id];
}

WebKitWebView * magenta_get_webkit_widget(int id) {
    return pWebKitWebView[id];
}

int magenta_tab_open_uri(int tab_pane_id, char * uri) {
    static int tab_id = -1;
    tab_id++;

    pWebKitWebView[tab_id] = WEBKIT_WEB_VIEW(webkit_web_view_new());
    webkit_web_view_load_uri(magenta_get_webkit_widget(tab_id), uri);

    gtk_tabs[tab_id] = gtk_notebook_append_page(
            magenta_get_tab_pane_widget(tab_pane_id),
            GTK_WIDGET(magenta_get_webkit_widget(tab_id)),
            gtk_label_new_with_mnemonic(uri));

    return tab_id;
}