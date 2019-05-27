/*
** EPITECH PROJECT, 2019
** add corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

int error_memory_add(int to_read[3], data_t *data, player_t *player)
{
    for (int i = 0, w = 1; i < 3; i++, w++) {
        if (to_read[i] != 1) {
            return (1);
        } else if (data->memory[player->program_counting + 1 + w] - 1 < 0 || \
        data->memory[player->program_counting + 1 + w] - 1 >= REG_NUMBER) {
            return (1);
        }
    }
    return (0);
}

int add(player_t *player, data_t *data, unsigned char *n_memory)
{
    int decal = 4;
    int to_read[3] = {
        get_coding_byte(data->memory[player->program_counting + 1], 0),
        get_coding_byte(data->memory[player->program_counting + 1], 1),
        get_coding_byte(data->memory[player->program_counting + 1], 2)
    };

    (void)n_memory;
    if (error_memory_add(to_read, data, player) == 1)
        return (1);
    player->registers[data->memory[player->program_counting + 1 + 3] - 1] = \
    player->registers[data->memory[player->program_counting + 1 + 1] - 1] + \
    player->registers[data->memory[player->program_counting + 1 + 2] - 1];
    player->cycle_wait = op_tab[3].nbr_cycles;
    return (decal);
}