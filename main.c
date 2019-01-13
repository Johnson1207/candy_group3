#include "function_header.h"
#include "struct.h"

// Definition of display size
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
    stru.fun = create_matrix2(rows, cols);

    random_mat2D(stru.body, rows, cols);
    initialize_mat2D(stru.emp, rows, cols);
    initialize_mat2D(stru.fun, rows, cols);

    printf("How many times you want to try?");
    scanf("%d", &times);

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_BITMAP* bitmap = NULL;
    ALLEGRO_BITMAP* red = NULL;
    ALLEGRO_BITMAP* red_1 = NULL;
    ALLEGRO_BITMAP* red_2 = NULL;
    ALLEGRO_BITMAP* red_3 = NULL;
    ALLEGRO_BITMAP* orange = NULL;
    ALLEGRO_BITMAP* orange_1 = NULL;
    ALLEGRO_BITMAP* orange_2 = NULL;
    ALLEGRO_BITMAP* orange_3 = NULL;
    ALLEGRO_BITMAP* purple = NULL;
    ALLEGRO_BITMAP* purple_1 = NULL;
    ALLEGRO_BITMAP* purple_2 = NULL;
    ALLEGRO_BITMAP* purple_3 = NULL;
    ALLEGRO_BITMAP* green = NULL;
    ALLEGRO_BITMAP* green_1 = NULL;
    ALLEGRO_BITMAP* green_2 = NULL;
    ALLEGRO_BITMAP* green_3 = NULL;
    ALLEGRO_BITMAP* boom = NULL;
    ALLEGRO_BITMAP* over = NULL;//ALLEGRO_SAMPLE *background = NULL; /* pointer to sound file */
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
    red = al_load_bitmap("./red.png");
    red_1 = al_load_bitmap("./red_1.png");
    red_2 = al_load_bitmap("./red_2.png");
    red_3 = al_load_bitmap("./red_3.png");
    orange = al_load_bitmap("./orange.png");
    orange_1 = al_load_bitmap("./orange_1.png");
    orange_2 = al_load_bitmap("./orange_2.png");
    orange_3 = al_load_bitmap("./orange_3.png");
    purple = al_load_bitmap("./purple.png");
    purple_1 = al_load_bitmap("./purple_1.png");
    purple_2 = al_load_bitmap("./purple_2.png");
    purple_3 = al_load_bitmap("./purple_3.png");
    green = al_load_bitmap("./green.png");
    green_1 = al_load_bitmap("./green_1.png");
    green_2 = al_load_bitmap("./green_2.png");
    green_3 = al_load_bitmap("./green_3.png");
    boom = al_load_bitmap("./bom.jpg");
    over = al_load_bitmap("./6.jpg");

    //background = al_load_sample("sponge.wav"); /* load the background sound file */
    //al_play_sample(background, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

    pongFont = al_load_ttf_font("ARCHRISTY.ttf", 30, 0); /* load the FONT file */

    //fill the matrix with picture

    pic_fill(stru.body, stru.fun, rows, cols,
             bitmap, red, orange, purple, green, boom, pongFont,
             stru.score, times-t,
             red_1, red_2, red_3, orange_1, orange_2, orange_3,
             purple_1, purple_2, purple_3, green_1, green_2, green_3);
    //num_fill(rows, cols, pongFont);

    //system("pause");

    while(1)
    {
        check(rows, cols, stru.body, stru.emp, stru.fun);

        pic_fill(stru.body, stru.fun, rows, cols,
                 bitmap, red, orange, purple, green, boom, pongFont,
                 stru.score, times-t,
                 red_1, red_2, red_3, orange_1, orange_2, orange_3,
                 purple_1, purple_2, purple_3, green_1, green_2, green_3);

        //num_fill(rows, cols, pongFont);
        //system("pause");
        b=break_point(rows, cols, stru.emp);

        printf_matrix2("\n\nyour game:\n\n",rows, cols, stru.body);
        printf_matrix2("\n\nyour check:\n\n", rows, cols, stru.emp);
        pic_fill(stru.body, stru.fun, rows, cols,
                 bitmap, red, orange, purple, green, boom, pongFont,
                 stru.score, times-t,
                 red_1, red_2, red_3, orange_1, orange_2, orange_3,
                 purple_1, purple_2, purple_3, green_1, green_2, green_3);
        num_fill(rows, cols, pongFont);
        //system("pause");
        stru.score=score(rows, cols, stru.score, stru.emp);
        clear(rows, cols, stru.body, stru.emp);
        initialize_mat2D(stru.emp, rows, cols);
        printf_matrix2("\n\nyour game:\n\n",rows, cols, stru.body);
        printf_matrix2("\n\nyour check:\n\n",rows, cols, stru.emp);
        printf_matrix2("\n\nyour function:\n\n", rows, cols, stru.fun);
        printf("\nscore:%d\n",stru.score);
        pic_fill(stru.body, stru.fun, rows, cols,
                 bitmap, red, orange, purple, green, boom, pongFont,
                 stru.score, times-t,
                 red_1, red_2, red_3, orange_1, orange_2, orange_3,
                 purple_1, purple_2, purple_3, green_1, green_2, green_3);
        //num_fill(rows, cols, pongFont);
        //system("pause");
        refill(rows, cols, stru.body, stru.emp);

        //system("pause");

        if(b==0)
            break;
    }

    while(t != times)
    {
        change(rows, cols, stru.body, stru.emp, stru.fun);

        t++;

        while(1)
        {
            check(rows, cols, stru.body, stru.emp, stru.fun);
            b=break_point(rows, cols, stru.emp);

            pic_fill(stru.body, stru.fun, rows, cols,
                     bitmap, red, orange, purple, green, boom, pongFont,
                     stru.score, times-t,
                     red_1, red_2, red_3, orange_1, orange_2, orange_3,
                     purple_1, purple_2, purple_3, green_1, green_2, green_3);
            //num_fill(rows, cols, pongFont);

            stru.score=score(rows, cols, stru.score, stru.emp);
            clear(rows, cols, stru.body, stru.emp);

            initialize_mat2D(stru.emp, rows, cols);
            printf("\nscore:%d\n",stru.score);
            pic_fill(stru.body, stru.fun, rows, cols,
                     bitmap, red, orange, purple, green, boom, pongFont,
                     stru.score, times-t,
                     red_1, red_2, red_3, orange_1, orange_2, orange_3,
                     purple_1, purple_2, purple_3, green_1, green_2, green_3);
            //num_fill(rows, cols, pongFont);
            refill(rows, cols, stru.body, stru.emp);
            pic_fill(stru.body, stru.fun, rows, cols,
                     bitmap, red, orange, purple, green, boom, pongFont,
                     stru.score, times-t,
                     red_1, red_2, red_3, orange_1, orange_2, orange_3,
                     purple_1, purple_2, purple_3, green_1, green_2, green_3);

            //num_fill(rows, cols, pongFont);

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
            al_draw_bitmap(over, 45, 0, 0);
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
    int num = NULL;
    char nam = NULL;
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
    if(a[5].time[3]>=24)
        a[5].time[3]=a[5].time[3]-24;
    a[5].time[4]=p->tm_min;
    a[5].time[5]=p->tm_sec;

    sort(a);

    system("pause");

    rank(a,nam,num);

    // Cleanup
    al_destroy_bitmap(bitmap);
    al_destroy_bitmap(red);
    al_destroy_bitmap(red_1);
    al_destroy_bitmap(red_2);
    al_destroy_bitmap(red_3);
    al_destroy_bitmap(orange);
    al_destroy_bitmap(orange_1);
    al_destroy_bitmap(orange_2);
    al_destroy_bitmap(orange_3);
    al_destroy_bitmap(purple);
    al_destroy_bitmap(purple_1);
    al_destroy_bitmap(purple_2);
    al_destroy_bitmap(purple_3);
    al_destroy_bitmap(green);
    al_destroy_bitmap(green_1);
    al_destroy_bitmap(green_2);
    al_destroy_bitmap(green_3);
    al_destroy_bitmap(boom);
    al_destroy_bitmap(over);
    al_destroy_display(display);
    //al_destroy_sample(background); /* destroy the background sound file */
    al_destroy_font(pongFont); /* destroy the font */

    free_matrix(rows, stru.body);
    free_matrix(rows, stru.emp);
    free_matrix(rows, stru.fun);

    system("pause");

    return 0;
}
