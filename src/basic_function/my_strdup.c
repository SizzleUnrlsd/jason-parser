/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup
*/
#include "../../include/parser_json.h"

__attribute__((always_inline)) inline char *my_strdup(char const *src)
{
    int_fast32_t a = 0;
    char *dest = NULL;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return NULL;
    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}
