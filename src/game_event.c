/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_event
*/

#include "../include/hunter.h"

void game_mouse(sfRenderWindow *window, sfEvent event, hunt_instances *inst);
void game_shakewindow(sfRenderWindow *window, int reset, hunt_object *objs);

void game_event_key(sfRenderWindow *window, sfEvent event)
{
    if (event.key.code == sfKeyEscape) {
        sfRenderWindow_close(window);
    }
    if (event.key.code == sfKeySpace) {

    }
}

void game_event(sfRenderWindow *window, sfEvent event, hunt_instances *inst)
{
    switch (event.type) {
        case sfEvtClosed:
        sfRenderWindow_close(window);
        break;

        case sfEvtKeyPressed:
        game_event_key(window, event);
        break;

        case sfEvtMouseButtonPressed:
        game_mouse(window, event, inst);
        break;

        default:
        break;
    }
    return;
}
