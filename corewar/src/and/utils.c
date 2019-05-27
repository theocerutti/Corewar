/*
** EPITECH PROJECT, 2019
** utils and
** File description:
** and other corewar
*/

#include "../../include/corewar.h"

int check_coding_byte_and(int param[4])
{
    if ((param[0] != 1 && param[0] != 2 && param[0] != 3) ||
    (param[1] != 1 && param[1] != 2 && param[1] != 3) ||
    (param[2] != 1) || param[3] != 0)
        return (1);
    return (0);
}

void and_or_xor_read(int to_read[3], int param[4], player_t *player)
{
    for (int i = 0; i < 3; i++) {
        if (param[i] == 1)
            to_read[i] = 1;
        if (param[i] == 2)
            to_read[i] = DIR_SIZE;
        if (param[i] == 3)
            to_read[i] = IND_SIZE;
    }
    modify_the_carry(player);
}

void fill_integer(int i, int w, unsigned char *integer, unsigned char *memory)
{
    if (i < MEM_SIZE)
        integer[w] = memory[i];
    else
        integer[w] = memory[i - MEM_SIZE];
}

void get_value_and(int size, int *value, unsigned char *memory, int *index)
{
    int i_end = 0;
    short s_end = 0;
    unsigned char *integer = malloc(size);

    if (size != 1) {
        for (int i = *index + size - 1, w = 0; i >= *index; w++, i--)
            fill_integer(i, w, integer, memory);
        if (size == 4) {
            i_end = *(int *)integer;
            *value = i_end;
        } else {
            s_end = *(short *)integer;
            *value = (int)s_end;
        }
    } else
        *value = memory[*index];
    *index += size;
    if (*index >= MEM_SIZE)
        *index -= MEM_SIZE;
}