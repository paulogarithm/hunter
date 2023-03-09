/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_strcat
*/
#include <stdlib.h>

int my_countstr(char *str);

char *my_strcat(char *src, char *add)
{
    int both_size = (my_countstr(src) + my_countstr(add));
    char *new_str = malloc(both_size) + sizeof(char);
    int src_n = 0;
    int add_n = 0;
    while (src[src_n] != '\0') {
        new_str[src_n] = src[src_n];
        src_n += 1;
    }
    while (add[add_n] != '\0') {
        new_str[src_n + add_n] = add[add_n];
        add_n += 1;
    }
    return new_str;
}
