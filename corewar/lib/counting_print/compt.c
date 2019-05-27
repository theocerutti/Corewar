/*
** EPITECH PROJECT, 2018
** compt.c
** File description:
** same fucntion than print.c but compt Antoine MAILLARD
*/

#include "my_printf.h"

int my_put_int_base_ct(int nb, char *base, int len, int *ct)
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

int my_showstr_ct(char *str, int *ct)
{
    int s;

    for (int i = 0; str[i] != '\0'; i++) {
        s = str[i];
        if (s >= 127) {
            ct[1] += 1;
            ct[1] += my_put_int_base_ct(s, "01234567", 8, ct);
        }
        if (s <= 7) {
            ct[1] += 3;
            my_put_int_base_ct(s, "01234567", 8, ct);
        } else if (s < 32) {
            ct[1] += 2;
            my_put_int_base_ct(s, "01234567", 8, ct);
        } else
            ct[1] += 1;
    }
    return (ct[1]);
}

int my_put_str_ct(char *str, int *ct)
{
    for (int i = 0; str[i] != '\0'; i++)
        ct[1] += 1;
    return (ct[1]);
}

void set_nbr(char *str, int j, double *res)
{
    int i;
    int x = 1;

    for (i = j; str[i] >= '0' && str[i] <= '9'; i++);
    i -= 1;
    for (; str[i] >= '0' && str[i] <= '9'; i--) {
        if (*res + (str[i] - 48) * x < 2147483647) {
            *res += (str[i] - 48) * x;
            x *= 10;
        } else {
            *res = 0;
            break;
        }
    }
}

int my_getnbr(char *str)
{
    int i = 0;
    int result;
    double set_nb = 0;
    double *res = &set_nb;

    if (str[i] >= '0' && str[i] <= '9')
        set_nbr(str, 0, res);
    result = *res;
    return (result);
}
