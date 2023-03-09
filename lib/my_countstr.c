/*
** EPITECH PROJECT, 2022
** aaa
** File description:
** aa
*/

int my_countstr(char const *str)
{
    int nb = 0;
    while (str[nb] != '\0') {
        nb += 1;
    }
    return nb;
}
