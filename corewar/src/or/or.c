/*
** EPITECH PROJECT, 2019
** or corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void or_result(player_t *player, int rd_val[2][3])
{
    int val1 = 0;
    int val2 = 0;

    if (rd_val[0][0] != 1)
        val1 = rd_val[1][0];
    else
        val1 = player->registers[rd_val[1][0] - 1];
    if (rd_val[0][1] != 1)
        val2 = rd_val[1][1];
    else
        val2 = player->registers[rd_val[1][1] - 1];
    player->registers[rd_val[1][2] - 1] = val1 | val2;
}

int or(player_t *player, data_t *data, unsigned char *n_memory)
{
    int decal_index[2] = {2, player->program_counting + 2};
    int param[4] = {
    get_coding_byte(data->memory[player->program_counting + 1], 0),
    get_coding_byte(data->memory[player->program_counting + 1], 1),
    get_coding_byte(data->memory[player->program_counting + 1], 2),
    get_coding_byte(data->memory[player->program_counting + 1], 3)};
    int rd_vl[2][3] = {{0, 0, 0}, {0, 0, 0}};

    (void)n_memory;
    if (check_coding_byte_and(param) == 1) {
        return (1);
    } else
        and_or_xor_read(rd_vl[0], param, player);
    for (int i = 0; i < 3; i++) {
        get_value_and(rd_vl[0][i], &rd_vl[1][i], data->memory, &decal_index[1]);
        decal_index[0] += rd_vl[0][i];
    }
    player->cycle_wait = op_tab[6].nbr_cycles;
    or_result(player, rd_vl);
    return (decal_index[0]);
}