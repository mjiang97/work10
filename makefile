all: main.o work10.o
	gcc -o program main.o work10.o
main.o: main.c work10.h
	gcc -c main.c
work10.o: work10.c work10.h
	gcc -c work10.c
run:
	./program 
clean:
	rm *.o