/*
** EPITECH PROJECT, 2018
** basics.c
** File description:
** basic function Antoine MAILLARD
*/

#include "my_printf.h"

void sharp_gest(char c, int *compt, va_list ap)
{
    if (c == 'x' || c == 'X') {
        if (c == 'x')
            my_put_str("0x", compt);
        else
            my_put_str("0X", compt);
    } else if (c == 'o')
        my_putchar_c('0', compt);
    first_case1(c, compt, ap);
}

void my_put_int_base_u(long nb, char *base, int len, int *compt)
{
    if (nb > len - 1) {
        my_put_int_base_u(nb / len, base, len, compt);
    }
    if (nb < 0 && nb < -len - 1) {
        my_putchar_c('-', compt);
        nb = nb * -1;
        my_put_int_base_u(nb / len, base, len, compt);
    } else if (nb < 0) {
        my_putchar_c('-', compt);
        nb *= -1;
    }
    my_putchar_c(base[nb % len], compt);
}

int my_put_int_base_ct_u(long nb, char *base, int len, int *ct)
{
    if (nb > len - 1) {
        my_put_int_base_ct(nb / len, base, len, ct);
    }
    if (nb < 0 && nb < -len - 1) {
        ct[1] += 1;
        nb = nb * -1;
        my_put_int_base_ct(nb / len, base, len, ct);
    } else if (nb < 0) {
        ct[1] += 1;
        nb *= -1;
    }
    ct[1] += 1;
    return (ct[1]);
}
