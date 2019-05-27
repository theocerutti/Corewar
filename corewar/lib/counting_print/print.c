/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** printing functions for my_printf Antoine MAILLARD
*/

#include "my_printf.h"

void my_putchar_c(char c, int *compt)
{
    write(1, &c, 1);
    compt[0] += 1;
}

void my_put_int_base(int nb, char *base, int len, int *compt)
{
    if (nb > len - 1) {
        my_put_int_base(nb / len, base, len, compt);
    }
    if (nb < 0 && nb < -len - 1) {
        my_putchar_c('-', compt);
        nb = nb * -1;
        my_put_int_base(nb / len, base, len, compt);
    } else if (nb < 0) {
        my_putchar_c('-', compt);
        nb *= -1;
    }
    my_putchar_c(base[nb % len], compt);
}

void my_showstr(char *str, int *compt)
{
    int s;

    for (int i = 0; str[i] != '\0'; i++) {
        s = str[i];
        if (s >= 127) {
            my_putchar_c('\\', compt);
            my_put_int_base(s, "01234567", 8, compt);
        }
        if (s <= 7) {
            my_putchar_c('\\', compt);
            my_putchar_c('0', compt);
            my_putchar_c('0', compt);
            my_put_int_base(s, "01234567", 8, compt);
        } else if (s < 32) {
            my_putchar_c('\\', compt);
            my_putchar_c('0', compt);
            my_put_int_base(s, "01234567", 8, compt);
        } else
            my_putchar_c(str[i], compt);
    }
}

void my_put_str(char *str, int *compt)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_c(str[i], compt);
}

int my_strlen_c(char *str)
{
    int len;

    for (len = 0; str[len] != '\0'; len++);
    return (len);
}
