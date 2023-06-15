/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-minishell1-clement-antoine.xavier
** File description:
** my_memset.c
*/

#include <stddef.h>
#include "lib.h"

int my_memset_zero(void *buffer, char c, size_t size)
{
    char *ptr = (char *)buffer;
    if (buffer == NULL)
        return 84;
    for (size_t i = 0; i < size; i++)
        ptr[i] = c;
    return (0);
}
