/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** detect_element_array
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

int32_t count_element_in_object(char *bucket)
{
    int32_t count = 0;
    for (uint32_t i = 0; bucket[i]; i++) {
        if (bucket[i] == ':')
            count++;
    }
    return count;
}
