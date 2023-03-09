/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_mouse
*/

#include "../include/hunter.h"
#include "../include/statics.h"
#include "../include/types.h"

void game_show_array(hunt_object *objs, int se);
hunt_object game_findtype(hunt_object *my_objects, int type);
hunt_object *game_obj_insert(hunt_object *objs, hunt_object obj, sfVector2f p);
void game_playmusic(char *file_path, int looped);
void game_shakewindow(sfRenderWindow *window, int reset, hunt_object *objs);

hunt_object detect_click(hunt_object obj, int x)
{
    int result = 0;
    sfVector2f obj_pos = sfSprite_getPosition(obj.sprite);
    int obj_x = obj_pos.x;

    if (x >= obj_x && x <= obj_x + (obj.size * GLOBAL_SCALE))
        result += 1;

    if (result >= 1 && (obj.type == 1 || obj.type == 6)) {
        return hunt_typeEMPTY;
    }
    return obj;
}

void detect_click_btn(hunt_object obj, hunt_instances *inst, int x, int y)
{
    int result = 0;
    sfVector2f txt_pos = sfText_getPosition(obj.text);
    int txt_x = txt_pos.x;
    int txt_y = txt_pos.y;

    if (x >= txt_x && x <= txt_x + (obj.size * GLOBAL_SCALE))
        result += 1;
    if (y >= txt_y && y <= txt_y + (obj.size * GLOBAL_SCALE))
        result += 1;

    if (result >= 2) {
        inst->mode = 1;
    }
    return;
}

int mouse_loops(hunt_instances *inst, hunt_object hand, int x, int y)
{
    int size = SPRITES_MAX;
    int nb = 0;
    hunt_object *folder;

    if (inst->mode) {
        folder = inst->game;
    } else {
        folder = inst->menu;
        nb = 1;
    }

    for (int i = 0; i < size; i ++) {
        hunt_object obj = folder[i];
        if (hand.type == 3 && inst->mode) break;
        if (obj.type >= 0 && inst->mode) folder[i] = detect_click(obj, x);
        if (obj.type >= 0 && !inst->mode) detect_click_btn(obj, inst, x, y);
    }
    return nb;
}

void game_mouse(sfRenderWindow *window, sfEvent event, hunt_instances *inst)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    game_shakewindow(window, 1, inst->game);
    hunt_object hand = game_findtype(inst->game, 3);
    if (mouse_loops(inst, hand, x, y)) return;

    if (hand.type != 3 && inst->mode == 1) {
        sfVector2f pos;
        sfIntRect rect = {0, 0, hunt_typeHAND.size, 0};
        pos.x = (x - hunt_typeHAND.size * GLOBAL_SCALE / 2);
        pos.y = HAND_POS;
        game_obj_insert(inst->game, hunt_typeHAND, pos);
        hand = game_findtype(inst->game, 3);
        if (hand.type == 3) sfSprite_setTextureRect(hand.sprite, rect);
        game_playmusic("assets/sfx/explosion.ogg", 0);
    }
}
