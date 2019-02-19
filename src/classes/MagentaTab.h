#ifndef MAGENTA_MAGENTATAB_H
#define MAGENTA_MAGENTATAB_H

#include "MagentaTabPane.h"
#include "engine/WebkitBrowserEngine.h"


class MagentaTab {
public:
    MagentaTab(GtkNotebook * tabPane, char * uri);
    void open();
    void close();

private:
    GtkNotebook * gtkTabPane;
    WebkitBrowserEngine browserEngine;
    char * pageUri;
};


#endif //MAGENTA_MAGENTATAB_H
