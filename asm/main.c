/*
** EPITECH PROJECT, 2019
** ASM
** File description:
** ASM
*/

#include "asm.h"

void print_help(void)
{
    my_printf("USAGE\n\t\t./asm file_name[.s]\n\nDESCRIPTION\n");
    my_printf("\t\tfile_name\tfile in assembly language");
    my_printf("to be converted into file_name.cor, an\n\t\t");
    my_printf("\t\texecutable in the Virtual Machine.\n");
    exit(0);
}

int check_error_file_name(char *name)
{
    int i = 0;

    for (i = 0; name[i] != '\0' && name[i] != '.'; i++);
    if (name[i] == '\0') {
        return (84);
    } else if (i != 0 && name[i] == '.' && name[i + 1] == 's' &&
    name[i + 2] == '\0')
        return (0);
    return (0);
}

void check_error_av(int ac, char **av)
{
    FILE *fd = NULL;

    if ((ac >= 2 && !my_strncmp("-h", av[1], 3)) || ac == 1)
        print_help();
    if (ac != 2)
        exit(84);
    if (!(fd = fopen(av[1], "r")))
        exit(84);
    if (check_error_file_name(av[1]) == 84)
        exit(84);
    fclose(fd);
}

void init_data(data_t *data, int ac, char **av)
{
    data->ac = ac;
    data->av = av;
    data->l_flag = NULL;
    data->pos_line = 0;
    data->prog_size = 0;
    data->pos_byte = 0;
    data->pos_byte_start_line = 0;
    fill_file(&data->assembly, av[1]);
}

int main(int ac, char **av)
{
    data_t data;

    check_error_av(ac, av);
    init_data(&data, ac, av);
    check_error_assembly_file(&data);
    get_prog_size_and_flag_pos(data.assembly.file, &data.l_flag,
    &data.prog_size);
    convert_assembly_to_exec_vm(&data);
    return (0);
}