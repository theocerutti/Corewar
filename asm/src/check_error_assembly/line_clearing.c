/*
** EPITECH PROJECT, 2019
** line_clearing
** File description:
** line_clearing
*/

#include "asm.h"

char *clear_comma(char *str)
{
    char *copy = malloc(sizeof(char) * my_strlen(str));

    for (int i = 1, j = 0; str[i] != '\0'; i++, j++)
        copy[j] = str[i];
    copy[my_strlen(str) - 1] = '\0';
    free(str);
    str = malloc(sizeof(char) * (my_strlen(copy) + 1));
    str = my_strcpy(str, copy);
    return (str);
}

char *clear_spaces_after(char *str, int size, int index)
{
    char *copy = NULL;

    for (int i = size; i >= 0; i--)
        if (str[i] != ' ' && str[i] != '\t') {
            index = i + 1;
            break;
        }
    copy = malloc(sizeof(char) * (index + 1));
    for (int i = 0; i <= index; i++)
        copy[i] = str[i];
    copy[index] = '\0';
    free(str);
    str = malloc(sizeof(char) * (index + 1));
    for (int i = 0; copy[i] != '\0'; i++)
        str[i] = copy[i];
    str[index] = '\0';
    return (str);
}

char *clear_spaces(char *str, int size, int index)
{
    char *copy = NULL;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ' && str[i] != '\t') {
            index = i;
            break;
        }
    copy = malloc(sizeof(char) * (size - index + 1));
    for (int i = index, j = 0; str[i] != '\0'; i++, j++) {
        copy[j] = str[i];
    }
    copy[size - index] = '\0';
    str = malloc(sizeof(char) * (size - index + 1));
    for (int i = 0; copy[i] != '\0'; i++)
        str[i] = copy[i];
    str[size - index] = '\0';
    str = clear_spaces_after(str, my_strlen(str) - 1, 0);
    return (str);
}