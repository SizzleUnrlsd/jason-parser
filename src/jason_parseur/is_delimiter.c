/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** is_delimiter
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

inline bool is_delimiter(char c)
{
    return c < '0' || c > '9';
}
