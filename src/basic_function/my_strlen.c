/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** strlen
*/
#include "../../include/parser_json.h"

__attribute__((always_inline)) inline int32_t my_strlen(char const *str)
{
    uint_fast32_t i = 0;
    do {
        i = i + 1;
    } while (str[i] != '\0');
    return i;
}
