cleanrun: clean makerun

run:
	./cat1

make run: make run

make: compile
	gcc cat1.o -o cat1

compile: cat1.cpp
	gcc -c cat1.cpp

clean:
	rm -rf *o cat1
