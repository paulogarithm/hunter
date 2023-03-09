/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** my_comparestr
*/

int my_countstr(char *str);

int my_comparestr(char *str1, char *str2)
{
    if (my_countstr(str1) != my_countstr(str2)) return 0;

    int n = 0;
    while (str1[n] != '\0') {
        if (str1[n] != str2[n]) {
            return 0;
        }
        n += 1;
    }
    return 1;
}
