/*
** EPITECH PROJECT, 2019
** check_error_assembly
** File description:
** check_error_assembly
*/

#include "asm.h"

void my_double_realloc(char ***str, int size)
{
    char **copy = malloc(sizeof(char *) * (size));

    for (int i = 0; str[0][i] != NULL; i++)
        copy[i] = malloc(sizeof(char) * (my_strlen(str[0][i]) + 1));
    my_strcpy_tab(copy, str[0]);
    copy[size - 1] = NULL;
    for (int i = 0; str[0][i] != NULL; i++)
        free(str[0][i]);
    free(str[0]);
    str[0] = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; copy[i] != NULL; i++)
        str[0][i] = malloc(sizeof(char) * (my_strlen(copy[i]) + 1));
    my_strcpy_tab(str[0], copy);
    str[0][size] = NULL;
    for (int i = 0; copy[i] != NULL; i++)
        free(copy[i]);
    free(copy);
}