#ifndef WIDGET_BUILDER_H
#define WIDGET_BUILDER_H

enum widget_type {
    WIDGET_TYPE_BUTTON,
    WIDGET_TYPE_SLIDER
};

struct button_data {
    gchar *label;
    gchar *cmd;
};

struct slider_data {
    gchar *label;
    gchar *get_cmd;
    gchar *set_cmd;
    gdouble *get_cmd_min;
    gdouble *get_cmd_max;
    gdouble *set_cmd_min;
    gdouble *set_cmd_max;
};

#endif
