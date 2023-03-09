/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_end
*/

#include "../include/hunter.h"

hunt_object game_findtype(hunt_object *my_objects, int type);
int my_countstr(char const *str);
int my_countnb(unsigned int nb);
int game_getindex_byid(hunt_object *objs, int id);
void game_setend(hunt_instances *inst);

char *my_addchar(char *str, char c)
{
    char *tmp = malloc(sizeof(char) * (my_countstr(str) + 2));
    int n = 0;
    while (str[n] != '\0') {
        tmp[n] = str[n];
        n += 1;
    }
    tmp[n] = c;
    tmp[n + 1] = '\0';
    return tmp;
}

char *my_nbtostr(int nb, char *text)
{
    char *str = text;
    if (nb == 0) {
        str = my_addchar(str, '0');
        return str;
    }
    for (int i = 0; i <= my_countnb(nb); i ++) {
        str = my_addchar(str, nb % 10 + '0');
        nb = nb / 10;
    }
    int i = 0;
    int j = my_countstr(str) - 1;
    while (j > i) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i ++;
        j --;
    }
    return str;
}

void game_setend(hunt_instances *inst)
{
    hunt_object tmp = game_findtype(inst->menu, 6);
    if (tmp.type == -1) return;

    int index = game_getindex_byid(inst->menu, tmp.id);
    hunt_object *object = &inst->menu[index];

    char *text = "Your level : ";
    char *str = my_nbtostr(inst->level, "");
    for (int i = 0; i < my_countstr(str); i++) {
        text = my_addchar(text, str[i]);
    }
    sfText_setString(object->text, text);
    sfVector2f pos = sfText_getPosition(object->text);
    pos.x = 75;
    sfText_setPosition(object->text, pos);
    return;
}

void game_end(hunt_instances *inst)
{
    hunt_object healthb = game_findtype(inst->game, 7);
    if (healthb.type < 0 && inst->mode != 2) {
        game_setend(inst);
        inst->mode = 2;
    }
    return;
}
