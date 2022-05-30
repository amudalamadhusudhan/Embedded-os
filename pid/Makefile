 cc=gcc

piddemo: piddemo.o
	$(cc) piddemo.o -o piddemo
piddemo.o: piddemo.c
	$(cc) -c piddemo.c -o piddemo.o
clean:
	rm -f piddemo.o piddemo
