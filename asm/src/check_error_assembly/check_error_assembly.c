/*
** EPITECH PROJECT, 2019
** check_error_assembly
** File description:
** check_error_assembly
*/

#include "asm.h"

void check_flag(char *str)
{
    int label = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == LABEL_CHAR)
            return;
        for (int j = 0; LABEL_CHARS[j] != '\0'; j++) {
            if (str[i] == LABEL_CHARS[j]) {
                label = 1;
                break;
            }
        }
        if (label == 0)
            exit(84);
        label = 0;
    }
    exit(84);
}

void is_line_err2(char *line)
{
    char *inst = NULL;

    inst = get_line_instruction(line);
    if (inst == NULL)
        exit(84);
    if (check_args(line) == 1)
        exit(84);
}

char **is_line_err(char *line, char **label)
{
    static int nb_label = 0;
    char *str = NULL;

    line = clear_spaces(line, my_strlen(line), 0);
    if ((str = label_and_inst(line, str)) != NULL)
        label = is_line_err(str, label);
    if (line[0] == COMMENT_CHAR || line[0] == '\0' || line[0] == '.')
        return (label);
    for (int i = 0; line[i] != '\0' && line[i] != ' ' && line[i] != '\t'; i++)
        if (line[i] == LABEL_CHAR) {
            check_flag(line);
            if (nb_label != 0)
                my_double_realloc(&label, nb_label + 1);
            label[nb_label] = malloc(sizeof(char) * (my_strlen(line) + 1));
            label[nb_label] = my_strcpy(label[nb_label], line);
            nb_label++;
            return (label);
        }
    is_line_err2(line);
    return (label);
}

void check_labels(char *line, char **label, int i, int lab)
{
    int check = 0;

    for (; line[i] != '\0'; i++)
        if (line[i] == DIRECT_CHAR && line[i + 1] == LABEL_CHAR) {
            lab = 1;
            break;
        }
    if (lab == 0) return;
    if (line[i + 2] <= '9' && line[i + 2] >= '0') return;
    for (int j = 0; label[j] != NULL; j++) {
        for (int idx = i + 2, jo = 0; label[j][jo] != '\0' &&
        label[j][jo] != LABEL_CHAR; idx++, jo++)
            if (line[idx] != label[j][jo]) {
                check = 1;
                break;
            }
        if (check == 0) return;
        check = 0;
    }
    exit(84);
}

void check_error_assembly_file(data_t *data)
{
    char *line = NULL;
    char **label = malloc(sizeof(char *) * 2);

    label[0] = NULL;
    label[1] = NULL;
    for (int i = 0; data->assembly.file[i] != NULL; i++) {
        line = malloc(sizeof(char) * (my_strlen(data->assembly.file[i]) + 1));
        my_strcpy(line, data->assembly.file[i]);
        label = is_line_err(line, label);
    }
    for (int i = 0; data->assembly.file[i] != NULL; i++)
        check_labels(data->assembly.file[i], label, 0, 0);
}