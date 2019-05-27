/*
** EPITECH PROJECT, 2019
** lib
** File description:
** Header struct.h
*/

enum ret_token {
    NO_OTHER_TOKEN = -1,
    BAD_TOKEN,
    GOOD_TOKEN,
    ERROR_TOKEN = 84,
};

typedef struct pos_byte_s {
    int pos_byte;
    int size_byte_direct;
} pos_byte_t;

typedef struct token_s {
    char *token;
    char **t_token;
    int nb_token;
    int is_token;
} token_t;

typedef struct file_s {
    FILE *fd;
    char *name;
    char **file;
    int nb_line;
} file_t;

typedef struct data_s {
    int ac;
    char **av;
    file_t assembly;
    file_t exec;
    list_t l_flag;
    int pos_line;
    int pos_byte;
    int pos_byte_start_line;
    int prog_size;
    int fd_exec;
} data_t;