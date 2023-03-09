/*
** EPITECH PROJECT, 2022
** my char to str
** File description:
** idk
*/
#include <stdlib.h>

char *my_chartostr(char c)
{
    char *hey = malloc(sizeof(char) * 2);
    hey[0] = c;
    return hey;
}
