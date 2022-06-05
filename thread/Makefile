cc=gcc

threaddemo:threaddemo.o
	$(cc) threaddemo.o -o threaddemo -lpthread
threaddemo.o:threaddemo.c
	$(cc) -c threaddemo.c -o threaddemo.o -lpthread
thread:thread.o
	$(cc) thread.o -o thread -lpthread
thread.o:thread.c
	$(cc) -c thread.c -o thread.o -lpthread
clean:
	rm -f thread.o threaddemo.o threaddemo 	