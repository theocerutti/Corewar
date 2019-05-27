/*
** EPITECH PROJECT, 2019
** linked_list header
** File description:
** header
*/

typedef struct flag_s {
    char *name;
    int pos_byte_code;
} flag_t;

typedef struct node_t {
    flag_t flag;
    struct node_t *next;
} node_t;
typedef node_t *list_t;

void delete_list(list_t *list);
void push(list_t *list, flag_t new_flag);
void push_index(list_t *list, flag_t new_flag, int n);
void pop_index(list_t *list, int n);
void print_list(list_t *list);
int is_empty(list_t list);
