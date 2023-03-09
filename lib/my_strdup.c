/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_countstr(char *str);

char *my_strdup(char *str)
{
    char *final = malloc(my_countstr(str) * sizeof(char));
    int n = 0;
    while (str[n] != '\0') {
        final[n] = str[n];
        n += 1;
    }
    return final;
}
