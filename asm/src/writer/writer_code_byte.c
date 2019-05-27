/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "asm.h"

void get_param_tab_code(char *byte, char **tab_param, int *idx_byte)
{
    for (int i = 0; tab_param[i] != NULL; i++, *idx_byte += 2) {
        switch (tab_param[i][0]) {
            case 'r':
                byte[*idx_byte] = '0';
                byte[*idx_byte + 1] = '1';
                break;
            case DIRECT_CHAR:
                byte[*idx_byte] = '1';
                byte[*idx_byte + 1] = '0';
                break;
            default:
                byte[*idx_byte] = '1';
                byte[*idx_byte + 1] = '1';
        }
    }
}

unsigned char bin_to_unsigned_char(char *byte)
{
    unsigned char code = 0;
    int b = 128;

    for (int i = 0; i < my_strlen(byte); i++) {
        if (byte[i] == '1') {
            code += b;
        }
        b /= 2;
    }
    return (code);
}

void write_code_byte_param(int fd, int *pos_byte, char **tab_param)
{
    unsigned char code = 0;
    char *byte = malloc(sizeof(char) * (MAX_ARGS_NUMBER * 2 + 1));
    int idx_byte = 0;

    get_param_tab_code(byte, tab_param, &idx_byte);
    for (int i = idx_byte; i < MAX_ARGS_NUMBER * 2; i++)
        byte[i] = '0';
    byte[MAX_ARGS_NUMBER * 2] = '\0';
    code = bin_to_unsigned_char(byte);
    *pos_byte += 1;
    write(fd, &code, 1);
}