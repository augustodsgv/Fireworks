#include <stdio.h>
#include <stdlib.h>
#include "frame.h"


frame_set * read_frame_file(char * file_name){
    FILE * frame_file = fopen(file_name, "r");
    int frame_count = read_int(frame_file);
    int frames_height = read_int(frame_file);
    int frames_lenght = read_int(frame_file);

    frame_set * f_set = malloc(sizeof(frame_set *));
    f_set->frame_array = malloc(sizeof(frame * ) * frame_count);
    f_set->frame_count = frame_count;
    for(int i = 0; i < frame_count; i++){
        f_set->frame_array[i] = read_frame(frame_file, frames_height, frames_lenght);
    }
    return f_set;
}

int read_int(FILE * file){
    int int_n = 0;
    char read_c;
    do{
        fread(&read_c, sizeof(char), 1, file);
        if(read_c >= 48 && read_c <= 57) int_n = int_n * 10 + strtol(&read_c, NULL, 10);
    }while(read_c != '\n');
    return int_n;
}

frame * read_frame(FILE * file, int frame_height, int frame_width){
    frame * f = malloc(sizeof(frame));
    f->frame_height = frame_height;
    f->frame_width = frame_width;
    f->frame_matrix = malloc(sizeof(char*) * frame_height);
    for(int i = 0; i < frame_height; i++)   f->frame_matrix[i] = malloc(sizeof(char) * frame_width);
    char pixel;
    /* Seek of the frame in the file */  
    // Finding the frame initiation "# N"
    do{
        fread(&pixel, sizeof(char), 1, file);
    }while(pixel != '#');
    // Skiping this line
    do{
        fread(&pixel, sizeof(char), 1, file);
    }while(pixel != '\n');

    for(int i = 0; i < frame_height; i++){
        for(int j = 0; j < frame_width; j++){
            // Clealing '\n' in the file read
            do{
                fread(&pixel, sizeof(char), 1, file);
            }while(pixel == '\n');
            f->frame_matrix[i][j] = pixel != ',' ? pixel : ' ' ;    // Using ',' as a blank character
        }
    }
    return f;
}

void print_frame_old(frame * f){
    for(int i = 0; i < f->frame_height; i++){
        for(int j = 0; j < f->frame_width; j++){
            printf("%c ", f->frame_matrix[i][j]);
        }
        printf("\n");
    }
}

void free_frame_set(frame_set ** f_set){
    for(int i = 0; i < (*f_set)->frame_count; i++) free_frame(&(*f_set)->frame_array[i]);
    free(*f_set);
}

void free_frame(frame ** f){
    for(int i = 0; i < (*f)->frame_height; i++) free((*f)->frame_matrix[i]);
    free((*f)->frame_matrix);
    free(*f);
}