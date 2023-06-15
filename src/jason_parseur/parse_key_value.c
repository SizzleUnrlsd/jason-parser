/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** parse_key_value
*/
#include "../../include/parser_json.h"

void parse_key_value(char *json_str, char **keys, char **val)
{
    char *ptr = json_str; char *name_start = ptr;
    while (*ptr != ':')
        ptr++;
    int_fast32_t name_len = ptr - name_start;
    char *name = malloc((name_len + 1) * sizeof(char));
    my_strncpy(name, name_start, name_len);
    name[name_len] = '\0';
    while (*ptr != ':' && *ptr != '\0') ptr++;
    ptr++;
    while (*ptr == ' ' && *ptr != '\0') ptr++;
    char *value_start = ptr;
    while (*ptr != ',' && *ptr != '\0')
        ptr++;
    int_fast32_t value_len = ptr - value_start;
    char *value = malloc((value_len + 1) * sizeof(char));
    my_strncpy(value, value_start, value_len);
    value[value_len] = '\0';
    *keys = name; *val = value;
    return;
}
