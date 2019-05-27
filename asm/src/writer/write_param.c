/*
** EPITECH PROJECT, 2019
** write_param
** File description:
** write_param
*/

#include "asm.h"

int get_pos_byte_flag(list_t *l_flag, char *flag, int off,
int pos_start_line_byte_code)
{
    node_t *tmp = *l_flag;
    int code = 0;

    flag += off;
    for (int i = 0; tmp != NULL && my_strncmp(flag, tmp->flag.name,
    my_strlen(flag)); i++) {
        tmp = tmp->next;
    }
    if (tmp) {
        code = tmp->flag.pos_byte_code - pos_start_line_byte_code;
    }
    return (code);
}

int get_code_param(char *line, int *size_to_write, list_t *l_flag,
pos_byte_t *pos_byte)
{
    int code = 0;

    if (line[0] == 'r') {
        code = get_nbr_param(line, 1);
        *size_to_write = 1;
    } else if (line[0] == DIRECT_CHAR) {
        if (line[1] == LABEL_CHAR)
            code = get_pos_byte_flag(l_flag, line, 2, pos_byte->pos_byte);
        else
            code = get_nbr_param(line, 1);
        *size_to_write = pos_byte->size_byte_direct;
    } else {
        if (line[0] == LABEL_CHAR)
            code = get_pos_byte_flag(l_flag, line, 1, pos_byte->pos_byte);
        else
            code = get_nbr_param(line, 0);
        *size_to_write = IND_SIZE;
    }
    return (code);
}

void setup_byte_code(int *code, int size_to_write)
{
    unsigned char *byte = NULL;

    if (size_to_write == sizeof(unsigned char)) {
        *code = (unsigned char)(*code);
    } else if (size_to_write == IND_SIZE) {
        *code = (short)(*code);
        byte = code;
        reverse_byte(byte, size_to_write);
    } else {
        *code = (int)(*code);
        byte = code;
        reverse_byte(byte, size_to_write);
    }
}

void write_param(data_t *d, op_t *op, char **tab_param)
{
    int code = 0;
    int size_to_write = 0;
    int i = 0;
    pos_byte_t pos_byte = {d->pos_byte_start_line, op->size_byte_direct};

    for (i = 0; tab_param[i] != NULL; i++) {
        code = get_code_param(tab_param[i], &size_to_write, &d->l_flag,
        &pos_byte);
        setup_byte_code(&code, size_to_write);
        d->pos_byte += size_to_write;
        write(d->fd_exec, &code, size_to_write);
    }
}