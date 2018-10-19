cake: linked.o music.o main.o
	gcc main.o linked.o music.o

linked.o: linked.c linked.h
	gcc -c linked.c

music.o: music.c music.h
	gcc -c music.c 

main.o: main.c linked.h music.h
	gcc -c main.c 

run:
	./a.out

clean:
	rm *.out
	rm*.o