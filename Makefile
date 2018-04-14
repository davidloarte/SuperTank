

all: SuperTank

SuperTank: supertank.o
	gcc supertank.o  $(ncursesw5-config --libs) -o supertank


supertank.o: supertank.cpp
	gcc supertank.cpp $(ncursesw5-config --cflags) -c

clean:
	$(RM) supertank.o supertank

