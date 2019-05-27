/*
** EPITECH PROJECT, 2019
** PROG
** File description:
** PROG
*/

#include "include/corewar.h"

#define HELP "USAGE\n\
        ./corewar [-dump nbr_cycle] [[-n prog_number] \
[-a load_address] prog_name] ...\n\n\
DESCRIPTION\n\
        -dump nbr_cycle dumps the memory after \
the nbr_cycle execution (if the round isn’t\n\
                        already over) with the following format: \
32 bytes/line in\n\
                        hexadecimal (A0BCDEFE1DD3...)\n\
        -n prog_number sets the next program’s number. \
By default, the first free number\n\
                        in the parameter order\n\
        -a load_address sets the next program’s loading address. \
When no address is\n\
                        specified, optimize the addresses so \
that the processes are as far\n\
                        away from each other as possible. \
The addresses are MEM_SIZE modulo.\n"

static const get_funct_t redirect[] =
{
    {1, &live},
    {2, &ld},
    {3, &st},
    {4, &add},
    {5, &sub},
    {6, &and},
    {7, &or},
    {8, &xor},
    {9, &zjmp},
    {10, &ldi},
    {11, &sti},
    {12, &fork_vm},
    {13, &lld},
    {14, &lldi},
    {15, &lfork},
    {16, &aff},
    {-1, NULL}
};

void play_turn_palyer(player_t *player, data_t *data, unsigned char *n_memory)
{
    char cmd;
    int move = 0;
    int is_function = 0;

    cmd = data->memory[player->program_counting];
    for (int i = 0; redirect[i].function != -1; i++) {
        if (cmd == redirect[i].function) {
            move = redirect[i].ptr(player, data, n_memory);
            is_function = 1;
            break;
        }
    }
    if (is_function == 0)
        move = 1;
    player->program_counting += move;
    if (player->program_counting >= MEM_SIZE)
        player->program_counting -= MEM_SIZE;
}

void turn_life(data_t *data)
{
    if (data->cycle_die > data->cycle_to_die) {
        for (int i = 0; i < data->nb_players; i++) {
            if (data->player[i].live == 0)
                data->player[i].alive = 0;
        }
        for (int i = 0; i < data->nb_players; i++) {
            data->player[i].live = 0;
        }
        data->cycle_die = 0;
    } else {
        data->cycle_die++;
    }
}

void game_loop(data_t *data)
{
    unsigned char new_memory[MEM_SIZE];

    while (is_more_than_one_player_alive(data) == 1) {
        if (data->total_cycle >= data->nbr_cycle && data->nbr_cycle != -1) {
            dump_memory(data->memory);
            return;
        }
        data->total_cycle += 1;
        for (int i = 0; i < MEM_SIZE; i++)
            new_memory[i] = data->memory[i];
        for (int i = 0; i < data->nb_players; i++) {
            if (data->player[i].cycle_wait == 0 && data->player[i].alive) {
                play_turn_palyer(&data->player[i], data, new_memory);
            } else if (data->player[i].cycle_wait > 0)
                data->player[i].cycle_wait -= 1;
        }
        for (int i = 0; i < MEM_SIZE; i++)
            data->memory[i] = new_memory[i];
        turn_life(data);
    }
}

int main(int ac, char **av)
{
    data_t data;

    data.nb_live = 0;
    data.cycle_to_die = CYCLE_TO_DIE;
    data.cycle_die = 0;
    data.total_cycle = 0;
    if (av[1] != NULL && !my_strcmp(av[1], "-h")) {
        my_printf("%s", HELP);
        return (0);
    }
    if (check_error(av, ac) == 84)
        return (84);
    get_arg(ac, av, &data);
    set_players(&data);
    game_loop(&data);
    return (0);
}