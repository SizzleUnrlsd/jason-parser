/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** jason_token_string
*/
#include "../../include/parser_json.h"

char *token_string(char **str)
{
    uint32_t count = 0;
    for (uint32_t i = 0; str[0][i]; i++) {
        count++;
        if (str[0][i] == '"')
            break;
        if (str[0][i] == ',')
            break;
    }
    char *new_str = malloc(sizeof(char) * (count + 1));
    for (uint32_t i = 0; i != count; i++) {
        new_str[i] = str[0][0];
        (*str)++;
    }
    new_str[count - 1] = '\0';

    return new_str;
}
