/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_clock
*/

#include "../include/hunter.h"
#include "../include/statics.h"
#include "../include/types.h"

void game_animenmy(hunt_object *obj, hunt_object *objs);
void game_animhand(sfRenderWindow *w, hunt_object *o, float s, hunt_object *os);
void game_animcloud(hunt_object *obj);

void game_objclock(sfRenderWindow *window, hunt_object *obj, hunt_object *objs)
{
    if (obj->type < 0) return;
    if (obj->clock == NULL) return;

    sfTime obj_time = sfClock_getElapsedTime(obj->clock);
    float seconds = obj_time.microseconds / 1000000.0;

    if (obj->type == 1 && seconds >= .5) {
        game_animenmy(obj, objs);
        return;
    }
    if (obj->type == 4 && seconds >= .2) {
        game_animcloud(obj);
        return;
    }
    if (obj->type == 3) {
        game_animhand(window, obj, seconds, objs);
        return;
    }
}

void game_clock(sfRenderWindow *window, sfClock *clock, hunt_object *objs)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 10000000.0;
    if (seconds > 1) {

    }
    for (int i = 0; i < SPRITES_MAX; i ++) {
        game_objclock(window, &objs[i], objs);
    }
    return;
}
