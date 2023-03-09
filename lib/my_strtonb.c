/*
** EPITECH PROJECT, 2022
** my string to number
** File description:
** jahaiu
*/

int my_strtonb(char const *str, int nb)
{
    int final = 0;
    while (str[nb] >= '0' && str[nb] <= '9') {
        final = final * 10;
        final += str[nb] - '0';
        nb += 1;
    }
    return final;
}
