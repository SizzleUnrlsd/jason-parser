/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-clement-antoine.xavier
** File description:
** extension_function_formatage
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"
#include <stdarg.h>
#include <string.h>

void get_intf_extend_extend(int tmp_num, int *index, char *buffer)
{
    do {
        buffer[(*index)--] = '0' + (tmp_num % 10);
        tmp_num /= 10;
    } while (tmp_num != 0);
    return;
}

void get_intf_extend(int num, int temp_num, int *num_digits)
{
    if (num == 0) {
        (*num_digits) = 1;
    } else {
        while (temp_num != 0) {
            (*num_digits)++;
            temp_num /= 10;
        }
    }
    return;
}
