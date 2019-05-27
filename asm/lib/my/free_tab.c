/*
** EPITECH PROJECT, 2019
** free_tab
** File description:
** free_tab
*/

#include <stdio.h>
#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}