/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** strstr
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

inline char *my_strstr(const char *haystack, const char *needle)
{
    size_t needle_len = my_strlen(needle);
    if (needle_len == 0)
        return (char *) haystack;

    do {
        if (*haystack == *needle)
            if (my_strncmp(haystack, needle, needle_len) == 0)
                return (char *) haystack;
        haystack++;
    } while (*haystack != '\0');

    return NULL;
}
