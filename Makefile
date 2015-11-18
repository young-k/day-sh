all: main.c
	gcc main.c -o day-sh

clean:
	rm *.out
	rm *~

run:
	./day-sh
