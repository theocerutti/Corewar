/*
** EPITECH PROJECT, 2019
** get_prog_size_utils
** File description:
** get_prog_size_utils
*/

#include "asm.h"

token_t transfo_in_token(char *line)
{
    token_t token;

    if (is_empty_token(line))
        token.is_token = BAD_TOKEN;
    else
        token.is_token = GOOD_TOKEN;
    token.token = get_code_line_without_commentary(line);
    token.t_token = my_str_to_word_array(line, ' ');
    return (token);
}

int get_direct_size(char *instru)
{
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (!my_strncmp(op_tab[i].mnemonique, instru, my_strlen(instru)))
            return (op_tab[i].size_byte_direct);
    }
    return (0);
}

int get_opcode_size(char *instru)
{
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (!my_strncmp(op_tab[i].mnemonique, instru, my_strlen(instru))) {
            if (op_tab[i].write_code_byte == TRUE)
                return (1);
            else
                return (0);
        }
    }
    return (0);
}