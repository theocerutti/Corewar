/*
** EPITECH PROJECT, 2019
** is_in
** File description:
** parse
*/

#include <stdio.h>
#include <stdlib.h>

char is_in(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (c);
    }
    return (0);
}