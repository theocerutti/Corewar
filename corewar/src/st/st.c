/*
** EPITECH PROJECT, 2019
** st corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void push_ind(int index, unsigned char *memory, int *nb)
{
    char *integer = (char *)nb;

    for (int i = index, w = 3; i < index + 4; w--, i++) {
        if (i < MEM_SIZE)
            memory[i] = integer[w];
        else
            memory[i - MEM_SIZE] = integer[w];
    }
}

int check_param_st(int param[4])
{
    if (param[0] != 1 || (param[1] != 3 && param[1] != 1) \
    || param[2] != 0 || param[3] != 0)
        return (1);
    return (0);
}

int exec_st(player_t *player, data_t *data, unsigned char *n_mem, int *param)
{
    int move = 3;
    int index_1 = data->memory[player->program_counting + 2];
    int index_2 = data->memory[player->program_counting + 3];
    int new_index = 0;

    if (param[1] == 1) {
            player->registers[index_2 - 1] = player->registers[index_1 - 1];
            move += REG_SIZE;
    } else {
        new_index = player->program_counting + \
        get_ind(player->program_counting + 3, data->memory) % IDX_MOD;
        push_ind(new_index, n_mem, &player->registers[index_1 - 1]);
        move += IND_SIZE;
    }
    player->cycle_wait = op_tab[2].nbr_cycles;
    return (move);
}

int st(player_t *player, data_t *data, unsigned char *n_memory)
{
    int param[4] = {
    get_coding_byte(data->memory[player->program_counting + 1], 0),
    get_coding_byte(data->memory[player->program_counting + 1], 1),
    get_coding_byte(data->memory[player->program_counting + 1], 2),
    get_coding_byte(data->memory[player->program_counting + 1], 3)};

    if (check_param_st(param))
        return (1);
    return (exec_st(player, data, n_memory, param));
}