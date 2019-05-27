/*
** EPITECH PROJECT, 2019
** lld corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void get_value_lld(int index, int to_read[2], unsigned char *integer, \
data_t *data)
{
    for (int i = index + to_read[0] - 1, w = 0; i >= index; w++, i--) {
        if (i < MEM_SIZE)
            integer[w] = data->memory[i];
        else
            integer[w] = data->memory[i - MEM_SIZE];
    }
}

void get_memory_lld(player_t *player, unsigned char *integer, data_t *data)
{
    int pos = player->program_counting + *(int *)integer;

    if (pos >= MEM_SIZE)
        pos -= MEM_SIZE;
    for (int i = pos + 3, w = 0; i >= pos; w++, i--) {
        if (i < MEM_SIZE)
            integer[w] = data->memory[i];
        else
            integer[w] = data->memory[i - MEM_SIZE];
    }
}

void get_info_param_lld(unsigned char param, int to_read[2], int *decal)
{
    if (param == 2)
        to_read[0] = DIR_SIZE;
    else if (param == 3)
        to_read[0] = IND_SIZE;
    *decal += to_read[0];
}

int lld(player_t *player, data_t *data, unsigned char *n_memory)
{
    int decal = 2;
    int to_read[] = {0, REG_SIZE};
    unsigned char param = \
    get_coding_byte(data->memory[player->program_counting + 1], 0);
    unsigned char *integer = NULL;
    int index = player->program_counting + 2;

    (void)n_memory;
    get_info_param_lld(param, to_read, &decal);
    integer = malloc(sizeof(unsigned char) * to_read[0]);
    modify_the_carry(player);
    get_value_lld(index, to_read, integer, data);
    if (to_read[0] == IND_SIZE || to_read[0] == DIR_SIZE)
        get_memory_lld(player, integer, data);
    if (data->memory[index + to_read[0]] > 0 && \
    data->memory[index + to_read[0]] <= REG_NUMBER)
        player->registers[data->memory[index + to_read[0]] - 1] \
        = *(int *)integer;
    player->cycle_wait = op_tab[9].nbr_cycles;
    return (decal);
}