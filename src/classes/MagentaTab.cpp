#include "MagentaTab.h"

void MagentaTab::open() {
    int pos = gtk_notebook_insert_page(
            gtkTabPane,
            browserEngine.gtkWidget(),
            GTK_WIDGET(gtk_label_new_with_mnemonic(pageUri)),
            gtk_notebook_get_n_pages(gtkTabPane) - 1);
    gtk_widget_show(browserEngine.gtkWidget());
    gtk_notebook_set_current_page(gtkTabPane, pos);

    browserEngine.loadUri(pageUri);
}

void MagentaTab::close() {

}

MagentaTab::MagentaTab(GtkNotebook * tabPane, char * uri) {
    gtkTabPane    = tabPane;
    browserEngine = WebkitBrowserEngine();
    pageUri       = uri;
}
