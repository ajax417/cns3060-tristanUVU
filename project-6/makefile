all: parta partb partc partd
parta: parta.c
	gcc -pthread -o parta parta.c
partb: partb.c
	gcc -pthread -o partb partb.c
partc: partc.c
	gcc -pthread -o partc partc.c
partd: partd.c
	gcc -pthread -o partd partd.c
clean:
	rm -rf *o parta partb partc partd
