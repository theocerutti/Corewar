/*
** EPITECH PROJECT, 2019
** ASM converter
** File description:
** ASM converter
*/

#include "asm.h"

int exec_token(data_t *data, token_t *token)
{
    switch (token->is_token) {
        case GOOD_TOKEN:
            parse_token(data, token);
            break;
        case BAD_TOKEN:
            break;
        default:
            exit(84);
    }
    return (0);
}

void convert_assembly_to_exec_vm(data_t *data)
{
    token_t token = {0, 0, 0, 0};

    data->fd_exec = setup_file_exec(&data->exec, data->assembly.name);
    convert_header(data);
    token = get_next_token(&data->assembly, data->pos_line);
    data->pos_line++;
    while (token.is_token != NO_OTHER_TOKEN) {
        exec_token(data, &token);
        free(token.t_token);
        free(token.token);
        token = get_next_token(&data->assembly, data->pos_line);
        data->pos_line++;
    }
    free(data->exec.name);
    close(data->fd_exec);
}