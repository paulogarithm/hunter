/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** game_convert
*/

#include "../include/hunter.h"


sfVector2i convert_vf_vi(sfVector2f vectorf)
{
    sfVector2i vectori;
    vectori.x = (int) vectorf.x;
    vectori.y = (int) vectorf.y;
    return vectori;
}

sfVector2f convert_vi_vf(sfVector2i vectori)
{
    sfVector2f vectorf;
    vectorf.x = (float) vectori.x;
    vectorf.y = (float) vectori.y;
    return vectorf;
}
