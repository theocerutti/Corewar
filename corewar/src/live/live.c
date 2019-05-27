/*
** EPITECH PROJECT, 2019
** live corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

char *get_name_cor(char *file)
{
    char *str = NULL;
    int c_s = 0;
    int c_p = 0;

    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '/')
            c_s = i;
        if (file[i] == '.')
            c_p = i;
    }
    str = malloc(sizeof(char) * (c_p - c_s));
    for (int i = c_s + 1, w = 0; file[i] != 0 && file[i] != '.'; i++, w++) {
        str[w] = file[i];
    }
    str[c_p - c_s - 1] = '\0';
    return (str);
}

int live(player_t *player, data_t *data, unsigned char *n_memory)
{
    (void)n_memory;
    if (data->nbr_cycle == -1) {
        my_printf("The player %d(%s) is alive.\n",
        player->arg.prog_number, get_name_cor(player->name));
    }
    player->live = 1;
    player->cycle_wait = op_tab[0].nbr_cycles;
    data->nb_live += 1;
    if (data->nb_live > NBR_LIVE)
        data->cycle_to_die -= CYCLE_DELTA;
    return (1 + DIR_SIZE);
}