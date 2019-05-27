/*
** EPITECH PROJECT, 2019
** my_tab_to_str.c
** File description:
** transform tab to str
*/

#include <stdio.h>
#include <stdlib.h>

char *my_tab_to_str(char **tab, char *separator)
{
    int index_str = 0;
    char *str = NULL;

    if (tab == NULL)
        return (str);
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++, index_str++);
        for (int h = 0; separator[h] != '\0'; h++, index_str++);
    }
    str = malloc(sizeof(char) * (index_str + 1));
    index_str = 0;
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++, index_str++) {
            str[index_str] = tab[i][j];
        }
        for (int h = 0; separator[h] != '\0'; h++, index_str++)
            str[index_str] = separator[h];
    }
    str[index_str - 1] = '\0';
    return (str);
}
