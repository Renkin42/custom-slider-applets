CC=gcc
DEPS=gtk+-3.0 gtk-layer-shell-0 yaml-0.1
CFLAGS=$(shell pkg-config --cflags $(DEPS))
LDFLAGS=$(shell pkg-config --libs $(DEPS))

bin/wayslider: wayslider.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
