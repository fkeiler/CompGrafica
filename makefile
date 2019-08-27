program: main.o

main.o: primitivos/Point.o primitivos/Vector.o primitivos/Cone.o primitivos/Cylinder.o primitivos/Ray.o main.cpp
	g++ primitivos/Point.o primitivos/Vector.o primitivos/Cone.o primitivos/Cylinder.o primitivos/Ray.o main.cpp -o main.o

objects: primitivos/Point.cpp primitivos/Vector.cpp primitivos/Cone.cpp primitivos/Cylinder.cpp primitivos/Ray.cpp
	g++ -c primitivos/Point.cpp primitivos/Vector.cpp primitivos/Cone.cpp primitivos/Cylinder.cpp primitivos/Ray.cpp

clear:
	find . -name '*.o' -delete
