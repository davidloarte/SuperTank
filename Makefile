

all: SuperTank

SuperTank: supertank.o
	g++ -o supertank supertank.cpp -lncurses

