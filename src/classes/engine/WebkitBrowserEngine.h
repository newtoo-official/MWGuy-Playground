#ifndef MAGENTA_WEBKITBROWSERENGINE_H
#define MAGENTA_WEBKITBROWSERENGINE_H

#include <webkit2/webkit2.h>

class WebkitBrowserEngine {
public:
    WebkitBrowserEngine();
    GtkWidget * gtkWidget();
    void loadUri(char * uri);

private:
    WebKitWebView * webKitWebView;
};


#endif //MAGENTA_WEBKITBROWSERENGINE_H
