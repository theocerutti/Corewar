/*
** EPITECH PROJECT, 2019
** ldi utils
** File description:
** corewar
*/

#include "../../include/corewar.h"

void get_index_ldi(int rd_val[2][3], player_t *player, int *index)
{
    if (rd_val[0][0] != 1)
        *index = player->program_counting + rd_val[1][0] % IDX_MOD;
    else
        *index = player->program_counting + \
        player->registers[rd_val[1][0] - 1] % IDX_MOD;
}