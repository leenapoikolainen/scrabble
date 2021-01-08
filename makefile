scrabble: main.o scrabble.o
	g++ -Wall -g main.o scrabble.o -o scrabble

main.o: main.cpp scrabble.h
	g++ -Wall -g -c main.cpp

scrabble.o: scrabble.cpp scrabble.h
	g++ -Wall -g -c scrabble.cpp
