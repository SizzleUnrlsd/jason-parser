/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** read
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

int32_t read_file(int32_t fd, char *buffer, size_t nbytes)
{
    int32_t size = read(fd, buffer, nbytes);
    if (size == -1)
        return 84;
    close(fd);
    return size;
}
