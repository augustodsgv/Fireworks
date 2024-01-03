#include <stdio.h>
#include <stdlib.h>
#include "frame.h"
#include "fireworks.h"
#include <ncurses.h>

int main(int argc, const char * argv[]){
    frame_set * f_set;
    initscr();
    curs_set(0);
    if(argc > 1){
        f_set = read_frame_file("frames.txt");
        print_frame(f_set->frame_array[strtol(argv[1], NULL, 10)]);
        getch();
    }else{
        f_set = read_frame_file("frames.txt");
        print_frame_set(f_set, 200);
    }

    
    // print_frame_old(f_set->frame_array[0]);
    free_frame_set(&f_set);

    endwin();
}