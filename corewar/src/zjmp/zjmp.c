/*
** EPITECH PROJECT, 2019
** zjmp corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

int zjmp(player_t *player, data_t *data, unsigned char *n_memory)
{
    short jump = 0;
    unsigned char integer[2];
    int index = player->program_counting + 1;

    (void)n_memory;
    if (player->carry == 1) {
        for (int i = index + 1, w = 0; i >= index; w++, i--) {
            if (i < MEM_SIZE)
                integer[w] = data->memory[i];
            else
                integer[w] = data->memory[i - MEM_SIZE];
        }
        jump = *(short *)integer;
        player->program_counting += jump % IDX_MOD;
        if (player->program_counting >= MEM_SIZE)
            player->program_counting -= MEM_SIZE;
        player->cycle_wait = op_tab[8].nbr_cycles;
    } else
        return (3);
    return (0);
}