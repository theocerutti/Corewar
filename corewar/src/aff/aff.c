/*
** EPITECH PROJECT, 2019
** aff corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

int aff(player_t *player, data_t *data, unsigned char *n_memory)
{
    (void)n_memory;
    my_printf("%c\n", \
    player->registers[data->memory[player->program_counting + 1] - 1] % 256);
    return (2);
}