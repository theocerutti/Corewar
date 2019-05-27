/*
** EPITECH PROJECT, 2019
** delete_char
** File description:
** delete_char
*/

int my_strlen(const char *s);

void delete_char(char *line, int index)
{
    for (int i = index; i < my_strlen(line) + 1; i++)
        line[i] = line[i + 1];
}