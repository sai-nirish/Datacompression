all : 
	gcc -c -o easyzlib.o easyzlib.c
	g++ -std=c++0x -o data Datacomp.cpp easyzlib.o

clean :
	rm easyzlib.o data
