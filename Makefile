all: frame fireworks
	gcc main.c -lncurses fireworks.o frame.o -o main

fireworks: frame
	gcc fireworks.c -c -lncurses

frame:
	gcc frame.c -c

debug:
	gcc -g3 frame.c -o frame