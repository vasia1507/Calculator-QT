all:

main:
	gcc main.c -o main `pkg-config --libs gtk4` `pkg-config --cflags gtk4` -std=c11

clean:
	rm main

rebuild: clean main

#gcc test2.c $( pkg-config --libs gtk4 ) $( pkg-config --cflags gtk4 ) -std=c11

# gcc test2.c -lgtk-4 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -lgdk_pixbuf-2.0 -lcairo-gobject -lcairo -lgraphene-1.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 `pkg-config --cflags gtk4` -std=c11
