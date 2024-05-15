#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

enum parser_state {
    STATE_START,
    STATE_STREAM,
    STATE_DOCUMENT,
    STATE_SECTION,

    STATE_DEFAULTS,
    STATE_DEFVALUES,
    STATE_DEFKEY,
    STATE_DEFLOCATION,
    STATE_DEFX,
    STATE_DEFY,

    STATE_STOP
}

struct parser_data {
    enum parser_state state;
}

#endif
