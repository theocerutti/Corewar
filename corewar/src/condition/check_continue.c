/*
** EPITECH PROJECT, 2019
** check continue functions
** File description:
** corewar
*/

#include "../../include/corewar.h"

int is_alive(data_t *data, int index)
{
    int nb = data->player[index].arg.prog_number;

    for (int i = 0; i < data->nb_players; i++) {
        if (data->player[i].arg.prog_number == nb && \
        data->player[i].alive == 1)
            return (1);
    }
    return (0);
}

int is_more_than_one_player_alive(data_t *data)
{
    int win = 0;

    for (int i = 0, alive = 0; i < data->nb_player_origin; i++) {
        if (is_alive(data, i)) {
            alive += 1;
            win = i;
        }
        if (alive > 1)
            return (1);
    }
    my_printf("The winner is the prog : %d(%s)\n", \
    data->player[win].arg.prog_number, get_name_cor(data->player[win].name));
    return (0);
}