/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_attack
*/

#include "../include/hunter.h"
#include "../include/types.h"

hunt_object game_findtype(hunt_object *my_objects, int type);
void game_show_array(hunt_object *my_objs, int show_empty);
int game_getindex_byid(hunt_object *objs, int id);

int my_rand(int a, int b)
{
    return a + (rand() % (a + 1 - b));
}

hunt_object check_health(sfIntRect rect, hunt_object *health)
{
    int R = 255 - ((float)rect.width / health->size) * 255;
    int G = ((float)rect.width / health->size) * 255;
    sfColor color = sfColor_fromRGB(R, G, 0);
    sfSprite_setColor(health->sprite, color);
    if (rect.width <= 0) {
        return hunt_typeEMPTY;
    }
    return *health;
}

int get_health_index(hunt_object *objs)
{
    hunt_object tmp_health = game_findtype(objs, 7);
    if (tmp_health.id == 0) return -1;
    int idx_health = game_getindex_byid(objs, tmp_health.id);
    return idx_health;
}

void game_attack(hunt_object *obj, hunt_object *objs)
{
    sfIntRect rectangle = sfSprite_getTextureRect(obj->sprite);
    rectangle.top = obj->size;
    if (rectangle.left == 0) {
        int idx_health = get_health_index(objs);
        if (idx_health >= 0) {
            hunt_object *health = &objs[idx_health];
            sfIntRect rect = sfSprite_getTextureRect(health->sprite);
            rect.width -= my_rand(10, 20);
            sfSprite_setTextureRect(health->sprite, rect);
            *health = check_health(rect, health);
        }
        obj->attack = 0;
    }
    rectangle.left += obj->size;
    if (rectangle.left > obj->size * (obj->raws - 1)) {
        rectangle.left = 0;
    }
    sfSprite_setTextureRect(obj->sprite, rectangle);
    sfClock_restart(obj->clock);
    return;
}
