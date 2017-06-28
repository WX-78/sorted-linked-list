all: list main
	g++ -o main.out list.o main.o
	rm *.o
list: list.h
	g++ -c list.cpp
main:	list.h
	g++ -c main.cpp
run:
	./main.out
