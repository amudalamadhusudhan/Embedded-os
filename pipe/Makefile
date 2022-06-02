 cc=gcc

pipedemo:pipedemo.o
	$(cc) pipedemo.o -o pipedemo
pipedemo.o:pipedemo.c
	$(cc) -c pipedemo.c -o pipedemo.o	
clean:
	rm -f pipedemo.o pipedemo
