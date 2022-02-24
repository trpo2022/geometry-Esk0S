all: geom1
geom1: geom1.c
	gcc -Wall -Werror -o geom1 geom1.c -lm
clean:
	rm geom1
run:
	./geom1