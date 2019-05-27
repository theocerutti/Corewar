/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** task05
*/

int my_strlen(char const *);

int my_getnbr(char *str)
{
    int size = my_strlen(str);
    long res = 0;
    int sign = 1;
    int i = 0;
    int size_nbr = 0;

    if (size == 0)
        return (0);
    for (; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            sign *= (-1);
    for (; i < size; i++, size_nbr++) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + (str[i] - 48);
        } else
            break;
    }
    return (res * sign);
}