/*
** EPITECH PROJECT, 2019
** write_utils
** File description:
** write_utils
*/

#include "asm.h"

char **get_just_param_corewar(char *str, int begin_code_line)
{
    int size = 0;
    char **tab = get_args_corewar(clear_spaces(str, my_strlen(str), 0));
    char **ret = NULL;
    int z = 0;

    for (size = 0; tab[size] != NULL; size++);
    ret = malloc(sizeof(char *) * (size + 1));
    for (int i = begin_code_line + 1; i < size; i++, z++) {
        ret[z] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
        my_strcpy(ret[z], tab[i]);
    }
    ret[z] = NULL;
    return (ret);
}

int get_nbr_param(char const *str, int off)
{
    int code = 0;
    char *s = malloc(sizeof(char) * (my_strlen(str) + 1));

    my_strcpy(s, str);
    s += off;
    code = my_atoi(s);
    return (code);
}

void reverse_byte(unsigned char *s, int size)
{
    int i = 0;
    int j = 0;
    char stock = 0;
    int size2 = size;

    for (i = size; i > size2 / 2; i--) {
        stock = s[j];
        s[j] = s[size - 1];
        s[size - 1] = stock;
        j += 1;
        size -= 1;
    }
}