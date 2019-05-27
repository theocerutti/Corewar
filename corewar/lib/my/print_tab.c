/*
** EPITECH PROJECT, 2019
** print_tab
** File description:
** print_tab
*/

#include <stdio.h>
#include <stdlib.h>

int my_printf(char *str, ...);

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_printf("%s\n", tab[i]);
    }
}