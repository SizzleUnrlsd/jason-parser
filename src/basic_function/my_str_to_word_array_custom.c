/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-BSQ-hugo.payet
** File description:
** my_str_to_word_array_custom
*/
#include "../../include/lib.h"

int funct_count(char *str, char c)
{
    int i = 0, e = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            e++;
        i++;
    }
    return (e);
}

char **funct_malloc(char *str, char c, char **array)
{
    int i = 0, n = 0, a = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            array[a] = malloc(sizeof(char) * (n + 1));
            array[a][n] = '\0';
            a++;
            n = 0;
            i++;
        } else {
            n++;
            i++;
        }
    }
    array[a] = malloc(sizeof(char) * (n + 1));
    array[a][n] = '\0';
    return (array);
}

char **funct_add_char(char *str, char c, char **array)
{
    int i = 0, n = 0, a = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            n = 0;
            a++;
            i++;
        } else {
            array[a][n] = str[i];
            n++;
            i++;
        }
    }
    array[a][n] = str[i];
    return (array);
}

char **my_str_to_word_array_custom(char *str, char c)
{
    int stock = funct_count(str, c);
    char **array = (char**)malloc(sizeof(char*) * (stock + 2));
    array = funct_malloc(str, c, array);
    array = funct_add_char(str, c, array);
    array[stock + 1] = NULL;

    return (array);
}
