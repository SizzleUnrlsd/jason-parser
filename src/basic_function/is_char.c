/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** is_char
*/
#include "../../include/parser_json.h"

inline bool is_char(char **str, char c)
{
    if (**str == c) {
        (*str)++;
        return 1;
    }
    return 0;
}
