all: main.c
	gcc parse.c main.c -o day-sh

clean:
	rm *~
	rm day-sh

run:
	./day-sh
