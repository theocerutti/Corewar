/*
** EPITECH PROJECT, 2019
** modify the carry function
** File description:
** corewar
*/

#include "../../include/corewar.h"

void modify_the_carry(player_t *player)
{
    if (player->carry == 0)
        player->carry = 1;
    else
        player->carry = 0;
}