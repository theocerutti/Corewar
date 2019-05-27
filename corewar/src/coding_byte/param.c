/*
** EPITECH PROJECT, 2019
** coding byte param
** File description:
** corewar
*/

#include "../../include/lib.h"

unsigned char get_coding_byte(unsigned char cod_byte, int id_param)
{
    int shift[] = {6, 4, 2, 0};
    unsigned char byte = cod_byte >> shift[id_param] & 0b11;

    return (byte);
}