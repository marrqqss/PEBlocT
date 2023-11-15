all: C C++ Padre
C: C.c 
	gcc -o C.x C.c 
C++: C++.cc 
	g++ C++.cc -o C++.x
Padre:
	gcc -o Padre.x Padre.c
clean:
	rm *.x
cleantxt:	
	rm *.txt