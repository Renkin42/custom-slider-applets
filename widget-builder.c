#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

#include "widget-builder.h"

static void
button_cmd_callback (GtkWidget *widget,
                     gchar     *cmd)
{
    system(cmd);
}

static void
add_new_button (GtkBox             *parent,
                struct button_data *data)
{
    GtkWidget *button;
    gchar     *cmd;

    strcpy(cmd, data->cmd)

    button = gtk_button_new_with_label(data->label);
    g_signal_connect(button, "clicked", G_CALLBACK (button_cmd_callback), cmd);

    gtk_box_pack_end(parent, button, TRUE, TRUE, 0);
}
