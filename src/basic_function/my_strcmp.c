/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-hugo.carolin
** File description:
** my_strcmp
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

int cmp_string(char s1, char s2)
{
    if (s1 < s2) {
        return (-1);
    }
    return (1);
}

__attribute__((always_inline)) inline int
my_strcmp(char const *s1, char const *s2)
{
    uint32_t n = 0;
    uint32_t len_s1 = my_strlen(s1);
    uint32_t len_s2 = my_strlen(s2);

    if (s1[0] == '\0')
        len_s1 = 1;
    else if (s2[0] == '\0')
        len_s2 = 1;

    if (len_s1 != len_s2)
        return (-1);

    while (s1[n] != '\0' && (s2[n]) != '\0') {
        if (s1[n] != s2[n])
            return cmp_string(s1[n], s2[n]);
        n++;
    }
    return (0);
}
