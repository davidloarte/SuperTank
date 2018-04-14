CC = gcc
#LIBS   = $(ncursesw5-config --libs)
#CFLAGS = $(ncursesw5-config --cflags)


#all: SuperTankV2

#SuperTankV2: supertankv2.o
#	$(CC) supertankv2.o $$(ncursesw5-config --libs) -o supertankv2


#supertankv2.o: supertankv2.cpp
#	$(CC) supertankv2.cpp $$(ncursesw5-config --cflags) -c

#clean:
#	$(RM) supertankv2.o supertankv2



all: SuperTank

SuperTank: supertank.o
	$(CC) supertank.o $$(ncursesw5-config --libs) -o supertank


supertank.o: supertank.cpp
	$(CC) supertank.cpp $$(ncursesw5-config --cflags) -c

clean:
	$(RM) supertank.o supertank

