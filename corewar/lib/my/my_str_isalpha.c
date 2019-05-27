/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** Day06 - task0??
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int count_same = 0;
    int len = 0;
    char s;

    for (i = 0; str[i] != '\0'; i++) {
        len += 1;
        s = str[i];
        if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
            count_same += 1;
    }
    if (count_same == len || len == 0)
        return (1);
    else
        return (0);
}
