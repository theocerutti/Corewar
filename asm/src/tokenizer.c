/*
** EPITECH PROJECT, 2019
** token
** File description:
** token
*/

#include "asm.h"

int is_empty_token(char *line)
{
    int n_char = 0;

    if (line == NULL || line[0] == '\0')
        return (1);
    for (int i = 0; line[i] != '\0' && line[i] != COMMENT_CHAR; i++) {
        if (VALID_CHAR(line[i]) && line[i] != ' ' && line[i] != '\t')
            n_char++;
    }
    if (n_char == 0)
        return (1);
    return (0);
}

char *get_code_line_without_commentary(char *line)
{
    char *code_line = NULL;
    int i = 0;

    if (!is_in(COMMENT_CHAR, line)) {
        return (line);
    } else {
        code_line = malloc(sizeof(char) * (my_strlen(line) + 1));
        for (i = 0; line[i] != '\0' && line[i] != '#'; i++)
            code_line[i] = line[i];
        code_line[i] = '\0';
    }
    return (code_line);
}

token_t get_next_token(file_t *assembly_file, int n_line)
{
    token_t token = {0};
    char *line = assembly_file->file[n_line];

    if (n_line == assembly_file->nb_line) {
        token.is_token = NO_OTHER_TOKEN;
    } else if (is_empty_token(line)) {
        token.is_token = BAD_TOKEN;
    } else {
        token.is_token = GOOD_TOKEN;
        token.token = get_code_line_without_commentary(line);
        token.t_token = my_str_to_word_array(token.token, ' ');
        token.nb_token = get_size_tab(token.t_token);
    }
    if (n_line <= assembly_file->nb_line)
        n_line++;
    return (token);
}