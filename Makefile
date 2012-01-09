BIN=sd-gnome-term-prof-launcher



all: $(BIN)

CFLAGS=$(shell pkg-config --cflags --libs libpanelapplet-2.0)

clean:
	-rm $(BIN)

$(BIN): applet.c
	gcc $(CFLAGS) -o $(BIN) applet.c

install: $(BIN) SD_GnomeTermProfLauncher.server
	cp SD_GnomeTermProfLauncher.server /usr/lib/bonobo/servers
	cp $(BIN) /usr/lib/gnome-panel


