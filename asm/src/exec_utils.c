/*
** EPITECH PROJECT, 2019
** ASM
** File description:
** ASM
*/

#include "asm.h"

char *get_name_exec(char *name_assembly)
{
    int i = 0;
    int pos_slash = 0;
    int j = 0;
    char *name_exec = malloc(sizeof(char) * (my_strlen(name_assembly) + 2));

    for (pos_slash = 0; name_assembly[pos_slash] != '\0'; pos_slash++)
        if (name_assembly[pos_slash] == '/')
            i = pos_slash;
    if (i != 0)
        i++;
    for (j = 0; (name_assembly[i] != '.' || name_assembly[i + 1] != 's')
    && name_assembly[i] != '\0'; i++, j++)
        name_exec[j] = name_assembly[i];
    name_exec[j] = '\0';
    name_exec = my_strcat(name_exec, ".cor");
    return (name_exec);
}

int setup_file_exec(file_t *exec_file, char *name_assembly_file)
{
    char *name_exec = get_name_exec(name_assembly_file);
    mode_t perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    int fd = open(name_exec, O_WRONLY | O_CREAT | O_TRUNC, perm);

    if (fd == -1)
        exit(84);
    exec_file->name = name_exec;
    exec_file->nb_line = 0;
    exec_file->file = NULL;
    exec_file->fd = NULL;
    return (fd);
}