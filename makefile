program: main.o

main.o: primitivos/Point.o primitivos/Vector.o main.cpp
	g++ primitivos/Point.o primitivos/Vector.o main.cpp -o main.o

objects: primitivos/Point.cpp primitivos/Vector.cpp
	g++ -c primitivos/Point.cpp primitivos/Vector.cpp

clear:
	find . -name '*.o' -delete
