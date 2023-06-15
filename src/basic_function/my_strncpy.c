/*
** EPITECH PROJECT, 2022
** strncpy.c
** File description:
** task02
*/
#include "../../include/lib.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;
    int src_len = 0;

    while (src[src_len] != '\0') {
        src_len++;
    }
    if (n > src_len) {
        while (src_len > a) {
            dest[a] = src[a];
            a++;
        }
        dest[a] = '\0';
    } else {
        while (a < n) {
            dest[a] = src[a];
            a++;
        }
    }
    return (dest);
}
