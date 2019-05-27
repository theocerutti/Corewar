/*
** EPITECH PROJECT, 2019
** get_size_tab
** File description:
** get_size_tab
*/

#include <stdlib.h>

int get_size_tab(char **tab)
{
    int len = 0;

    for (len = 0; tab[len] != NULL; len++);
    return (len);
}