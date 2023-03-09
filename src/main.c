/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** main
*/

#include "../include/hunter.h"
#include "../include/statics.h"
#include "../include/functions.h"

void game_help(void)
{
    char *messages[] = {
        "\n- Hand Hunter -\n",
        "Hand hunter is a game for the My hunter Epitech's project.\n",
        "You embody a hand and your goal is to kill the monsters that\n",
        "wants to kill you.\n",
        "Sprites & code has been made by hands by Paul PARISOT\n\n",
        "click  -> summon hand\n",
        "escape -> leave game\n\n"
    };
    int len = (sizeof(messages) / sizeof(char *));

    for (int i = 0; i < len; i ++) {
        my_showstr(messages[i]);
    }
    return;
}

int game_usage(char *flag)
{
    char *accepted[] = {"-h", "-help", "-H", "help"};
    int len = (sizeof(accepted) / sizeof(char *));

    for (int i = 0; i < len; i ++) {
        if (my_comparestr(flag, accepted[i])) {
            game_help();
            return 1;
        }
    }
    return 0;
}

sfRenderWindow *create_window(void)
{
    char *name = "My Hunter";
    sfVector2i pos = {WIN_POS_X, WIN_POS_Y};
    sfRenderWindow *window;
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};

    window = sfRenderWindow_create(mode, name, sfClose, NULL);
    sfRenderWindow_setPosition(window, pos);
    return window;
}

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac == 2) {
        if (game_usage(av[1])) return 0;
    }
    sfRenderWindow *window = create_window();
    game_loop(window);
    return 0;
}
