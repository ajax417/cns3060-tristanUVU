cleanrun: clean makerun

run:
	./main

make run: make run

make: compile
	g++ main.o -o main

compile: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *o main
