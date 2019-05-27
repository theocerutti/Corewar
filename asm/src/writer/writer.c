/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "asm.h"

void write_instruction_code(int fd, unsigned char code, int *pos_byte)
{
    *pos_byte += 1;
    write(fd, &code, 1);
}

void write_instruction(data_t *data, token_t *token, op_t *op,
int begin_code_line)
{
    char **tab_param = get_just_param_corewar(token->token, begin_code_line);

    data->pos_byte_start_line = data->pos_byte;
    write_instruction_code(data->fd_exec, op->code, &data->pos_byte);
    if (op->write_code_byte == TRUE)
        write_code_byte_param(data->fd_exec, &data->pos_byte, tab_param);
    write_param(data, op, tab_param);
}