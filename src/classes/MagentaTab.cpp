#include "MagentaTab.h"

void MagentaTab::open() {
    GtkBox * box = GTK_BOX(gtk_box_new(GtkOrientation::GTK_ORIENTATION_HORIZONTAL, 3));
    GtkButton * closeButton = GTK_BUTTON(gtk_button_new_from_icon_name("window-close-symbolic", GtkIconSize::GTK_ICON_SIZE_MENU));
    GtkLabel * titleLabel = GTK_LABEL(gtk_label_new_with_mnemonic(pageUri));
    GtkImage * titleIcon = GTK_IMAGE(gtk_image_new());

    gtk_container_add(GTK_CONTAINER(box), GTK_WIDGET(titleIcon));
    gtk_container_add(GTK_CONTAINER(box), GTK_WIDGET(titleLabel));
    gtk_container_add(GTK_CONTAINER(box), GTK_WIDGET(closeButton));

    gtk_widget_set_name(GTK_WIDGET(closeButton), "tab-remove-button");

    g_signal_connect(G_OBJECT(closeButton), "clicked", G_CALLBACK(+[](GtkButton * button, gpointer data) {
        // You say "WTF!?!??!", i`m say "Getting GtkNotebook struct"
        GtkNotebook * notebook = GTK_NOTEBOOK(gtk_widget_get_parent(gtk_widget_get_parent(GTK_WIDGET(button))));

        gtk_widget_hide(GTK_WIDGET(data));
        gtk_notebook_remove_page(notebook, gtk_notebook_get_current_page(notebook) - 1);

        if (gtk_notebook_get_n_pages(notebook) <= 1) {
            (MagentaTab(GTK_NOTEBOOK(notebook), const_cast<char *>("http://google.com"))).open();
        }

        if (gtk_notebook_get_current_page(notebook) == gtk_notebook_get_n_pages(notebook) - 1) {
            gtk_notebook_set_current_page(notebook, gtk_notebook_get_n_pages(notebook) - 2);
        }

    }), browserEngine.gtkWidget());

    int pos = gtk_notebook_insert_page(
            gtkTabPane,
            GTK_WIDGET(browserEngine.gtkWidget()),
            GTK_WIDGET(box),
            gtk_notebook_get_n_pages(gtkTabPane) - 1);

    gtk_widget_show(browserEngine.gtkWidget());
    gtk_widget_show(GTK_WIDGET(closeButton));
    gtk_widget_show(GTK_WIDGET(titleLabel));
    gtk_widget_show(GTK_WIDGET(titleIcon));

    gtk_notebook_set_current_page(gtkTabPane, pos);

    browserEngine.loadUri(pageUri);
}

MagentaTab::MagentaTab(GtkNotebook * tabPane, char * uri) {
    gtkTabPane    = tabPane;
    browserEngine = WebkitBrowserEngine();
    pageUri       = uri;
}
