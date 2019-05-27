/*
** EPITECH PROJECT, 2018
** flagzero.c
** File description:
** myprintf Antoine MAILLARD
*/

#include "my_printf.h"

void third_case3(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    int stock;

    if (c == 'x') {
        stock = va_arg(ap, int);
        zero[1] = my_put_int_base_ct_u(stock, "0123456789abcdef", 16, zero);
        if (zero[0] > zero[1]) {
            print_space(zero[0] - zero[1], compt);
            my_put_int_base_u(stock, "0123456789abcdef", 16, compt);
        } else
            my_put_int_base_u(stock, "0123456789abcdef", 16, compt);
    } else
        third_case4(nb, c, compt, ap);
}

void third_case2(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    unsigned int stock;

    if (c == 'o') {
        stock = va_arg(ap, unsigned int);
        zero[1] = my_put_int_base_ct_u(stock, "01234567", 8, zero);
        if (zero[0] > zero[1]) {
            print_space(zero[0] - zero[1], compt);
            my_put_int_base_u(stock, "01234567", 8, compt);
        } else
            my_put_int_base_u(stock, "01234567", 8, compt);
    } else
        third_case3(nb, c, compt, ap);
}

void third_case1(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    int stock;

    if (c == 'd' || c == 'i') {
        stock = va_arg(ap, int);
        zero[1] = my_put_int_base_ct(stock, "0123456789", 10, zero);
        if (zero[0] > zero[1]) {
            print_space(zero[0] - zero[1], compt);
            my_put_int_base(stock, "0123456789", 10, compt);
        } else
            my_put_int_base(stock, "0123456789", 10, compt);
    } else
        third_case2(nb, c, compt, ap);
}

void print_space(int nb, int *compt)
{
    for (int i = 0; i < nb; i++)
        my_putchar_c(' ', compt);
}

int flag_nb(char *str, int i, int *compt, va_list ap)
{
    char *nb = NULL;

    if (str[i] > '0' && str[i] <= '9') {
        nb = recup_nb2(nb, str, i);
        third_case1(nb, str[i + my_strlen_c(nb)], compt, ap);
        return (my_strlen_c(nb));
    } else if (str[i] == '#') {
        sharp_gest(str[i + 1], compt, ap);
        return (1);
    } else {
        if (str[i] == ' ') {
            return (space_gest(i + 1, str, compt, ap));
        } else {
            first_case1(str[i], compt, ap);
            return (0);
        }
    }
    return (0);
}
