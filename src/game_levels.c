/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_levels
*/

#include "../include/hunter.h"
#include "../include/types.h"

hunt_object *game_obj_insert(hunt_object *objs, hunt_object obj, sfVector2f p);
hunt_object game_findtype(hunt_object *my_objects, int type);

void game_check_levels(hunt_instances *inst)
{
    if (!inst->mode) return;
    int *level = &inst->level;
    hunt_object ennemy = game_findtype(inst->game, 1);
    hunt_object hand = game_findtype(inst->game, 3);
    if (hand.type == 3) return;
    if (ennemy.type != 1) {
        for (int i = 0; i < (*level / 3) + 1; i ++) {
            sfVector2f pos;
            pos.x = .1 * WIN_WIDTH + rand() % ((int) (0.6 * WIN_WIDTH)) ;
            pos.y = HAND_POS - hunt_typeENNEMY.size * GLOBAL_SCALE;
            pos.y += rand() % 15;
            game_obj_insert(inst->game, hunt_typeENNEMY, pos);
        }
        *level += 1;
    }
    return;
}
