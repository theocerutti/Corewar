/*
** EPITECH PROJECT, 2019
** set player
** File description:
** corewar
*/

#include "../../include/corewar.h"

void set_registers(data_t *data, int i)
{
    for (int w = 0; w < REG_NUMBER; w++)
        for (int j = 0; j < REG_SIZE; j++)
            data->player[i].registers[w] = 0;
}

void set_players(data_t *data)
{
    int space = MEM_SIZE / data->nb_players;
    int place = 0;

    for (int i = 0; i < MEM_SIZE; i++)
        data->memory[i] = '\0';
    for (int i = 0, fd = 0; i < data->nb_players; i++) {
        data->player[i].alive = 1;
        data->player[i].cycle_wait = 0;
        fd = open(data->player[i].name, O_RDONLY);
        if (data->player[i].arg.address == -1)
            data->player[i].arg.address = i * space;
        place = data->player[i].arg.address;
        set_registers(data, i);
        data->player[i].program_counting = place;
        read_cor(place, space, fd, data);
        close(fd);
    }
}

void add_prog_number(data_t *data, int i, int nb_c)
{
    int nb = i;

    for (int j = 0; j < data->nb_players ; j++) {
        if (nb == data->player[j].arg.prog_number) {
            nb++;
            j = 0;
        }
    }
    if (data->player[nb_c].arg.prog_number == -1)
        data->player[nb_c].arg.prog_number = nb;
    data->player[nb_c].registers[0] = data->player[nb_c].arg.prog_number;
}

void fill_arg_player(data_t *data, char **av)
{
    for (int i = 0; i < data->nb_players; i++) {
        data->player[i].alive = 1;
        data->player[i].cycle_wait = 0;
        data->player[i].arg.prog_number = -1;
        data->player[i].carry = 0;
        data->player[i].arg.address = -1;
        data->player[i].live = 0;
    }
    for (int i = 1, nb_champ = 0; av[i] != NULL; i++) {
        if (av[i][0] != '-' && av[i - 1][0] != '-') {
            data->player[nb_champ].name = av[i];
            nb_champ++;
        } else if (!my_strcmp(av[i], "-n") && av[i + 1] != NULL)
            data->player[nb_champ].arg.prog_number = my_atoi(av[i + 1]);
        if (!my_strcmp(av[i], "-a") && av[i + 1] != NULL)
            data->player[nb_champ].arg.address = my_atoi(av[i + 1]);
    }
    for (int i = 0; i < data->nb_players; i++)
        add_prog_number(data, i + 1, i);
}

void get_arg(int ac, char **av, data_t *data)
{
    int nb_champ = 0;

    (void)ac;
    data->nbr_cycle = -1;
    for (int i = 1; av[i] != NULL; i++)
        if (!my_strcmp(av[i], "-dump") && av[i + 1] != NULL)
            data->nbr_cycle = my_atoi(av[i + 1]);
    for (int i = 1; av[i] != NULL; i++)
        if (av[i][0] != '-' && av[i - 1][0] != '-')
            nb_champ++;
    data->player = malloc(sizeof(player_t) * (nb_champ + 1));
    data->nb_players = nb_champ;
    data->nb_player_origin = nb_champ;
    fill_arg_player(data, av);
}