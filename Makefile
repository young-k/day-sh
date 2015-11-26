all: main.c
	gcc parse.c main.c

clean:
	rm *~

run:
	./a.out
