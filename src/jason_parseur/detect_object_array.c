/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** detect_object_array
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

bool detect_object_in_array(char *bucket)
{
    if (bucket[1] == '{')
        return true;
    return false;
}
