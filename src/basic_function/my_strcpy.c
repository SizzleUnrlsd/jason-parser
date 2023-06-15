/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** task01
*/
#include "../../include/parser_json.h"

inline char *my_strcpy(char *dest, char const *src)
{
    uint_fast32_t a = 0;
    do {
        dest[a] = src[a];
        a++;
    } while (src[a] != '\0');
    dest[a] = '\0';
    return dest;
}
