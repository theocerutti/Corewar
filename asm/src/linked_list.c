/*
** EPITECH PROJECT, 2018
** Handle linked_list
** File description:
** Handle linked_list
*/

#include "asm.h"

void delete_list(list_t *list)
{
    node_t *temp = NULL;

    while (*list != NULL) {
        temp = *list;
        *list = (*list)->next;
        free(temp->flag.name);
        free(temp);
    }
    *list = NULL;
}

void push(list_t *list, flag_t new_flag)
{
    node_t *temp = *list;
    node_t *new_node = malloc(sizeof(node_t));

    new_node->flag = new_flag;
    new_node->next = NULL;
    if (is_empty(*list)) {
        *list = new_node;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

void push_index(list_t *list, flag_t new_flag, int n)
{
    node_t *current = *list;
    node_t *temp_node = NULL;
    node_t *new_node = malloc(sizeof(node_t));

    new_node->flag = new_flag;
    if (is_empty(*list)) {
        *list = new_node;
        return;
    }
    if (n == 0) {
        temp_node = current;
        new_node->next = current;
        *list = new_node;
        return;
    }
    for (int i = 0; i < n - 1 && current->next != NULL; i++)
        current = current->next;
    temp_node = current->next;
    current->next = new_node;
    new_node->next = temp_node;
}

void pop_index(list_t *list, int n)
{
    int i = 0;
    node_t *current = *list;
    node_t *temp_node = NULL;

    if (is_empty(*list)) {
        *list = NULL;
        return;
    }
    if (n == 0) {
        *list = (*list)->next;
        return;
    }
    for (i = 0; i < n - 1; i++) {
        if (current->next == NULL)
            return;
        current = current->next;
    }
    temp_node = current->next;
    current->next = temp_node->next;
    free(temp_node);
}

int is_empty(list_t list)
{
    return (list == NULL);
}
