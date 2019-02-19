#include "MagentaTab.h"

void MagentaTab::open() {
    gtk_notebook_insert_page(
            gtkTabPane,
            browserEngine.gtkWidget(),
            GTK_WIDGET(gtk_label_new_with_mnemonic(pageUri)), 0);

    browserEngine.loadUri(pageUri);
}

void MagentaTab::close() {

}

MagentaTab::MagentaTab(GtkNotebook * tabPane, char * uri) {
    gtkTabPane    = tabPane;
    browserEngine = WebkitBrowserEngine();
    pageUri       = uri;
}
