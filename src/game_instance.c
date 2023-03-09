/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_instance
*/

#include "../include/hunter.h"
#include "../include/types.h"
#include "../include/statics.h"

hunt_object *game_obj(void);
int my_countstr(char *str);

hunt_object game_menunew(hunt_object pattern, sfVector2f position)
{
    hunt_object my_object = pattern;
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfText *text = sfText_create();
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(my_object.texture, NULL);
    sfVector2f scale = {GLOBAL_SCALE, GLOBAL_SCALE};
    my_object.sprite = sprite;
    my_object.clock = sfClock_create();
    my_object.id = rand();
    my_object.text = text;
    my_object.speed = (rand() % 10) + 10;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(my_object.sprite, scale);
    sfSprite_setPosition(my_object.sprite, position);
    sfText_setPosition(my_object.text, position);
    if (my_object.type == 6) sfText_setString(text, my_object.name);
    sfText_setFont(text, font);
    sfText_setScale(text, scale);

    return my_object;
}

hunt_object *game_menuinsert(hunt_object *objs, hunt_object pat, sfVector2f p)
{
    pat = game_menunew(pat, p);
    for (int i = 0; i < SPRITES_MAX; i ++) {
        if (objs[i].type < 0) {
            objs[i] = pat;
            break;
        }
    }
    return objs;
}

hunt_object *game_menu(void)
{
    hunt_object *menu = malloc(sizeof(hunt_object) * SPRITES_MAX);
    for (int i = 0; i < SPRITES_MAX; i ++) {
        menu[i] = hunt_typeEMPTY;
    }

    sfVector2f pos = {WIN_WIDTH / 2 - 64 * GLOBAL_SCALE / 2, 200};
    game_menuinsert(menu, hunt_typePLAYBTN, pos);
    pos = (sfVector2f) {100, 50};
    game_menuinsert(menu, hunt_typeCLOUD, pos);
    return menu;
}

hunt_instances game_instance(void)
{
    hunt_instances instances;
    instances.game = game_obj();
    instances.menu = game_menu();
    instances.mode = 0;
    instances.level = 0;
    return instances;
}
