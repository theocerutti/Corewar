/*
** EPITECH PROJECT, 2018
** coma_print.c
** File description:
** function to help my_printf
*/

#include "my_printf.h"

void print_zero(int nb, int *compt)
{
    for (int i = 0; i < nb; i++)
        my_putchar_c('0', compt);
}

void second_case4(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    int stock;

    if (c == 'u') {
        stock = va_arg(ap, unsigned int);
        zero[1] = my_put_int_base_ct_u(stock, "0123456789", 10, zero);
        if (zero[0] > zero[1]) {
            print_zero(zero[0] - zero[1], compt);
            my_put_int_base_u(stock, "0123456789", 10, compt);
        } else
            my_put_int_base_u(stock, "0123456789", 10, compt);
    } else
        second_case5(nb, c, compt, ap);
}

void second_case3(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    int stock;

    if (c == 'x') {
        stock = va_arg(ap, unsigned int);
        zero[1] = my_put_int_base_ct_u(stock, "0123456789abcdef", 16, zero);
        if (zero[0] > zero[1]) {
            print_zero(zero[0] - zero[1], compt);
            my_put_int_base_u(stock, "0123456789abcdef", 16, compt);
        } else
            my_put_int_base_u(stock, "0123456789abcdef", 16, compt);
    } else
        second_case4(nb, c, compt, ap);
}

void second_case2(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    unsigned int stock;

    if (c == 'o') {
        stock = va_arg(ap, unsigned int);
        zero[1] = my_put_int_base_ct_u(stock, "01234567", 8, zero);
        if (zero[0] > zero[1]) {
            print_zero(zero[0] - zero[1], compt);
            my_put_int_base_u(stock, "01234567", 8, compt);
        } else
            my_put_int_base_u(stock, "01234567", 8, compt);
    } else
        second_case3(nb, c, compt, ap);
}

void second_case1(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    int stock;

    if (c == 'd' || c == 'i') {
        stock = va_arg(ap, int);
        zero[1] = my_put_int_base_ct(stock, "0123456789", 10, zero);
        if (zero[0] > zero[1]) {
            print_zero(zero[0] - zero[1], compt);
            my_put_int_base(stock, "0123456789", 10, compt);
        } else
            my_put_int_base(stock, "0123456789", 10, compt);
    } else
        second_case2(nb, c, compt, ap);
}
