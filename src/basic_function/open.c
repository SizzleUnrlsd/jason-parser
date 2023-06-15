/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** open
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

// #ifdef OPEN
// int32_t open_file(char *path)
// {
//     FILE **file = malloc(sizeof(FILE *));
//     *file = fopen(path, "r");
//     if (*file == NULL)
//         return 84;
//     return (int32_t) file;
// }
// #else
int32_t open_file(char *path)
{
    int32_t fd = open(path, O_RDONLY);
    if (fd == -1)
        return 84;
    return fd;
}
// #endif
