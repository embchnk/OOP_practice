all: Fraction

Fraction : Main.o Fraction.o FractionPointer.o
	g++ -Wall -g -o $@ $^

Main.o: Main.cpp
	g++ -Wall -g -c -o $@ $<

Fraction.o: Fraction.cpp Fraction.h
	g++ -Wall -g -c -o $@ $<

FractionPointer.o: FractionPointer.cpp FractionPointer.h
	g++ -Wall -g -c -o $@ $<

clean:
	rm -f *.o Fraction
.PHONY: clean all

