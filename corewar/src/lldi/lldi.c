/*
** EPITECH PROJECT, 2019
** lldi corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void get_index_lldi(int rd_val[2][3], player_t *player, int *index)
{
    if (rd_val[0][0] != 1)
        *index = player->program_counting + rd_val[1][0];
    else
        *index = player->program_counting + \
        player->registers[rd_val[1][0] - 1];
}

void do_lldi(int rd_val[2][3], data_t *data, player_t *player)
{
    int index = 0;
    unsigned char integer[2] = {0, 0};
    unsigned char int2[4] = {0};
    short value = 0;
    int sum = 0;

    get_index_lldi(rd_val, player, &index);
    for (int i = index + 1, w = 0; i >= index; i--, w++)
        fill_integer(i, w, integer, data->memory);
    value = *(short *)integer;
    if (rd_val[0][1] != 1)
        sum = (int)value + rd_val[1][1];
    else
        sum = (int)value + player->registers[rd_val[1][1] - 1];
    index = player->program_counting + sum;
    for (int i = index + 3, w = 0; i >= index; i--, w++)
        fill_integer(i, w, int2, data->memory);
    sum = *(int *)int2;
    player->registers[rd_val[1][2] - 1] = sum;
}

int lldi(player_t *player, data_t *data, unsigned char *n_memory)
{
    int decal_index[2] = {1, player->program_counting + 2};
    int param[4] = {get_coding_byte(data->memory[decal_index[1]], 0),
    get_coding_byte(data->memory[decal_index[1]], 1),
    get_coding_byte(data->memory[decal_index[1]], 2),
    get_coding_byte(data->memory[decal_index[1]], 3)};
    int rd_val[2][3] = {{0, 0, 0}, {0, 0, 0}};

    (void)n_memory;
    if (check_coding_byte_ldi(param) == 1)
        return (1);
    get_read_ldi(param, rd_val);
    for (int i = 0; i < 3; i++)
        get_value_ldi(rd_val, data, i, &decal_index[1]);
    modify_the_carry(player);
    do_lldi(rd_val, data, player);
    player->cycle_wait = op_tab[13].nbr_cycles;
    return (2 + rd_val[0][0] + rd_val[0][1] + rd_val[0][2]);
}