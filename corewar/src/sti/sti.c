/*
** EPITECH PROJECT, 2019
** sti corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

int check_coding_byte_sti(int param[4])
{
    if ((param[0] != 1) || (param[1] != 1 && param[1] != 2 && param[1] != 3) \
    || (param[2] != 2 && param[2] != 1) || (param[3] != 0))
        return (1);
    return (0);
}

void set_sti_read(int read[3], int param[4])
{
    for (int i = 0; i < 3; i++) {
        if (param[i] == 1)
            read[i] = 1;
        if (param[i] == 2 || param[i] == 3)
            read[i] = 2;
    }
}

void get_value_sti(int i, unsigned char *memory, \
int rd_val[2][3], int *index)
{
    short id_value = 0;
    unsigned char integer[2] = {0, 0};

    if (rd_val[0][i] != 1) {
        for (int j = *index + rd_val[0][i] - 1, w = 0; j > *index; w++, j--)
            fill_integer(j, w, integer, memory);
        if (rd_val[0][i] == 2) {
            id_value = *(short *)integer;
            rd_val[1][i] = (int)id_value;
        }
    } else
        rd_val[1][i] = memory[*index];
    *index += rd_val[0][i];
    if (*index >= MEM_SIZE)
        *index -= MEM_SIZE;
}

void mod_memory_sti(unsigned char *memory, int rd_val[2][3], player_t *player)
{
    int index = player->program_counting;
    int sum = 0;

    for (int i = 1; i < 3; i++) {
        if (rd_val[0][i] != 1)
            sum += rd_val[1][i];
        else
            sum += player->registers[rd_val[1][i] - 1];
    }
    sum %= IDX_MOD;
    index += sum;
    push_ind(index, memory, &player->registers[rd_val[1][0] - 1]);
}

int sti(player_t *player, data_t *data, unsigned char *n_memory)
{
    int decal_index[2] = {2, player->program_counting + 2};
    int rd_val[2][3] = {{0, 0, 0}, {0, 0, 0}};
    int param[4] = {
    get_coding_byte(data->memory[player->program_counting + 1], 0),
    get_coding_byte(data->memory[player->program_counting + 1], 1),
    get_coding_byte(data->memory[player->program_counting + 1], 2),
    get_coding_byte(data->memory[player->program_counting + 1], 3)};

    if (check_coding_byte_sti(param)) {
        return (1);
    } else
        set_sti_read(rd_val[0], param);
    for (int i = 0; i < 3; i++)
        get_value_sti(i, data->memory, rd_val, &decal_index[1]);
    mod_memory_sti(n_memory, rd_val, player);
    player->cycle_wait = op_tab[10].nbr_cycles;
    return (2 + rd_val[0][0] + rd_val[0][1] + rd_val[0][2]);
}