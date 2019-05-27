/*
** EPITECH PROJECT, 2019
** lib
** File description:
** Header struct.h
*/

#ifndef __STRUCT__
#define __STRUCT__

#include "op.h"

typedef struct arg_s {
    int prog_number;
    int address;
} arg_t;

typedef struct player_s {
    char *name;
    int program_counting;
    int registers[REG_NUMBER];
    unsigned int alive;
    int live;
    unsigned int carry;
    unsigned int cycle_wait;
    arg_t arg;
} player_t;

typedef struct data_s {
    int nb_player_origin;
    int nb_live;
    int cycle_die;
    int cycle_to_die;
    int nbr_cycle;
    player_t *player;
    unsigned char memory[MEM_SIZE];
    int nb_players;
    int total_cycle;
} data_t;

typedef struct get_funct_s
{
    int function;
    int (*ptr)(player_t *, data_t *, unsigned char *);
} get_funct_t;

#endif