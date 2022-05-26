arithout: main.o add.o
	gcc add.o main.o -o arithout
main.o: main.c
	gcc -c main.c -o main.o
add.o: add.c
	gcc -c add.c -o add.o
clean:
	rm -f add.o main.o arithout