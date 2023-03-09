/*
** EPITECH PROJECT, 2022
** haha
** File description:
** hoho
*/

int my_countnb(unsigned int nb)
{
    int dgts = 0;
    while (nb > 0) {
        nb = nb - (nb % 10);
        nb = nb / 10;
        dgts += 1;
    }
    return dgts;
}
