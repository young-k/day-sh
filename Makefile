all: main.c
	gcc main.c -o main.out

clean:
	rm *.out
	rm *~

run:
	./main.out
