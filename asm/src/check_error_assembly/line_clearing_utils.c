/*
** EPITECH PROJECT, 2019
** line_clearing_utils
** File description:
** line_clearing_utils
*/

#include "asm.h"

int str_begin(char *str, char *check)
{
    int i = 0;

    for (; check[i] != '\0'; i++)
        if (str[i] != check[i])
            return (1);
    if (str[i] != ' ' && str[i] != '\t')
        return (1);
    return (0);
}

char *get_line_instruction(char *str)
{
    for (int i = 0; i < 16; i++)
        if (str_begin(str, op_tab[i].mnemonique) == 0)
            return (op_tab[i].mnemonique);
    return (NULL);
}

int get_reg(char *str, int res, int i, int size_nbr)
{
    int size = my_strlen(str);
    int sign = 1;

    if (size == 0)
        return (0);
    while ((str[i] < '0' || str[i] > '9') && str[i] != '-'
    && str[i] != '+')
        i++;
    for (; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (; i < size; i++, size_nbr++) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + (str[i] - '0');
        } else
            break;
    }
    return (res * sign);
}