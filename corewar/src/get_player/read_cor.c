/*
** EPITECH PROJECT, 2019
** read_cor
** File description:
** corewar
*/

#include "../../include/corewar.h"

void read_cor(int place, int space, int fd, data_t *data)
{
    char *path = malloc(sizeof(struct header_s));

    read(fd, path, sizeof(struct header_s));
    for (int stck = place, stop = 0; stop == 0; place++) {
        if (place == MEM_SIZE)
            place = 0;
        if (data->memory[place] != 0)
            error_overwriting();
        if (read(fd, data->memory + place, 1) != 1)
            stop = 1;
        if (place > stck + space && stop == 0)
            error_cor();
    }
}