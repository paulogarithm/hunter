/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_music
*/
#include "../include/hunter.h"

void game_playmusic(char *file_path, int looped)
{
    sfMusic *music;
    music = sfMusic_createFromFile(file_path);
    if (!music) return;
    if (looped) sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
}
