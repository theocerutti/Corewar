/*
** EPITECH PROJECT, 2019
** error_get
** File description:
** corewar
*/

#include "../../include/lib.h"

void error_overwriting(void)
{
    my_printf("A champion is already writing on another one's memory.\n");
    exit(1);
}

void error_cor(void)
{
    my_printf("The number of champion load is above the limit.\n");
    exit(1);
}

int is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}