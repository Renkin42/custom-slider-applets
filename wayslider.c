#include <gtk-layer-shell.h>
#include <gtk/gtk.h>
#include <glib/gprintf.h>
#include <yaml.h>

static void
print_hello (GtkWidget      *widget,
             gpointer        data)
{
    g_print ("Hello World\n");
}

static gboolean
slider_released (GtkWidget *widget,
                 gpointer   data)
{
    gdouble value = gtk_range_get_value(GTK_RANGE (widget));
    g_printf("%.1f\n", value);
    return FALSE;
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *slider;
    GtkWidget *button;

    window = gtk_application_window_new (app);
    gtk_layer_init_for_window (GTK_WINDOW (window));
    gtk_layer_set_layer (GTK_WINDOW (window), GTK_LAYER_SHELL_LAYER_TOP);
    gtk_layer_set_anchor (GTK_WINDOW (window), 1, TRUE);
    gtk_layer_set_anchor (GTK_WINDOW (window), 2, TRUE);

    grid = gtk_grid_new();
    gtk_container_add (GTK_CONTAINER (window), grid);

    slider = gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, 0.0, 100.0, 5.0);
    g_signal_connect (slider, "button-release-event", G_CALLBACK (slider_released), NULL);
    gtk_grid_attach (GTK_GRID (grid), slider, 0, 0, 1, 1);

    button = gtk_button_new_with_label("Hello world");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 1, 1);

    gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("dev.renkin42.wayslider", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}

