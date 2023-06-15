/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** find_string_index
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

inline int32_t find_string_index(char* json, char* target)
{
    char* pos = my_strstr(json, target);
    if (pos == NULL) {
        return -1;
    } else {
        return pos - json;
    }
}
