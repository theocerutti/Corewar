/*
** EPITECH PROJECT, 2018
** coma_print2.c
** File description:
** second file for %. flag Antoine MAILLARD
*/

#include "my_printf.h"

char *recup_nb2(char *nb, char *str, int i)
{
    int compt = 0;

    for (int w = i; str[w] >= '0' && str[w] <= '9'; w++, compt++);
    nb = malloc(compt + 1);
    nb[0] = '0';
    nb[1] = '\0';
    for (int w = i, z = 0; str[w] >= '0' && str[w] <= '9'; w++, z++) {
        nb[z] = str[w];
        nb[z + 1] = '\0';
    }
    return (nb);
}

void my_put_str2(char *stock, int n, int *compt)
{
    for (int i = 0; i < n; i++)
        my_putchar_c(stock[i], compt);
}

void second_case7(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};

    if (c == 's') {
        zero[1] = my_put_str_ct(va_arg(ap, char *), zero);
        if (zero[0] >= zero[1]) {
            my_put_str(va_arg(ap, char *), compt);
        } else
            my_put_str2(va_arg(ap, char *), zero[0], compt);
    }
}

void second_case6(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    int stock;

    if (c == 'b') {
        stock = va_arg(ap, int);
        zero[1] = my_put_int_base_ct(stock, "01", 2, zero);
        if (zero[0] > zero[1]) {
            print_zero(zero[0] - zero[1], compt);
            my_put_int_base(stock, "01", 2, compt);
        } else
            my_put_int_base(stock, "01", 2, compt);
    } else
        second_case7(nb, c, compt, ap);
}

void second_case5(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    int stock;

    if (c == 'X') {
        stock = va_arg(ap, unsigned int);
        zero[1] = my_put_int_base_ct_u(stock, "0123456789ABCDEF", 16, zero);
        if (zero[0] > zero[1]) {
            print_zero(zero[0] - zero[1], compt);
            my_put_int_base_u(stock, "0123456789ABCDEF", 16, compt);
        } else
            my_put_int_base_u(stock, "0123456789ABCDEF", 16, compt);
    } else
        second_case6(nb, c, compt, ap);
}
