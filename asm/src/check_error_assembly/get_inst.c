/*
** EPITECH PROJECT, 2019
** get_inst
** File description:
** get_inst
*/

#include "asm.h"

char *get_next_inst(char *line, char *str, int idx)
{
    int check = 0;
    int size = 0;

    for (; line[idx] != '\0'; idx++)
        if (line[idx] != ' ' && line[idx] != '\t') {
            check = 1;
            break;
        }
    if (check == 0)
        return (NULL);
    for (int i = idx; line[i] != '\0'; i++)
        size++;
    str = malloc(sizeof(char) * (size + 1));
    for (int i = idx, j = 0; line[i] != '\0'; i++, j++)
        str[j] = line[i];
    str[size] = '\0';
    return (str);
}

char *label_and_inst(char *line, char *str)
{
    for (int i = 0; line[i] != '\0' && line[i] != ' ' && line[i] != '\t'; i++)
        if (line[i] == LABEL_CHAR)
            return (get_next_inst(line, str, i + 1));
    return (NULL);
}