/*
** EPITECH PROJECT, 2019
** utility corewar
** File description:
** corewar
*/

#include "../include/corewar.h"

int get_ind(int index, unsigned char *memory)
{
    char integer[2] = {'\0'};

    for (int i = index + 1, w = 0; i >= index; w++, i--) {
        if (i < MEM_SIZE)
            integer[w] = memory[i];
        else
            integer[w] = memory[i - MEM_SIZE];
    }
    return (*(int *)integer);
}

int get_dir(int index, unsigned char *memory)
{
    char integer[4] = {'\0'};

    for (int i = index + 3, w = 0; i >= index; w++, i--) {
        if (i < MEM_SIZE)
            integer[w] = memory[i];
        else
            integer[w] = memory[i - MEM_SIZE];
    }
    return (*(int *)integer);
}