#ifndef FRAME_H
#define FRAME_H
#include <stdio.h>

typedef struct{
    int frame_n;
    int frame_height;
    int frame_width;
    char ** frame_matrix;
}frame;

typedef struct{
    int frame_count;
    frame ** frame_array;
}frame_set;

frame_set * read_frame_file(char * file_name);
int read_int(FILE * file);
frame * read_frame(FILE * file, int frame_height, int frame_width);
void print_frame_old(frame * f);
void free_frame_set(frame_set ** f_set);
void free_frame(frame ** f);

#endif /* FRAME_H */
