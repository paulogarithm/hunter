/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_rendersprite
*/

#include "../include/hunter.h"

void my_swap(hunt_object *xp, hunt_object *yp)
{
    hunt_object temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void get_min(hunt_object *my_objects, int j, int *min_idx)
{
    hunt_object a = my_objects[j];
    hunt_object b = my_objects[*min_idx];
    if (a.type < 0 || b.type < 0) return;

    sfVector2f apos = sfSprite_getPosition(a.sprite);
    sfVector2f bpos = sfSprite_getPosition(b.sprite);
    if (apos.y * a.priority < bpos.y * b.priority) *min_idx = j;
    return;
}

void my_sort(hunt_object *my_objects, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i ++) {
        min_idx = i;
        for (j = i + 1; j < n; j ++) {
            get_min(my_objects, j, &min_idx);
        }
        if (min_idx != i) my_swap(&my_objects[min_idx], &my_objects[i]);
    }
}

void game_renderobj(sfRenderWindow *window, hunt_object *my_objects)
{
    my_sort(my_objects, SPRITES_MAX);
    for (int i = 0; i < SPRITES_MAX; i ++) {
        if (my_objects[i].type != -1) {
            sfRenderWindow_drawSprite(window, my_objects[i].sprite, NULL);
        }
        if (my_objects[i].text != NULL) {
            sfRenderWindow_drawText(window, my_objects[i].text, NULL);
        }
    }
}
