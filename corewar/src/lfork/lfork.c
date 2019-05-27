/*
** EPITECH PROJECT, 2019
** lfork corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

int lfork(player_t *player, data_t *data, unsigned char *n_memory)
{
    unsigned char val[2] = {'\0'};

    (void)n_memory;
    val[0] = data->memory[player->program_counting + 2];
    val[1] = data->memory[player->program_counting + 1];
    player->cycle_wait = op_tab[11].nbr_cycles;
    copy_player_add(data, player, player->program_counting + *(short *)val);
    return (3);
}