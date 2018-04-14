CC = gcc
#LIBS   = $(ncursesw5-config --libs)
#CFLAGS = $(ncursesw5-config --cflags)


all: SuperTank

SuperTank: supertank.o
	$(CC) supertank.o $$(ncursesw5-config --libs) -o supertank


supertank.o: supertank.cpp
	$(CC) supertank.cpp $$(ncursesw5-config --cflags) -c

clean:
	$(RM) supertank.o supertank

