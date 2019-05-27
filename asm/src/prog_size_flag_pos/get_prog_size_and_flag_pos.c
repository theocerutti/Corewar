/*
** EPITECH PROJECT, 2019
** get_prog_size
** File description:
** get_prog_size
*/

#include "asm.h"

int is_flag(char *line)
{
    return (is_in(LABEL_CHAR, line));
}

void add_flag_to_list(list_t *l_flag, char *name, int pos_code)
{
    flag_t flag;
    char *new_name = malloc(sizeof(char) * (my_strlen(name) + 1));
    int i = 0;

    for (i = 0; name[i] != '\0' && name[i] != LABEL_CHAR; i++)
        new_name[i] = name[i];
    new_name[i] = '\0';
    flag.name = new_name;
    flag.pos_byte_code = pos_code;
    push(l_flag, flag);
}

void count_prog_byte_param(char **tab_param, token_t *token,
int begin_code_line, int *prog_size)
{
    for (int i = 0; tab_param[i] != NULL; i++) {
        switch (tab_param[i][0]) {
            case 'r':
                *prog_size += 1;
                break;
            case DIRECT_CHAR:
                *prog_size += get_direct_size(token->t_token[begin_code_line]);
                break;
            default:
                *prog_size += IND_SIZE;
                break;
        }
    }
}

void count_nb_byte_token(token_t *token, list_t *l_flag, int *prog_size)
{
    int begin_code_line = 0;
    char **tab_param = NULL;
    int size_instru = 1;

    if (is_in(LABEL_CHAR, token->t_token[0]))
        begin_code_line++;
    tab_param = get_just_param_corewar(token->token, begin_code_line);
    if (is_in(LABEL_CHAR, token->t_token[0]))
        add_flag_to_list(l_flag, token->t_token[0], *prog_size);
    if (token->t_token[1] != NULL) {
        count_prog_byte_param(tab_param, token, begin_code_line, prog_size);
        *prog_size += get_opcode_size(token->t_token[begin_code_line]);
        *prog_size += size_instru;
    }
}

void get_prog_size_and_flag_pos(char **file, list_t *l_flag, int *prog_size)
{
    unsigned char *s = NULL;
    token_t token;

    for (int i = 0; file[i] != NULL; i++) {
        token = transfo_in_token(file[i]);
        if (token.is_token == GOOD_TOKEN && !is_in('.', token.t_token[0]))
            count_nb_byte_token(&token, l_flag, prog_size);
    }
    s = prog_size;
    reverse_byte(s, sizeof(int));
}