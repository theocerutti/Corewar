/*
** EPITECH PROJECT, 2019
** fork corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void copy_player_add(data_t *data, player_t *player, short pos)
{
    player_t new_player;
    player_t *player_tab = malloc(sizeof(player_t) * (data->nb_players + 2));

    new_player.alive = player->alive;
    new_player.live = player->live;
    new_player.arg = player->arg;
    new_player.carry = player->carry;
    new_player.cycle_wait = player->cycle_wait;
    new_player.name = player->name;
    new_player.program_counting = pos;
    for (int i = 0; i < 16; i++)
        new_player.registers[i] = player->registers[i];
    for (int i = 0; i < data->nb_players; i++)
        player_tab[i] = data->player[i];
    player_tab[data->nb_players] = new_player;
    data->player = player_tab;
    data->nb_players += 1;
}

int fork_vm(player_t *player, data_t *data, unsigned char *n_memory)
{
    unsigned char val[2] = {'\0'};

    (void)n_memory;
    val[0] = data->memory[player->program_counting + 2];
    val[1] = data->memory[player->program_counting + 1];
    player->cycle_wait = op_tab[11].nbr_cycles;
    copy_player_add(data, player, player->program_counting + *(short *)val \
    % IDX_MOD);
    return (3);
}