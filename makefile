program: main.o

main.o: Point.o Vector.o main.cpp
	g++ Point.o Vector.o main.cpp -o main.o

objects: Point.cpp Vector.cpp
	g++ -c Point.cpp Vector.cpp

clear:
	rm *.o
