/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_USEFULL
*/

#include "../include/hunter.h"
#include "../include/types.h"
#include "../include/statics.h"

void game_show_array(hunt_object *my_objs, int show_empty);
sfVector2i convert_vf_vi(sfVector2f v);
sfVector2f convert_vi_vf(sfVector2i v);
void my_showstr(char *str);

int game_getindex_byid(hunt_object *objs, int id)
{
    for (int i = 0; i < SPRITES_MAX; i ++) {
        if (objs[i].id == id) {
            return i;
        }
    }
    return -1;
}

hunt_object game_findtype(hunt_object *my_objects, int type)
{
    for (int i = 0; i < SPRITES_MAX; i ++) {
        if (my_objects[i].type == type) {
            return my_objects[i];
        }
    }
    return hunt_typeEMPTY;
}

void game_shakewindow(sfRenderWindow *window, int reset, hunt_object *objs)
{
    hunt_object win_obj = game_findtype(objs, 5);
    if (win_obj.type != 5) return;

    sfVector2i winpos;
    sfVector2f spritepos = sfSprite_getPosition(win_obj.sprite);
    if (reset == 1) {
        winpos = sfRenderWindow_getPosition(window);
        sfSprite_setPosition(win_obj.sprite, convert_vi_vf(winpos));
        return;
    } else if (reset == 2) {
        sfRenderWindow_setPosition(window, convert_vf_vi(spritepos));
        return;
    }
    winpos = convert_vf_vi(spritepos);
    winpos.x += rand() % 10;
    winpos.y += rand() % 10;
    sfRenderWindow_setPosition(window, winpos);
    return;
}

void game_show_array(hunt_object *my_objs, int show_empty)
{
    my_showstr("---[BEG]---\n");
    for (int i = 0; i < SPRITES_MAX; i ++) {
        if (show_empty || my_objs[i].type != -1) {
            my_showstr(my_objs[i].name);
            my_showstr("\n");
        }
    }
    my_showstr("---[END]---\n\n");
    return;
}
