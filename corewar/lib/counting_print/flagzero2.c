/*
** EPITECH PROJECT, 2018
** flagzero2.c
** File description:
** myprintf Antoine MAILLARD
*/

#include "my_printf.h"

int space_gest(int i, char *str, int *compt, va_list ap)
{
    char *nb = NULL;

    if (str[i] == '.' || str[i] == '0') {
        my_putchar_c(' ', compt);
        nb = recup_nb(nb, str, i);
        second_case1(nb, str[i + my_strlen_c(nb)], compt, ap);
        return (my_strlen_c(nb) + 1);
    } else if (str[i] > '0' && str[i] <= '9') {
        nb = recup_nb2(nb, str, i);
        third_case1(nb, str[i + my_strlen_c(nb)], compt, ap);
        return (my_strlen_c(nb) + 1);
    } else {
        my_putchar_c(' ', compt);
        first_case1(str[i], compt, ap);
        return (1);
    }
    return (1);
}

void third_case7(char *nb, char c, int *compt, va_list ap)
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

void third_case6(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    int stock;

    if (c == 'b') {
        stock = va_arg(ap, int);
        zero[1] = my_put_int_base_ct(stock, "01", 2, zero);
        if (zero[0] > zero[1]) {
            print_space(zero[0] - zero[1], compt);
            my_put_int_base(stock, "01", 2, compt);
        } else
            my_put_int_base(stock, "01", 2, compt);
    } else
        third_case7(nb, c, compt, ap);
}

void third_case5(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    int stock;

    if (c == 'X') {
        stock = va_arg(ap, int);
        zero[1] = my_put_int_base_ct_u(stock, "0123456789ABCDEF", 16, zero);
        if (zero[0] > zero[1]) {
            print_space(zero[0] - zero[1], compt);
            my_put_int_base_u(stock, "0123456789ABCDEF", 16, compt);
        } else
            my_put_int_base_u(stock, "0123456789ABCDEF", 16, compt);
    } else
        third_case6(nb, c, compt, ap);
}

void third_case4(char *nb, char c, int *compt, va_list ap)
{
    int zero[2] = {my_getnbr(nb), 0};
    int stock;

    if (c == 'u') {
        stock = va_arg(ap, unsigned int);
        zero[1] = my_put_int_base_ct_u(stock, "0123456789", 10, zero);
        if (zero[0] > zero[1]) {
            print_space(zero[0] - zero[1], compt);
            my_put_int_base_u(stock, "0123456789", 10, compt);
        } else
            my_put_int_base_u(stock, "0123456789", 10, compt);
    } else
        third_case5(nb, c, compt, ap);
}
