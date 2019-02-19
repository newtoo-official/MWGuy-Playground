#ifndef MAGENTA_MAGEANTATABPANE_H
#define MAGENTA_MAGEANTATABPANE_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

class MagentaTabPane {
public:
    MagentaTabPane(GtkWindow * window);
    GtkNotebook * gtkNotebookWidget();
    void test();

private:
    GtkWindow * gtkWindow;
    GtkNotebook * gtkNotebook;
};


#endif //MAGENTA_MAGEANTATABPANE_H
