

all: prog

prog: main.o Numerical_methods.o
	gcc -o prog main.o Numerical_methods.o

main.o: main.c Numerical_methods.h
	gcc  -c main.c -o main.o 

Numerical_methods.o: Numerical_methods.c Numerical_methods.h
	gcc  -c Numerical_methods.c -o Numerical_methods.o 

clean:
	del *.o
	del prog.exe
