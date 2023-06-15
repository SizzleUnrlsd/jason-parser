/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** detect_structural_character
*/
#include "../../include/parser_json.h"

char* format_ptr(char* ptr)
{
    int longueur = my_strlen(ptr);
    if (longueur >= 2 && ptr[longueur - 2] == ']'
    && ptr[longueur - 1] == '}') {
        ptr[longueur - 2] = '\0';
    }
    if (longueur >= 2 && ptr[longueur - 2] == '}'
    && ptr[longueur - 1] == ']') {
        ptr[longueur - 2] = '\0';
    }
    if (longueur >= 1 && ptr[longueur - 1] == '}') {
        ptr[longueur - 1] = '\0';
    }
    return ptr;
}

void detect_structural_second_token_extend(char *ptr, uint_fast32_t len_ptr,
                                                            bool *is_number)
{
    ptr = format_ptr(ptr);
    len_ptr = my_strlen(ptr);
    if (ptr[len_ptr - 1] == '}')
        len_ptr--;
    for (uint_fast32_t i = 0; i < len_ptr; i++) {
        if ((ptr[i] < '0' || ptr[i] > '9') && ptr[i] != '.' && ptr[i] != '-') {
            *is_number = false;
            break;
        }
    }
}

int32_t detect_structural_second_token(char **str)
{
    char *ptr = *str;
    if (*ptr == '\"')
        return STRING;
    if (my_strcmp(ptr, "true") == 0 || my_strcmp(ptr, "false") == 0)
        return BOOLEAN;
    if (my_strcmp(ptr, "null") == 0)
        return NONE;
    if (*ptr == '[') {
        return ARRAY;
    } else {
        bool is_number = true;
        uint_fast32_t len_ptr = my_strlen(ptr);
        detect_structural_second_token_extend(ptr, len_ptr, &is_number);
        if (is_number) {
            return INTEGER;
        } else {
            return STRING;
        }
    }
    return NONE;
}

char *detect_structural_character(char **str)
{
    switch (detect_structural_second_token(str)) {
    case STRING:
        return "STRING";
    case INTEGER:
        return "INTEGER";
    case BOOLEAN:
        return "BOOLEAN";
    case ARRAY:
        return "ARRAY";
    case OBJECT:
        return "OBJECT";
    default:
        return "ERROR";
    }
}
