/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** count_occurrence
*/
#include "parser_json.h"
#include "lib.h"

uint32_t count_occurrences(char* str, char* target)
{
    uint32_t count = 0;
    char* pos = my_strstr(str, target);
    while (pos != NULL) {
        count++;
        pos = my_strstr(pos + 1, target);
    }
    return count;
}
