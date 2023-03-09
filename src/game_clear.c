/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_clear
*/

#include "../include/hunter.h"

void game_clear_objs(hunt_instances *inst)
{
    hunt_object *my_objects = inst->game;
    for (int i = 0; i < SPRITES_MAX; i ++) {
        sfSprite_destroy(my_objects[i].sprite);
        sfClock_destroy(my_objects[i].clock);
        sfText_destroy(my_objects[i].text);
    }
    free(my_objects);
    my_objects = inst->menu;
    for (int i = 0; i < SPRITES_MAX; i ++) {
        sfSprite_destroy(my_objects[i].sprite);
        sfClock_destroy(my_objects[i].clock);
        sfText_destroy(my_objects[i].text);
    }
    free(my_objects);
    return;
}

void game_clear(sfRenderWindow *window, sfClock *clock)
{
    sfRenderWindow_destroy(window);
    sfClock_destroy(clock);
    return;
}
