/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** detect_array
*/
#include "../../include/parser_json.h"

bool detect_array(char **bucket)
{
    uint_fast32_t len_bucket = my_strlen(bucket[0]);
    for (uint_fast32_t i = 0; i != len_bucket; i++) {
        if (bucket[0][i] == ':' && bucket[0][i + 1] == '[')
            return true;
        else
            break;
    }
    return false;
}
