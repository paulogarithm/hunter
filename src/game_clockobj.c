/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_obj_clocks
*/

#include "../include/hunter.h"
#include "../include/statics.h"
#include "../include/types.h"

void game_shakewindow(sfRenderWindow *window, int reset, hunt_object *objs);
void game_attack(hunt_object *obj, hunt_object *objs);

void game_animcloud(hunt_object *obj)
{
    sfVector2f position = sfSprite_getPosition(obj->sprite);
    position.x += (obj->orientation * obj->speed);
    if (position.x > WIN_WIDTH + obj->size * GLOBAL_SCALE) {
        position.x = -obj->size * GLOBAL_SCALE;
    }
    if (position.x < -obj->size * GLOBAL_SCALE) {
        position.x = WIN_WIDTH + obj->size * GLOBAL_SCALE;
    }
    sfSprite_setPosition(obj->sprite, position);
    sfClock_restart(obj->clock);
}

void game_animhand(sfRenderWindow *w, hunt_object *o, float s, hunt_object *os)
{
    if (s >= .01) {
        sfVector2f pos = sfSprite_getPosition(o->sprite);
        sfIntRect rect = sfSprite_getTextureRect(o->sprite);
        if (rect.height < o->size) {
            rect.height += 2;
            game_shakewindow(w, 0, os);
        } else {
            game_shakewindow(w, 2, os);
        }

        if (pos.y > HAND_POS - o->size * GLOBAL_SCALE) {
            pos.y -= 2 * GLOBAL_SCALE;
            sfClock_restart(o->clock);
        }
        sfSprite_setPosition(o->sprite, pos);
        sfSprite_setTextureRect(o->sprite, rect);
    }
    if (s >= 1) *o = hunt_typeEMPTY;
    return;
}

int check_attack(hunt_object *obj, hunt_object *objs)
{
    if (obj->attack) {
        game_attack(obj, objs);
        return 1;
    }
    if (rand() % 10 == 1) {
        sfIntRect rectangle = sfSprite_getTextureRect(obj->sprite);
        rectangle.left = 0;
        sfSprite_setTextureRect(obj->sprite, rectangle);
        obj->attack = 1;
    }
    return 0;
}

void game_animenmy(hunt_object *obj, hunt_object *objs)
{
    if (check_attack(obj, objs)) return;
    sfIntRect rectangle = sfSprite_getTextureRect(obj->sprite);
    sfVector2f position = sfSprite_getPosition(obj->sprite);

    rectangle.left += obj->size;
    rectangle.top = 0;
    if (rectangle.left > obj->size * (obj->raws - 1))
        rectangle.left = 0;
    position.x += (obj->orientation * obj->speed);
    if (position.x >= .8 * WIN_WIDTH || position.x <= .05 * WIN_WIDTH) {
        position.x -= (obj->orientation * obj->speed);
        obj->orientation *= -1;
    }
    sfSprite_setTextureRect(obj->sprite, rectangle);
    sfSprite_setPosition(obj->sprite, position);
    sfClock_restart(obj->clock);
}
