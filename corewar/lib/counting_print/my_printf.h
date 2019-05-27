/*
** EPITECH PROJECT, 2018
** my_printf.h
** File description:
** header my_printf Antoine MAILLARD
*/

#ifndef __INCLUSION__
#define __INCLUSION__

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int my_countf(char *, ...);
void my_putchar_c(char, int *);
void my_put_int_base(int, char *, int, int *);
void my_put_int_base_u(long, char *, int, int *);
void my_put_str(char *, int *);
void my_showstr(char *, int *);
int my_put_int_base_ct(int, char *, int, int *);
int my_put_int_base_ct_u(long, char *, int, int *);
int my_put_str_ct(char *, int *);
int my_showstr_ct(char *, int *);
int my_strlen_c(char *);
int my_getnbr(char *);
void print_zero(int, int *);
void print_space(int, int *);
void second_case1(char *, char, int *, va_list);
void second_case5(char *, char, int *, va_list);
int flag_nb(char *, int, int *, va_list);
char *recup_nb(char *, char *, int);
char *recup_nb2(char *, char *, int);
void first_case1(char, int *, va_list);
void first_case2(char, int *, va_list);
void third_case4(char *, char, int *, va_list);
void third_case1(char *, char, int *, va_list);
void my_put_str2(char *, int, int *);
int space_gest(int, char *, int *, va_list);
void sharp_gest(char, int *, va_list);

#endif
