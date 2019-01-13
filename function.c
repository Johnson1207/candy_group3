#include "function_header.h"
#include "struct.h"

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

void pic_fill(int **a, int **f, int m, int n,
              ALLEGRO_BITMAP* b, ALLEGRO_BITMAP* r, ALLEGRO_BITMAP* o, ALLEGRO_BITMAP* p,
              ALLEGRO_BITMAP* g, ALLEGRO_BITMAP* b5, ALLEGRO_FONT *pongFont,
              int score, int step,
              ALLEGRO_BITMAP* r1, ALLEGRO_BITMAP* r2, ALLEGRO_BITMAP* r3,
              ALLEGRO_BITMAP* o1, ALLEGRO_BITMAP* o2, ALLEGRO_BITMAP* o3,
              ALLEGRO_BITMAP* p1, ALLEGRO_BITMAP* p2, ALLEGRO_BITMAP* p3,
              ALLEGRO_BITMAP* g1, ALLEGRO_BITMAP* g2, ALLEGRO_BITMAP* g3)
{
    int i=0, j=0;

    al_draw_bitmap(b, 85, 85, 0);

    for(i=0; i<m; i++)
    {
        al_draw_textf( pongFont, al_map_rgb(55, 55, 255), 115 + 55*i, 50, -1, "%d",i);

        for(j=0; j<n; j++)
        {
            al_draw_textf( pongFont, al_map_rgb(55, 55, 255), 60, 95+ 55*j, -1, "%d",j);

            if( ((a[i][j] == 1) && (f[i][j] == 0)) || ((a[i][j] == 1) && (f[i][j] == 5)))
                al_draw_bitmap(r, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 1) && (f[i][j] == 1))
                al_draw_bitmap(r1, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 1) && (f[i][j] == 2))
                al_draw_bitmap(r2, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 1) && (f[i][j] == 3))
                al_draw_bitmap(r3, 55*j+90, 55*i+90, 0);

            if( ((a[i][j] == 2) && (f[i][j] == 0)) || ((a[i][j] == 2) && (f[i][j] == 5)))
                al_draw_bitmap(o, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 2) && (f[i][j] == 1))
                al_draw_bitmap(o1, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 2) && (f[i][j] == 2))
                al_draw_bitmap(o2, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 2) && (f[i][j] == 3))
                al_draw_bitmap(o3, 55*j+90, 55*i+90, 0);

            if( ((a[i][j] == 3) && (f[i][j] == 0)) || ((a[i][j] == 3) && (f[i][j] == 5)))
                al_draw_bitmap(p, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 3) && (f[i][j] == 1))
                al_draw_bitmap(p1, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 3) && (f[i][j] == 2))
                al_draw_bitmap(p2, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 3) && (f[i][j] == 3))
                al_draw_bitmap(p3, 55*j+90, 55*i+90, 0);

            if( ((a[i][j] == 4) && (f[i][j] == 0)) || ((a[i][j] == 4) && (f[i][j] == 5)))
                al_draw_bitmap(g, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 4) && (f[i][j] == 1))
                al_draw_bitmap(g1, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 4) && (f[i][j] == 2))
                al_draw_bitmap(g2, 55*j+90, 55*i+90, 0);
            if( (a[i][j] == 4) && (f[i][j] == 3))
                al_draw_bitmap(g3, 55*j+90, 55*i+90, 0);
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
