#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DISPLAY_WIDTH   680
#define DISPLAY_HEIGHT  680


int **create_matrix2(int rows, int cols);
void printf_matrix2(char *message, int rows, int cols, int **mat);
void random_mat2D(int **a, int rows, int cols);
void initialize_mat2D(int **a, int rows, int cols);
void pic_fill(int **a, int m, int n, ALLEGRO_BITMAP* b, ALLEGRO_BITMAP* b1, ALLEGRO_BITMAP* b2, ALLEGRO_BITMAP* b3, ALLEGRO_BITMAP* b4, ALLEGRO_BITMAP* b5,  ALLEGRO_FONT *pongFont,int score, int step);
void num_fill(int m, int n, ALLEGRO_FONT *pongFont);
void free_matrix(int rows, int **mat);
int **change(int r, int c, int **mat, int **emp, int **fun);
int **check(int r, int c, int **body, int **emp, int **fun);
int **check_fun(int r,int c,int **emp,int **fun,int k,int j);
int **clear(int r, int c, int **body, int **emp);
int **refill(int r, int c, int **body, int **emp);
int score(int r, int c, int score, int **emp);
int break_point(int r, int c, int **emp);
int mouse(int *x, int *y);

