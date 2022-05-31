 cc=aarch64-none-linux-gnu-gcc
 

arithout: main.o add.o sub.o mul.o div.o
	$(cc) add.o main.o sub.o mul.o div.o -o arithout
libarith.a: add.o sub.o mul.o div.o
	ar cvr -o libarith.a add.o sub.o mul.o div.o
main.o: main.c
	$(cc) -c main.c -o main.o
add.o: add.c
	$(cc) -c add.c -o add.o
sub.o: sub.c
	$(cc) -c sub.c -o sub.o	
mul.o: mul.c
	$(cc) -c mul.c -o mul.o
div.o: div.c
	$(cc) -c div.c -o div.o
clean:
	rm -f add.o main.o sub.o div.o mul.o libarith.a arithout
