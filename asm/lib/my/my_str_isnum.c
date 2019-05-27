/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** Day06 - task0??
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}
