#ifndef MAGENTA_MAGENTA_TABS_H
#define MAGENTA_MAGENTA_TABS_H

#define MAGENTA_TAB_PANE_LIMIT 100
#define MAGENTA_TABS_LIMIT 100

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

int magenta_tabs_build_tab_pane();
GtkNotebook * magenta_get_tab_pane_widget(int id);
int magenta_tab_open_uri(int tabpane_id, char * uri);

#endif //MAGENTA_MAGENTA_TABS_H
