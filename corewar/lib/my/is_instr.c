/*
** EPITECH PROJECT, 2019
** is_instr
** File description:
** parse
*/

#include <stdio.h>
#include <stdlib.h>

char is_instr(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return (s1[i]);
            }
        }
    }
    return (0);
}