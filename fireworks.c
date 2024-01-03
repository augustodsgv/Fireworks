#include <stdio.h>
#include <ncurses.h>
#include "fireworks.h"
#include "frame.h"

void print_frame_set(frame_set * f_set, int refresh_period){
    for(int i = 0; i < f_set->frame_count; i++){
        clear();
        print_frame(f_set->frame_array[i]);
        refresh();
        napms(refresh_period);
    }
}

void print_frame(frame * f){
    for(int i = 0; i < f->frame_height; i++){
        mvprintw(i, 0, f->frame_matrix[i]);
        /*
        for(int j = 0; j < f->frame_width; j++){
            if(f->frame_matrix[i][j] != ',')
                mvaddch(j, i, f->frame_matrix[i][j]);
            else
                mvaddch(j, i, ' ');
        }
        */    
    }
}

