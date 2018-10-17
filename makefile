cake: linked.o
	gcc linked.o 

linked.o: linked.c
	gcc -c linked.c

run:
	./a.out