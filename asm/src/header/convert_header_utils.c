/*
** EPITECH PROJECT, 2019
** convert_header
** File description:
** convert_header
*/

#include "asm.h"

char *my_strcpy_special(char *dest, char *src)
{
    int idx = 0;
    int j = 0;

    if (src == NULL)
        return (NULL);
    for (; src[idx] != '"'; idx++);
    idx++;
    for (int i = idx; src[i] != '"'; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}

int is_variable(char *str, char *op)
{
    int g = 0;
    int idx = 0;

    for (; str[idx] != '\0'; idx++)
        if (str[idx] != '\t' && str[idx] != ' ')
            break;
    for (int i = 0, j = idx; op[i] != '\0'; i++, j++)
        if (str[j] != op[i])
            return (1);
    for (int i = my_strlen(op) + idx; str[i] != '\0'; i++)
        if (str[i] == '"')
            g++;
    if (g != 2)
        return (1);
    return (0);
}

int is_empty_line(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ' && str[i] != '\t')
            return (1);
    return (0);
}