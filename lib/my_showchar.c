/*
** EPITECH PROJECT, 2022
** Boot_bsq
** File description:
** my_showchar
*/

#include <unistd.h>

void my_showchar(char c)
{
    write(1, &c, 1);
}
