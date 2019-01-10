#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "function_header.h"
#include "struct.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


// Definition of display size
#define DISPLAY_WIDTH   680
#define DISPLAY_HEIGHT  680



int **create_matrix2(int rows, int cols)
{
// input rows and cols
// output a pointer to 2D mat[rows][cols]

    int **mat = (int **) malloc(sizeof(int *)*rows);
    int i=0,j=0;
    for(i=0; i<rows; i++)
        // Allocate array, store pointer
        mat[i] = (int *) malloc(sizeof(int)*cols);

    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            mat[i][j]=0;
        }
    }
    return mat;
}

void printf_matrix2(char *message, int rows, int cols, int **mat)
{
//input message, row, col, matrix
//print message and matrix

    int i=0,j=0;
    printf("%s",message);

    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("%3d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void random_mat2D(int **a, int rows, int cols)
{
    // randomize all elements in a

    int i=0,j=0;

    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            a[i][j]=(int) (rand()%4+1);
        }
    }
}

void initialize_mat2D(int **a, int rows, int cols)
{
    // randomize all elements in a

    int i=0,j=0;

    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            a[i][j]=(int) (0);
        }
    }
}

void pic_fill(int **a, int m, int n, ALLEGRO_BITMAP* b, ALLEGRO_BITMAP* b1, ALLEGRO_BITMAP* b2, ALLEGRO_BITMAP* b3, ALLEGRO_BITMAP* b4, ALLEGRO_BITMAP* b5, ALLEGRO_FONT *pongFont, int score, int step)
{
    int i=0, j=0;

    al_draw_bitmap(b, 85, 85, 0);

    for(i=0; i<m; i++)
    {
        al_draw_textf( pongFont, al_map_rgb(55, 55, 255), 115 + 55*i, 50, -1, "%d",i);

        for(j=0; j<n; j++)
        {
            al_draw_textf( pongFont, al_map_rgb(55, 55, 255), 60, 95+ 55*j, -1, "%d",j);

            if(a[i][j] == 1)
                al_draw_bitmap(b1, 55*j+90, 55*i+90, 0);
            if(a[i][j] == 2)
                al_draw_bitmap(b2, 55*j+90, 55*i+90, 0);
            if(a[i][j] == 3)
                al_draw_bitmap(b3, 55*j+90, 55*i+90, 0);
            if(a[i][j] == 4)
                al_draw_bitmap(b4, 55*j+90, 55*i+90, 0);
            if(a[i][j] == 0)
                al_draw_bitmap(b5, 55*j+90, 55*i+90, 0);
        }
    }
    al_rest(0.5);

    al_draw_textf( pongFont, al_map_rgb(55, 55, 255), 200, 0, -1, "Player Score: %d",score);
    al_draw_textf( pongFont, al_map_rgb(55, 55, 255), 500, 0, -1, "Step: %d",step);

    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
}

void num_fill(int m, int n, ALLEGRO_FONT *pongFont)
{
    int i, j;
    for (i=0; i<m; i++)
    {
        al_draw_textf( pongFont, al_map_rgb(55, 55, 255), 115 + 55*i, 50, -1, "%d",i);
    }
    for (j=0; j<n; j++)
    {
        al_draw_textf( pongFont, al_map_rgb(55, 55, 255), 60, 95+ 55*j, -1, "%d",j);
    }
}

void free_matrix(int rows, int **mat)
{
    int i=0;
    for(i=0; i<rows; i++)
        free(mat[i]);
    free(mat);
}

int **change(int r, int c, int **mat, int **emp)
{
    int **a=create_matrix2(r,c);

    int x1=0, y1=0, x2=0, y2=0;

    int b;

    printf ("Enter the row of the face you wanna move:");
    scanf ("%d",&x1);
    printf ("Enter the col of the face you wanna move:");
    scanf ("%d",&y1);

    printf ("Enter the row of the position you wanna move to:");
    scanf ("%d",&x2);
    printf ("Enter the col of the position you wanna move to:");
    scanf ("%d",&y2);

    if( (x1==x2 && (y1-y2==1 || y2-y1==1)) || (y1==y2 && (x1-x2==1 ||x2-x1==1)))
    {
        a[y1][x1] = mat[y1][x1];
        mat[y1][x1] = mat[y2][x2];
        mat[y2][x2] = a[y1][x1];

        check(r, c, mat, emp);
        b=break_point(r, c, emp);
        initialize_mat2D(emp, r, c);

        if(b==0)
        {
            printf("\nerror\n\n");

            a[y1][x1] = mat[y1][x1];
            mat[y1][x1] = mat[y2][x2];
            mat[y2][x2] = a[y1][x1];

            change(r, c, mat, emp);
        }
    }
    else
    {
        printf("\nerror\n\n");
        change(r, c, mat, emp);
    }


    return mat;
}

int **check(int r, int c, int **body, int **emp)
{
    int j,k;
    for(k=0; k<r; k++)
    {
        for(j=0; j<c-2; j++)
        {
            if (  (body[k][j]== body[k][j+1])  &&  (body[k][j+1]==body[k][j+2])  )/*橫的連續先檢查*/
            {
                emp[k][j]=1;
                emp[k][j+1]=1;
                emp[k][j+2]=1;

            }

        }

        for(j=0; j<r-2; j++) /*檢查直的連續*/
        {
            if (  (body[j][k]==body[j+1][k]) && (body[j+1][k]==body[j+2][k])   )
            {
                emp[j][k]=1;
                emp[j+1][k]=1;
                emp[j+2][k]=1;
            }

        }

    }
    return emp;
}

