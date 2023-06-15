/*
** EPITECH PROJECT, 2022
** str
** File description:
** cat
*/
#include "../../include/parser_json.h"

char *my_strcat(char *dest, char const *src)
{
    int32_t cmpt = 0;
    int32_t size = my_strlen(dest);

    while (src != NULL && src[cmpt] != '\0') {
        dest[size] = src[cmpt];
        cmpt++;
        size++;
    }
    dest[size] = '\0';
    return dest;
}
