/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** parse_string
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

intarray_t parse_string(const char* input)
{
    int *numbers = malloc(sizeof(int_fast32_t) * (my_strlen(input)));
    int_fast32_t numbers_count = 0; int_fast32_t current_number = 0;
    bool was_delimiter = true;
    uint_fast32_t len_input = (uint_fast32_t)my_strlen(input);
    for (uint_fast32_t i = 0; i < len_input; i++) {
        if (!is_delimiter(input[i])) {
            current_number = current_number * 10 + (input[i] - '0');
            was_delimiter = false; continue;
        }
        if (!was_delimiter) {
            numbers[numbers_count++] = current_number;
            current_number = 0;
            was_delimiter = true;
        }
    }
    if (!was_delimiter)
        numbers[numbers_count++] = current_number;
    numbers = re_alloc(numbers, numbers_count * sizeof(int));
    intarray_t result = {.numbers = numbers, .length = numbers_count};
    return result;
}
