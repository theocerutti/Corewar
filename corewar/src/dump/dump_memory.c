/*
** EPITECH PROJECT, 2019
** dump memory functions
** File description:
** Dump corewar memo
*/

#include "../../include/lib.h"

void dump_memory(unsigned char *memory)
{
    int space = 0;

    for (int i = 0, w = 0; i < MEM_SIZE; i++, w++) {
        if (w == 0) {
            space = my_countf("%X", i);
            for (int j = 0; j < 5 - space; j++)
                my_printf(" ");
            my_printf(":");
        }
        my_printf(" %01X", memory[i]);
        if (w == 31) {
            write(1, "\n", 1);
            w = -1;
        }
    }
}