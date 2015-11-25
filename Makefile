all: main.c
	gcc main.c parse.c -o day-sh

clean:
	rm *.out
	rm *~

run:
	./day-sh
