cake: linked.o
	gcc linked.o 

linked.o: linked.c linked.h
	gcc -c linked.c

run:
	./a.out