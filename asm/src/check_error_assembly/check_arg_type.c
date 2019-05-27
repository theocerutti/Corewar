/*
** EPITECH PROJECT, 2019
** check_arg_type
** File description:
** check_arg_type
*/

#include "asm.h"

void check_type_arg2(char **args, int i, int pos)
{
    if (args[i][0] == DIRECT_CHAR &&
    ((op_tab[pos].type[i - 1] != T_DIR &&
    op_tab[pos].type[i - 1] != T_DIR + T_REG &&
    op_tab[pos].type[i - 1] != T_DIR + T_IND &&
    op_tab[pos].type[i - 1] != T_DIR + T_IND + T_REG) &&
    (args[i][1] != LABEL_CHAR && ((args[i][1] < '0' ||
    args[i][1] > '9') && args[i][1] != '-')))) {
        exit(84);
    }
    if (((args[i][0] >= '0' && args[i][0] <= '9') ||
    args[i][0] == LABEL_CHAR) &&
    (op_tab[pos].type[i - 1] != T_IND &&
    op_tab[pos].type[i - 1] != T_IND + T_REG &&
    op_tab[pos].type[i - 1] != T_IND + T_DIR &&
    op_tab[pos].type[i - 1] != T_IND + T_DIR + T_REG)) {
        exit(84);
    }
}

void check_type_arg(int pos, char **args)
{
    for (int i = 1; args[i] != NULL; i++) {
        if (args[i][0] == 'r' && ((op_tab[pos].type[i -1] != T_REG &&
        op_tab[pos].type[i - 1] != T_REG + T_DIR &&
        op_tab[pos].type[i - 1] != T_REG + T_IND &&
        op_tab[pos].type[i - 1] != T_REG + T_IND + T_DIR) ||
        (get_reg(args[i], 0, 0, 0) < 1 ||
        get_reg(args[i], 0, 0, 0) > REG_NUMBER))) {
            exit(84);
        }
        check_type_arg2(args, i, pos);
    }
}

char *get_arg(char *str, int *idx, int size)
{
    char *arg = NULL;
    int i = *idx;

    for (; str[i] != '\0'; i++)
        if (str[i] != ' ' && str[i] != SEPARATOR_CHAR && str[i] != '\t')
            break;
    for (int j = i; str[j] != '\0'; j++) {
        if (str[j] == ' ' || str[j] == SEPARATOR_CHAR || str[i] == '\t')
            break;
        size++;
    }
    arg = malloc(sizeof(char) * (size + 1));
    for (int j = 0; str[i] != '\0'; i++, j++) {
        if (str[i] == ' ' || str[i] == SEPARATOR_CHAR || str[i] == '\t')
            break;
        arg[j] = str[i];
    }
    arg[size] = '\0';
    *idx = i;
    return (arg);
}

char **get_args_corewar(char *str)
{
    int size = 1;
    int idx = 0;
    char **args = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == SEPARATOR_CHAR || str[i] == '\t')
        && str[i + 1] != ' ' && str[i + 1] != SEPARATOR_CHAR &&
        str[i + 1] != '\t')
            size++;
    }
    args = malloc(sizeof(char *) * (size + 1));
    args[size] = NULL;
    for (int i = 0; i < size; i++)
        args[i] = get_arg(str, &idx, 0);
    return (args);
}

int check_args(char *str)
{
    int nb_args = 1;
    int pos = 0;

    for (int i = 0; str[i] != '\0' && str[i] != COMMENT_CHAR; i++)
        if (str[i] == SEPARATOR_CHAR && str[i + 1] != '\0')
            nb_args++;
    for (; op_tab[pos].mnemonique != NULL; pos++) {
        if (str_begin(str, op_tab[pos].mnemonique) == 0)
            break;
    }
    if (op_tab[pos].nbr_args != nb_args) {
        exit(84);
    }
    check_type_arg(pos,
    get_args_corewar(get_code_line_without_commentary(str)));
    return (0);
}