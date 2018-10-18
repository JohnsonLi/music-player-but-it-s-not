cake: linked.o music.o
	gcc linked.o music.o

linked.o: linked.c linked.h
	gcc -c linked.c

music.o: music.c 
	gcc -c music.c

run:
	./a.out

clean:
	rm *.out
	rm *.o