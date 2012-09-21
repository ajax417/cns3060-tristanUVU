cleanrun: clean makerun

run:
	./cat1

make run: make run

make: compile
	gcc cat1.o -o cat1

compile: cat1.c
	gcc -c cat1.c

clean:
	rm -rf *o cat1
