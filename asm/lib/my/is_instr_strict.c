/*
** EPITECH PROJECT, 2019
** is_instr_strict
** File description:
** parse
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *);

int is_instr_strict(char *s1, char *s2)
{
    int j = 0;
    int same = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[j]) {
            j += 1;
            same += 1;
        } else {
            j = 0;
            same = 0;
        }
        if (same == my_strlen(s2))
            return (1);
    }
    return (0);
}
