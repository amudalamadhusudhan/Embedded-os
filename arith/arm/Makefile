 cc=aarch64-none-linux-gnu-gcc
 
arithout: main.o add.o
	$(cc) add.o main.o -o arithout
main.o: main.c
	$(cc) -c main.c -o main.o
add.o: add.c
	$(cc) -c add.c -o add.o
clean:
	rm -f add.o main.o arithout