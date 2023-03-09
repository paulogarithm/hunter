/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** hunter_loop
*/

#include "../include/hunter.h"

void game_clock(sfRenderWindow *window, sfClock *clock, hunt_object *my_objs);
void game_event(sfRenderWindow *window, sfEvent event, hunt_instances *inst);
void game_show_array(hunt_object *my_objs, int se);
void game_renderobj(sfRenderWindow *w, hunt_object *my_objs);
void game_check_levels(hunt_instances *inst);
void game_playmusic(char *file_path, int looped);
void game_end(hunt_instances *inst);
void game_clear_objs(hunt_instances *inst);
void game_clear(sfRenderWindow *window, sfClock *clock);
hunt_instances game_instance(void);

void game_display(sfRenderWindow *window, hunt_object *my_objects)
{
    sfColor color = sfColor_fromRGB(72, 140, 190);
    sfRenderWindow_clear(window, color);
    game_renderobj(window, my_objects);
    sfRenderWindow_display(window);
    return;
}

void game_mode(sfRenderWindow *window, hunt_instances *instances)
{
    if (instances->mode == 0) game_display(window, instances->menu);
    if (instances->mode == 1) game_display(window, instances->game);
    if (instances->mode == 2) game_display(window, instances->menu);
    return;
}

int game_loop(sfRenderWindow *window)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    game_playmusic("assets/sfx/music.ogg", 1);
    hunt_instances instances = game_instance();

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            game_event(window, event, &instances);
        }
        game_mode(window, &instances);
        game_check_levels(&instances);
        game_clock(window, clock, instances.game);
        game_clock(window, clock, instances.menu);
        game_end(&instances);
    }
    game_clear_objs(&instances);
    game_clear(window, clock);
    return 0;
}
