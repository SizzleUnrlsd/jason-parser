/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** find_endchar_index_array
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

int32_t find_end_char_index_spe_array(char *jsonStr, int start,
                                                const char end)
{
    int32_t bracket_count = 0;
    const char modif = '[';
    jsonStr[start] = modif;
    uint_fast32_t len_json_str = (uint_fast32_t)my_strlen(jsonStr);
    for (uint_fast32_t i = 0; i < len_json_str; i++) {
        (jsonStr[i] == modif) ? bracket_count++ : 0;
        (jsonStr[i] == end) ? bracket_count-- : 0;
        if (bracket_count == 0) {
            jsonStr[start] = '"';
            return i;
        }
    }
    return -1;
}
