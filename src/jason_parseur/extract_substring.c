/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** extract_substring
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

char *extract_substring(char *source, uint32_t start_index, uint32_t end_index)
{
    uint32_t j = 0;
    char *result = malloc(sizeof(char) * (end_index + 2));
    if (result == NULL)
        return NULL;
    for (uint32_t i = start_index; i <= end_index; i++) {
        result[j] = source[i];
        j++;
    }
    result[j] = '\0';
    return result;
}
