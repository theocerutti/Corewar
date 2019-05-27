/*
** EPITECH PROJECT, 2019
** ldi corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

int check_coding_byte_ldi(int param[4])
{
    if ((param[0] != 1 && param[0] != 2 && param[0] != 3) || \
    (param[1] != 1 && param[1] != 2) || (param[2] != 1) || (param[3] != 0))
        return (1);
    return (0);
}

void get_read_ldi(int param[4], int rd_val[2][3])
{
    for (int i = 0; i < 3; i++) {
        if (param[i] == 1)
            rd_val[0][i] = 1;
        if (param[i] == 3 || param[i] == 2)
            rd_val[0][i] = 2;
    }
}

void get_value_ldi(int rd_val[2][3], data_t *data, int i, int *index)
{
    short id_value = 0;
    unsigned char integer[2] = {0, 0};

    if (rd_val[0][i] != 1) {
        for (int j = *index + rd_val[0][i] - 1, w = 0; j >= *index; w++, j--)
            fill_integer(j, w, integer, data->memory);
        if (rd_val[0][i] == 2) {
            id_value = *(short *)integer;
            rd_val[1][i] = (int)id_value;
        }
    } else
        rd_val[1][i] = data->memory[*index];
    *index += rd_val[0][i];
    if (*index >= MEM_SIZE)
        *index -= MEM_SIZE;
}

void do_ldi(int rd_val[2][3], data_t *data, player_t *player)
{
    int index = 0;
    unsigned char integer[2] = {0, 0};
    unsigned char int2[4] = {0};
    short value = 0;
    int sum = 0;

    get_index_ldi(rd_val, player, &index);
    for (int i = index + 1, w = 0; i >= index; i--, w++)
        fill_integer(i, w, integer, data->memory);
    value = *(short *)integer;
    if (rd_val[0][1] != 1)
        sum = (int)value + rd_val[1][1];
    else
        sum = (int)value + player->registers[rd_val[1][1] - 1];
    index = player->program_counting + sum % IDX_MOD;
    for (int i = index + 3, w = 0; i >= index; i--, w++)
        fill_integer(i, w, int2, data->memory);
    sum = *(int *)int2;
    player->registers[rd_val[1][2] - 1] = sum;
}

int ldi(player_t *player, data_t *data, unsigned char *n_memory)
{
    int decal_index[2] = {1, player->program_counting + 2};
    int param[4] = {get_coding_byte(data->memory[decal_index[1] - 1], 0), \
    get_coding_byte(data->memory[decal_index[1] - 1], 1), \
    get_coding_byte(data->memory[decal_index[1] - 1], 2), \
    get_coding_byte(data->memory[decal_index[1] - 1], 3)};
    int rd_val[2][3] = {{0, 0, 0}, {0, 0, 0}};

    (void)n_memory;
    if (check_coding_byte_ldi(param) == 1)
        return (1);
    get_read_ldi(param, rd_val);
    for (int i = 0; i < 3; i++)
        get_value_ldi(rd_val, data, i, &decal_index[1]);
    modify_the_carry(player);
    do_ldi(rd_val, data, player);
    player->cycle_wait = op_tab[9].nbr_cycles;
    return (2 + rd_val[0][0] + rd_val[0][1] + rd_val[0][2]);
}