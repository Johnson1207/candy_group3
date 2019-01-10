#include "function_header.h"
#include "struct.h"

int mouse(int *x,int *y)
{
    ALLEGRO_EVENT_QUEUE *queue;
    queue = al_create_event_queue();
    al_install_mouse();
    al_register_event_source(queue, al_get_mouse_event_source());
    bool running = true;
    int xx,yy;
    while (running)
    {
        ALLEGRO_EVENT event;
        if (!al_is_event_queue_empty(queue))
        {
            al_wait_for_event(queue, &event);

            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            {
                xx = event.mouse.x - 90;
                yy = event.mouse.y - 90;
                *x = xx/55;
                *y = yy/55;
                break;
            }
        }
    }
    al_uninstall_mouse();

}
