/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** LIB
*/

#ifndef __COREWAR__
#define __COREWAR__

#include "lib.h"

void push_ind(int index, unsigned char *memory, int *nb);
void get_value_ldi(int rd_val[2][3], data_t *data, int i, int *index);
void get_read_ldi(int param[4], int rd_val[2][3]);
int check_coding_byte_ldi(int param[4]);
void get_index_ldi(int rd_val[2][3], player_t *player, int *index);

int check_coding_byte_and(int param[4]);
void and_or_xor_read(int to_read[3], int param[4], player_t *player);
void fill_integer(int j, int w, unsigned char *integer, unsigned char *memory);
void get_value_and(int size, int *value, unsigned char *memory, int *index);

void modify_the_carry(player_t *player);

unsigned char get_coding_byte(unsigned char cod_byte, int id_param);

void read_cor(int place, int space, int fd, data_t *data);

void error_overwriting(void);
void error_cor(void);
int is_number(char *str);

void dump_memory(unsigned char *memory);

void set_players(data_t *data);
void get_arg(int ac, char **av, data_t *data);
int check_error(char **av, int ac);

int is_more_than_one_player_alive(data_t *data);

int get_ind(int index, unsigned char *memory);
int get_dir(int index, unsigned char *memory);
void copy_player_add(data_t *data, player_t *player, short pos);
char *get_name_cor(char *file);

int add(player_t *player, data_t *data, unsigned char *n_memory);
int aff(player_t *player, data_t *data, unsigned char *n_memory);
int and(player_t *player, data_t *data, unsigned char *n_memory);
int fork_vm(player_t *player, data_t *data, unsigned char *n_memory);
int ld(player_t *player, data_t *data, unsigned char *n_memory);
int ldi(player_t *player, data_t *data, unsigned char *n_memory);
int lfork(player_t *player, data_t *data, unsigned char *n_memory);
int live(player_t *player, data_t *data, unsigned char *n_memory);
int lld(player_t *player, data_t *data, unsigned char *n_memory);
int lldi(player_t *player, data_t *data, unsigned char *n_memory);
int or(player_t *player, data_t *data, unsigned char *n_memory);
int xor(player_t *player, data_t *data, unsigned char *n_memory);
int st(player_t *player, data_t *data, unsigned char *n_memory);
int sti(player_t *player, data_t *data, unsigned char *n_memory);
int sub(player_t *player, data_t *data, unsigned char *n_memory);
int zjmp(player_t *player, data_t *data, unsigned char *n_memory);

#endif