int **clear(int r, int c, int **body, int **emp)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(emp[i][j]==1)
            {
                body[i][j]=0;
            }
        }
    }
    return body;
}

int **refill(int r, int c, int **body, int **emp)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(  body[i][j]==0  )
            {
                for(i=i; i>0; i--)
                {
                    body[i][j]=body[i-1][j];
                }
                body[i][j]=rand()%4+1;
            }
        }
    }
    return body;
}

int score(int r, int c, int score, int **emp)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(emp[i][j]==1)
            {
                score+=10;
            }
        }
    }

    return score ;
}

int break_point(int r, int c, int **emp)
{

    int i, j, b=0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(emp[i][j]==1)
            {
                b+=1;
            }
        }
    }

    return b ;
}

void sort(form a[])
{
    int *fkey;
    int i,j,k,t ;
    int max=0,temp=0 ;

    fkey=fopen("score.txt","r");
    if(fkey==NULL)
    {
        printf("ERROR");
    }
    else
    {
        for(i=0; i<5; i++)
        {
            fscanf(fkey,"%s%d", a[i].name, &a[i].score);
            fscanf(fkey,"%d%d%d", &a[i].time[0], &a[i].time[1], &a[i].time[2]);
            fscanf(fkey,"%d%d%d\n", &a[i].time[3], &a[i].time[4], &a[i].time[5]);

        }
    }
    fclose(fkey);


    for(i=0; i<6; i++)
    {
        printf("%s %d",a[i].name,a[i].score);
        printf("  %d  %d  %d", a[i].time[0], a[i].time[1], a[i].time[2]);
        printf("  %d:%d:%d\n", a[i].time[3], a[i].time[4], a[i].time[5]);

    }

    system("pause");

    printf("\n");

    for(j=0; j<6; j++)
    {
        for(i=j; i<6; i++)
        {
            if(a[i].score>max)
            {
                max=a[i].score;
                k=i;
            }
        }
        temp=a[j].score;
        a[j].score=max;
        a[k].score=temp;
        max=0;

        strcpy(a[7].name,a[j].name);
        strcpy(a[j].name,a[k].name);
        strcpy(a[k].name,a[7].name);

        for(t=0; t<6; t++)
        {
            temp=a[j].time[t];
            a[j].time[t]=a[k].time[t];
            a[k].time[t]=temp;
        }
    }
    for(i=0; i<6; i++)
    {
        printf("%s %d",a[i].name,a[i].score);
        printf("  %d  %d  %d", a[i].time[0], a[i].time[1], a[i].time[2]);
        printf("  %d:%d:%d\n", a[i].time[3], a[i].time[4], a[i].time[5]);

    }

    fkey=fopen("score.txt","w");
    if(fkey==NULL)
    {
        printf("error");
    }
    else
    {
        for(i=0; i<6; i++)
        {
            fprintf(fkey,"%s %d",a[i].name,a[i].score);
            fprintf(fkey," %d %d %d", a[i].time[0], a[i].time[1], a[i].time[2]);
            fprintf(fkey," %d %d %d\n", a[i].time[3], a[i].time[4], a[i].time[5]);
        }

    }
    fclose(fkey);

}

void rank(form a[],char nam,int num)
{
    int *fkey;
    int i ;

    fkey=fopen("score.txt","r");
    if(fkey==NULL)
    {
        printf("ERROR");
    }
    else
    {
        for(i=0; i<5; i++)
        {
            fscanf(fkey,"%s%d", a[i].name, &a[i].score);
            fscanf(fkey,"%d%d%d", &a[i].time[0], &a[i].time[1], &a[i].time[2]);
            fscanf(fkey,"%d%d%d\n", &a[i].time[3], &a[i].time[4], &a[i].time[5]);

        }
    }
    fclose(fkey);

    printf("\n\n------LEADER BOARD------\n\n");

    i=0;
    printf("first--%s: %d",a[i].name,a[i].score);
    printf(" %d %d %d", a[i].time[0], a[i].time[1], a[i].time[2]);
    printf(" %d:%d:%d\n", a[i].time[3], a[i].time[4], a[i].time[5]);

    i=1;
    printf("second--%s: %d",a[i].name,a[i].score);
    printf(" %d %d %d", a[i].time[0], a[i].time[1], a[i].time[2]);
    printf(" %d:%d:%d\n", a[i].time[3], a[i].time[4], a[i].time[5]);

    i=2;
    printf("third--%s: %d",a[i].name,a[i].score);
    printf(" %d %d %d", a[i].time[0], a[i].time[1], a[i].time[2]);
    printf(" %d:%d:%d\n", a[i].time[3], a[i].time[4], a[i].time[5]);

    i=3;
    printf("fourth--%s: %d",a[i].name,a[i].score);
    printf(" %d %d %d", a[i].time[0], a[i].time[1], a[i].time[2]);
    printf(" %d:%d:%d\n", a[i].time[3], a[i].time[4], a[i].time[5]);

    i=4;
    printf("fifth--%s: %d",a[i].name,a[i].score);
    printf(" %d %d %d", a[i].time[0], a[i].time[1], a[i].time[2]);
    printf(" %d:%d:%d\n", a[i].time[3], a[i].time[4], a[i].time[5]);

}
