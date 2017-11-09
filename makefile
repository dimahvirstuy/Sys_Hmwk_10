all: sig.c
	gcc -o sig sig.c

run: sig
	./sig
