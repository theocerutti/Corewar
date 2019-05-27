/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for my_printf Antoine MAILLARD
*/

#include "my_printf.h"

char *recup_nb(char *nb, char *str, int i)
{
    int compt = 0;

    for (int w = i + 1; str[w] >= '0' && str[w] <= '9'; w++, compt++);
    nb = malloc(compt + 2);
    nb[0] = '0';
    nb[1] = '\0';
    for (int w = i + 1, z = 1; str[w] >= '0' && str[w] <= '9'; w++, z++) {
        nb[z] = str[w];
        nb[z + 1] = '\0';
    }
    return (nb);
}

void first_case3(char c, int *compt, va_list ap)
{
    switch (c) {
        case 'S':
            my_showstr(va_arg(ap, char *), compt);
            break;
        case 'p':
            my_putchar_c('0', compt);
            my_putchar_c('x', compt);
            my_put_int_base_u(va_arg(ap, long), "0123456789abcdef", 16, compt);
            break;
        case 'x':
            my_put_int_base_u(va_arg(ap, unsigned int), "0123456789abcdef", \
            16, compt);
            break;
        default:
            my_putchar_c('%', compt);
            my_putchar_c(c, compt);
            break;
    }
}

void first_case2(char c, int *compt, va_list ap)
{
    switch (c) {
        case 'X':
            my_put_int_base_u(va_arg(ap, unsigned int), "0123456789ABCDEF"\
            , 16, compt);
            break;
        case 's':
            my_put_str(va_arg(ap, char *), compt);
            break;
        case 'b':
            my_put_int_base(va_arg(ap, unsigned int), "01", 2, compt);
            break;
        case '%':
            my_putchar_c('%', compt);
            break;
        default:
            first_case3(c, compt, ap);
            break;
    }
}

void first_case1(char c, int *compt, va_list ap)
{
    switch (c) {
        case 'i':
        case 'd':
            my_put_int_base(va_arg(ap, int), "0123456789", 10, compt);
            break;
        case 'o':
            my_put_int_base_u(va_arg(ap, unsigned int), "01234567", 8, compt);
            break;
        case 'u':
            my_put_int_base_u(va_arg(ap, unsigned int), "0123456789", 10\
            , compt);
            break;
        case 'c':
            my_putchar_c(va_arg(ap, int), compt);
            break;
        default:
            first_case2(c, compt, ap);
            break;
    }
}

int my_countf(char *str, ...)
{
    int res = 0;
    int *compt = &res;
    char *nb = NULL;
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] != '.' && str[i + 1] != '0') {
            i += flag_nb(str, i + 1, compt, ap);
            i += 1;
        } else if (str[i] == '%' && (str[i + 1] == '.' || str[i + 1] == '0')) {
            nb = recup_nb(nb, str, i + 1);
            second_case1(nb, str[i + my_strlen_c(nb) + 1], compt, ap);
            i += my_strlen_c(nb) + 1;
        } else
            my_putchar_c(str[i], compt);
    }
    va_end(ap);
    return (res);
}
