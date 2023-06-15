/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** index_of_char
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

bool index_of_char_extend(char *str, char c, int *index)
{
    bool access = false;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '"' && access == false) {
            access = true;
            continue;
        }
        if (str[i] == '"' && access == true) {
            access = false;
            continue;
        }
        if (access == false && str[i] == c) {
            *index = i;
            return true;
        }
    }
    return false;
}

int index_of_char(char *str, char c)
{
    int index = 0;
    index_of_char_extend(str, c, &index);
    char *ptr = my_strchr(str, c);

    if (ptr) {
        if ((ptr - str) > index)
            return ptr - str;
        if ((ptr - str) < index)
            return index;
        if ((ptr - str) == index)
            return index;
    } else {
        return -1;
    }
    return -1;
}
