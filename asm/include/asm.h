/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** LIB
*/

#include "lib.h"

#define FALSE 0
#define TRUE 1
#define VALID_CHAR(c) (c > 31 && c < 127)

void fill_file(file_t *file, char *name);
void convert_assembly_to_exec_vm(data_t *data);
char *get_name_exec(char *name_assembly);
void convert_header(data_t *data);
int parse_token(data_t *data, token_t *token);
void check_error_assembly_file(data_t *data);
token_t get_next_token(file_t *assembly_file, int n_line);
int is_flag(char *line);
char **get_args_corewar(char *str);
void write_instruction(data_t *data, token_t *token, op_t *op,
int begin_code_line);
int setup_file_exec(file_t *exec_file, char *name_assembly_file);
char *clear_spaces(char *str, int size, int index);
int check_args(char *str);
char *clear_comma(char *str);
int get_reg(char *str, int res, int i, int size_nbr);
char *get_line_instruction(char *str);
int str_begin(char *str, char *check);
char **get_just_param_corewar(char *str, int begin_code_line);
void write_code_byte_param(int fd, int *pos_byte, char **tab_param);
void write_param(data_t *d, op_t *op, char **tab_param);
int get_nbr_param(char const *str, int off);
void reverse_byte(unsigned char *s, int size);
void get_prog_size_and_flag_pos(char **file, list_t *l_flag, int *prog_size);
char *get_code_line_without_commentary(char *line);
int is_empty_token(char *line);
token_t transfo_in_token(char *line);
int get_direct_size(char *instru);
int get_opcode_size(char *instru);
int is_variable(char *str, char *op);
int is_empty_line(char *str);
char *my_strcpy_special(char *dest, char *src);
int str_begin(char *str, char *check);
char *get_line_instruction(char *str);
int get_reg(char *str, int res, int i, int size_nbr);
void my_double_realloc(char ***str, int size);
char *get_next_inst(char *line, char *str, int idx);
char *label_and_inst(char *line, char *str);