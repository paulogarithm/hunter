/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_sprites
*/

#include "../include/hunter.h"
#include "../include/types.h"
#include "../include/statics.h"

hunt_object game_findtype(hunt_object *my_objects, int type);
int game_getindex_byid(hunt_object *objs, int id);

hunt_object game_obj_new(hunt_object pattern, sfVector2f position)
{
    hunt_object my_object = pattern;

    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(my_object.texture, NULL);
    sfIntRect rectangle = {0, 0, my_object.size, my_object.size};
    sfVector2f scale = {GLOBAL_SCALE, GLOBAL_SCALE};
    int orientation = rand() % 2;
    if (!orientation) orientation = -1;
    my_object.orientation = orientation;
    my_object.sprite = sprite;
    my_object.clock = sfClock_create();
    my_object.id = rand();
    my_object.speed = (rand() % 10) + 10;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(my_object.sprite, rectangle);
    sfSprite_setScale(my_object.sprite, scale);
    sfSprite_setPosition(my_object.sprite, position);

    return my_object;
}

hunt_object *game_obj_insert(hunt_object *objs, hunt_object obj, sfVector2f p)
{
    obj = game_obj_new(obj, p);
    for (int i = 0; i < SPRITES_MAX; i ++) {
        if (objs[i].type < 0) {
            objs[i] = obj;
            break;
        }
    }
    return objs;
}

void set_healthcolor(hunt_object *objs)
{
    hunt_object tmp_health = game_findtype(objs, 7);
    if (tmp_health.id == 0) return;

    int idx_health = game_getindex_byid(objs, tmp_health.id);
    if (idx_health < 0) return;

    hunt_object *health = &objs[idx_health];
    sfColor color = sfColor_fromRGB(0, 255, 0);
    sfSprite_setColor(health->sprite, color);
}

hunt_object *game_obj(void)
{
    sfVector2f pos;
    hunt_object *my_objects = malloc(sizeof(hunt_object) * SPRITES_MAX);
    for (int i = 0; i < SPRITES_MAX; i ++) my_objects[i] = hunt_typeEMPTY;

    pos = (sfVector2f) {WIN_POS_X, WIN_POS_Y};
    game_obj_insert(my_objects, hunt_typeWINDOW, pos);
    pos = (sfVector2f) {0, -200};
    game_obj_insert(my_objects, hunt_typeBRIDGE, pos);
    pos = (sfVector2f) {100 + rand() % 400, 250 + rand() % 300};
    game_obj_insert(my_objects, hunt_typeCLOUD, pos);
    pos = (sfVector2f) {100 + rand() % 400, 250 + rand() % 300};
    game_obj_insert(my_objects, hunt_typeCLOUD2, pos);
    pos = (sfVector2f) {100 + rand() % 400, 10 + rand() % 100};
    game_obj_insert(my_objects, hunt_typeCLOUD2, pos);
    pos = (sfVector2f) {600, 10};
    game_obj_insert(my_objects, hunt_typeHEALTH, pos);
    set_healthcolor(my_objects);
    return my_objects;
}
