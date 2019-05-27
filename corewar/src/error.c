/*
** EPITECH PROJECT, 2019
** error
** File description:
** corewar
*/

#include "../include/corewar.h"

int error_nb_prog(char **av)
{
    for (int i = 0; av[i] != NULL; i++) {
        for (int j = 0; av[j] != NULL; j++) {
            if (av[i + 1] != NULL && av[j + 1] != NULL && j != i && \
            !my_strcmp(av[i], "-n") && !my_strcmp(av[j], "-n") \
            && !my_strcmp(av[i + 1], av[j + 1])) {
                my_printf("Two champions can't have the same prog number\n");
                return (84);
            }
        }
    }
    return (0);
}

int check_error(char **av, int ac)
{
    if (ac < 3 || error_nb_prog(av) == 84)
        return (84);
    for (int i = 0; av[i] != NULL; i++) {
        if (av[i][0] == '-' && !(!my_strcmp(av[i], "-a") || \
        !my_strcmp(av[i], "-n") || !my_strcmp(av[i], "-dump")))
            return (84);
        if (av[i][0] == '-' && av[i + 1] != NULL) {
            if (!is_number(av[i + 1]))
                return (84);
        } else if (av[i][0] == '-' && av[i + 1] == NULL)
            return (84);
        if (is_number(av[i]) && av[i - 1][0] != '-')
            return (84);
    }
    return (0);
}