/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** my_showstr
*/

void my_showchar(char c);

void my_showstr(char const *str)
{
    int nb = 0;
    while (str[nb] != '\0') {
        my_showchar(str[nb]);
        nb += 1;
    }
}
