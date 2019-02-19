#include "WebkitBrowserEngine.h"

WebkitBrowserEngine::WebkitBrowserEngine() {
    webKitWebView = WEBKIT_WEB_VIEW(webkit_web_view_new());
}

GtkWidget * WebkitBrowserEngine::gtkWidget() {
    return GTK_WIDGET(this->webKitWebView);
}

void WebkitBrowserEngine::loadUri(char *uri) {
    webkit_web_view_load_uri(this->webKitWebView, uri);
}