 cc=gcc


libarith.a: add.o sub.o
	ar cvr libarith.a add.o sub.o

arithout: main.o add.o sub.o
	$(cc) add.o main.o sub.o -o arithout
main.o: main.c
	$(cc) -c main.c -o main.o
add.o: add.c
	$(cc) -c add.c -o add.o
sub.o: sub.c
	$(cc) -c sub.c -o sub.o	
clean:
	rm -f add.o main.o sub.o libarith.a arithout
