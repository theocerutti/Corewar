/*
** EPITECH PROJECT, 2019
** ASM
** File description:
** ASM
*/

#include "asm.h"

int get_nb_line(char *name)
{
    FILE *fd = fopen(name, "r");
    int size = 0;
    size_t n = 0;
    char *line = NULL;
    int ret = 0;

    if (fd == NULL)
        exit(84);
    ret = getline(&line, &n, fd);
    if (ret == -1)
        exit(84);
    while (ret != -1) {
        size += 1;
        ret = getline(&line, &n, fd);
    }
    fclose(fd);
    return (size);
}

int fill_line_file(file_t *file, FILE *fd, int i, char **line)
{
    int len_line = 0;
    int ret = 0;
    size_t n = 0;

    len_line = my_strlen(*line);
    file->file[i] = malloc(sizeof(char) * (len_line + 1));
    my_strcpy(file->file[i], *line);
    if (file->file[i][len_line - 1] == '\n')
        file->file[i][len_line - 1] = '\0';
    ret = getline(line, &n, fd);
    return (ret);
}

void fill_file(file_t *file, char *name)
{
    int nb_line = get_nb_line(name);
    FILE *fd = fopen(name, "r");
    size_t n = 0;
    int ret = 0;
    char *line = 0;

    if (fd == NULL)
        exit(84);
    file->nb_line = nb_line;
    file->file = malloc(sizeof(char *) * (nb_line + 1));
    ret = getline(&line, &n, fd);
    for (int i = 0; ret != -1; i++) {
        ret = fill_line_file(file, fd, i, &line);
    }
    file->file[nb_line] = NULL;
    file->name = name;
    file->fd = fd;
    fclose(fd);
}