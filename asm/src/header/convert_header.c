/*
** EPITECH PROJECT, 2019
** line_clearing
** File description:
** line_clearing
*/

#include "asm.h"

void check_comment_place(char **str, int i, int idx)
{
    char *com = ".comment";

    for (i = i + 1; str[i] != NULL; i++)
        if (is_empty_line(str[i]) == 1)
            break;
    for (idx = 0; str[i][idx] != '\0'; idx++)
        if (str[i][idx] != ' ' && str[i][idx] != '\t')
            break;
    if (str[i][idx] != '.')
        exit(84);
    for (int j = 0; com[j] != '\0'; j++, idx++)
        if (str[i][idx] != com[j])
            exit(84);
}

void check_name_place(char **str)
{
    int i = 0;
    int idx = 0;
    char *name = ".name";

    for (; str[i] != NULL; i++)
        if (str[i][0] != COMMENT_CHAR)
            break;
    for (; str[i][idx] != '\0'; idx++)
        if (str[i][idx] != ' ' && str[i][idx] != '\t')
            break;
    if (str[i][idx] != '.')
        exit(84);
    for (int j = 0; name[j] != '\0'; j++, idx++)
        if (str[i][idx] != name[j])
            exit(84);
    check_comment_place(str, i, idx);
}

void check_error_header(data_t *data, header_t *header, int *name, int *com)
{
    char *str = NULL;

    for (int i = 0; data->assembly.file[i] != NULL; i++) {
        str = data->assembly.file[i];
        if (is_variable(str, ".name") == 0) {
            my_strcpy_special(header->prog_name, str);
            *name = 1;
        }
        if (is_variable(str, ".comment") == 0) {
            my_strcpy_special(header->comment, str);
            *com = 1;
        }
    }
}

void convert_header(data_t *data)
{
    header_t header = {COREWAR_EXEC_MAGIC, {0}, data->prog_size, {0}};
    int com = 0;
    int name = 0;
    unsigned char *magic_byte = NULL;

    check_name_place(data->assembly.file);
    check_error_header(data, &header, &name, &com);
    if (name == 0)
        exit(84);
    if (com == 0)
        header.comment[0] = '\0';
    magic_byte = &header.magic;
    reverse_byte(magic_byte, sizeof(int));
    write(data->fd_exec, &header, sizeof(header));
}