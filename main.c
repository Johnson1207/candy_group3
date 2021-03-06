#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "function_header.h"
#include "struct.h"


#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include <windows.h>

// Definition of display size
#define DISPLAY_WIDTH   680
#define DISPLAY_HEIGHT  680

int main ()
{
    form stru;
    stru.score=0;


    int rows=9, cols=9;

    int times=0, t=0;
    int b;

    srand( (unsigned)time(NULL) );

    stru.body = create_matrix2(rows, cols);
    stru.emp = create_matrix2(rows, cols);

    random_mat2D(stru.body, rows, cols);
    initialize_mat2D(stru.emp, rows, cols);

    printf("How many times you want to try?");
    scanf("%d", &times);


    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_BITMAP* bitmap = NULL;
    ALLEGRO_BITMAP* bitmap1 = NULL;
    ALLEGRO_BITMAP* bitmap2 = NULL;
    ALLEGRO_BITMAP* bitmap3 = NULL;
    ALLEGRO_BITMAP* bitmap4 = NULL;
    ALLEGRO_BITMAP* bitmap5 = NULL;
    ALLEGRO_BITMAP* bitmap6 = NULL;
    //ALLEGRO_SAMPLE *background = NULL; /* pointer to sound file */
    ALLEGRO_FONT *pongFont = NULL; /* pointer to Font file */
    ALLEGRO_KEYBOARD_STATE KBstate;
    //ALLEGRO_MOUSE_STATE MSstate;




    // Initialize Allegro
    al_init();
    al_init_image_addon();
    al_install_keyboard(); /* install the keyboard for Allegro to use */
    al_install_mouse(); /* install the mouse for Allegro to use */
    al_install_audio();  // install sound driver
    al_init_acodec_addon();
    al_reserve_samples(9);
    al_init_font_addon();    // install font addons
    al_init_ttf_addon();

    // Create allegro display
    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

    // Load bitmap
    bitmap = al_load_bitmap("./color.jpg");
    bitmap1 = al_load_bitmap("./1.jpg");
    bitmap2 = al_load_bitmap("./2.jpg");
    bitmap3 = al_load_bitmap("./3.jpg");
    bitmap4 = al_load_bitmap("./4.jpg");
    bitmap5 = al_load_bitmap("./bom.jpg");
    bitmap6 = al_load_bitmap("./6.jpg");

    //background = al_load_sample("sponge.wav"); /* load the background sound file */
    //al_play_sample(background, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

    pongFont = al_load_ttf_font("ARCHRISTY.ttf", 30, 0); /* load the FONT file */

    //fill the matrix with picture

    pic_fill(stru.body, rows, cols, bitmap, bitmap1, bitmap2, bitmap3, bitmap4, bitmap5, pongFont, stru.score, times-t);
    //num_fill(rows, cols, pongFont);

    while(1)
    {
        check(rows, cols, stru.body, stru.emp);
        pic_fill(stru.body, rows, cols, bitmap, bitmap1, bitmap2, bitmap3, bitmap4, bitmap5, pongFont, stru.score, times-t);
        num_fill(rows, cols, pongFont);
        //system("pause");
        b=break_point(rows, cols, stru.emp);
        printf_matrix2("\n\nyour game:\n\n",rows, cols, stru.body);
        printf_matrix2("\n\nyour check:\n\n", rows, cols, stru.emp);
        pic_fill(stru.body, rows, cols, bitmap, bitmap1, bitmap2, bitmap3, bitmap4, bitmap5, pongFont, stru.score, times-t);
        num_fill(rows, cols, pongFont);
        //system("pause");
        stru.score=score(rows, cols, stru.score, stru.emp);
        clear(rows, cols, stru.body, stru.emp);
        initialize_mat2D(stru.emp, rows, cols);
        printf_matrix2("\n\nyour game:\n\n",rows, cols, stru.body);
        printf_matrix2("\n\nyour check:\n\n",rows, cols, stru.emp);
        printf("\nscore:%d\n",stru.score);
        pic_fill(stru.body, rows, cols, bitmap, bitmap1, bitmap2, bitmap3, bitmap4, bitmap5, pongFont, stru.score, times-t);
        num_fill(rows, cols, pongFont);
        //system("pause");
        refill(rows, cols, stru.body, stru.emp);

        //system("pause");

        if(b==0)
            break;
    }

    while(t != times)
    {
        change(rows, cols, stru.body, stru.emp);

        t++;

        while(1)
        {
            check(rows, cols, stru.body, stru.emp);
            b=break_point(rows, cols, stru.emp);
            pic_fill(stru.body, rows, cols, bitmap, bitmap1, bitmap2, bitmap3, bitmap4, bitmap5, pongFont, stru.score, times-t);
            num_fill(rows, cols, pongFont);
            stru.score=score(rows, cols, stru.score, stru.emp);
            clear(rows, cols, stru.body, stru.emp);
            initialize_mat2D(stru.emp, rows, cols);
            printf("\nscore:%d\n",stru.score);
            pic_fill(stru.body, rows, cols, bitmap, bitmap1, bitmap2, bitmap3, bitmap4, bitmap5, pongFont, stru.score, times-t);
            num_fill(rows, cols, pongFont);
            refill(rows, cols, stru.body, stru.emp);
            pic_fill(stru.body, rows, cols, bitmap, bitmap1, bitmap2, bitmap3, bitmap4, bitmap5, pongFont, stru.score, times-t);

            num_fill(rows, cols, pongFont);

            if(b==0)
            {
                break;
            }

            al_get_keyboard_state(&KBstate);
            if (al_key_down(&KBstate, ALLEGRO_KEY_ESCAPE))
                break;
        }

        if(t==times)
        {
            al_draw_bitmap(bitmap6, 45, 0, 0);
            al_draw_textf( pongFont, al_map_rgb(55, 55, 255), 330, 400, -1, "Player Score: %d",stru.score);

            al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));

            system("pause");
        }


        al_get_keyboard_state(&KBstate);
        if (al_key_down(&KBstate, ALLEGRO_KEY_ESCAPE))
            break;
    }

    form a[10];
    int num ;
    char nam ;
    time_t timep;
    struct tm *p;

    time(&timep);
    p = gmtime(&timep);
    printf("\n%d  %d  %d", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
    printf("  %d:%d:%d\n", p->tm_hour+8, p->tm_min, p->tm_sec);

    printf("Name:\n");
    scanf("%s",a[5].name);

    a[5].score=stru.score;
    a[5].time[0]=1900+p->tm_year;
    a[5].time[1]=1+p->tm_mon;
    a[5].time[2]=p->tm_mday;
    a[5].time[3]=p->tm_hour+8;
    a[5].time[4]=p->tm_min;
    a[5].time[5]=p->tm_sec;

    sort(a);

    system("pause");

    rank(a,nam,num);

    // Cleanup
    al_destroy_bitmap(bitmap);
    al_destroy_bitmap(bitmap1);
    al_destroy_bitmap(bitmap2);
    al_destroy_bitmap(bitmap3);
    al_destroy_bitmap(bitmap4);
    al_destroy_bitmap(bitmap5);
    al_destroy_bitmap(bitmap6);
    al_destroy_display(display);
    //al_destroy_sample(background); /* destroy the background sound file */
    al_destroy_font(pongFont); /* destroy the font */

    free_matrix(rows, stru.body);
    free_matrix(rows, stru.emp);

    system("pause");

    return 0;
}
