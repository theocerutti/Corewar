/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "asm.h"

void write_instru_token(data_t *data, token_t *token, char *instru,
int begin_code_line)
{
    for (int i = 0; instru != NULL && op_tab[i].mnemonique != NULL; i++) {
        if (!my_strncmp(instru, op_tab[i].mnemonique, my_strlen(instru))) {
            write_instruction(data, token, &op_tab[i], begin_code_line);
            break;
        }
    }
}

int parse_token(data_t *data, token_t *token)
{
    int ret = 0;
    char *instru = token->t_token[0];
    int begin_code_line = 0;

    if (is_flag(instru)) {
        instru = token->t_token[1];
        begin_code_line = 1;
    } else {
        begin_code_line = 0;
    }
    write_instru_token(data, token, instru, begin_code_line);
    return (ret);
}