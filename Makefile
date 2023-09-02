all:

compile:
	gcc test2.c `pkg-config --libs gtk4` `pkg-config --cflags gtk4` -std=c11

clean:
	rm a.out

#gcc test2.c $( pkg-config --libs gtk4 ) $( pkg-config --cflags gtk4 ) -std=c11
