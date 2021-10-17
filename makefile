all: work10.o
	gcc -o program work10.o
main.o: work10.c
	gcc -c work10.c
run:
	./program
clean:
	rm *.o