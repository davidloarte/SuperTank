

all: SuperTank

SuperTank: supertank.o
	g++ -o supertank supertank.o -lncursesw

supertank.o: supertank.cpp
	g++ -c supertank.cpp -o supertank.o

clean:
	$(RM) supertank.o supertank

