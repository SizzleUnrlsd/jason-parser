/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-clement-antoine.xavier
** File description:
** strchr
*/
#include <stddef.h>

char *my_strchr(const char* str, int c)
{
    while (*str != '\0') {
        if (*str == c) {
            return (char*)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char*)str;
    }
    return NULL;
}
