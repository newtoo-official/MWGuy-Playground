#ifndef MAGENTA_MAIN_H
#define MAGENTA_MAIN_H

#include <stdio.h>
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

#include "magenta_window.h"

int main(int argc, char ** argv);
int gtk_magenta_main(int argc, char ** argv);
void load_gtk();

#endif //MAGENTA_MAIN_H