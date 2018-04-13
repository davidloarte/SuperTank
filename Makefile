

all: SuperTank

SuperTank: supertank.o
		gcc supertank.cpp  $(ncursesw5-config --cflags) -c


supertank.o: supertank.cpp
		gcc supertank.o  $(ncursesw5-config --libs) -o supertank

clean:
	$(RM) supertank.o supertank

