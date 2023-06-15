/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** print_array
*/
#include "../../include/lib.h"

void print_array(char **array, char c)
{
    for (int i = 0; i != len_array(array); i++) {
        my_putchar('[', 1);
        my_putstr(array[i], 1);
        my_putchar(']', 1);
        if (c != 0)
            my_putchar(c, 1);
    }
    return;
}
