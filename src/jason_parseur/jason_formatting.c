/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** jason_formating
*/
#include "../../include/parser_json.h"

char *json_formatting(method_t *method, char *bucket)
{
    bool let_print = false;
    uint_fast32_t i = 0, e = 0;
    uint_fast32_t len_bucket = method->str_m->my_strlen(bucket);
    char *format_bucket = malloc(sizeof(char) * (len_bucket));

    if (!format_bucket) {
        exit(84);
    }

    do {
        if (bucket[i] == '"' && let_print == false)
            let_print = true;
        else if (bucket[i] == '"' && let_print == true)
            let_print = false;
        if ((bucket[i] == '\t' || bucket[i] == '\n' || bucket[i] == ' ')
        && let_print == false) {
            i++;
            continue;
        } else {
            format_bucket[e] = bucket[i];
            e++; i++; continue;
        }
        format_bucket[e] = bucket[i];
        e++;
        i++;
    } while (bucket[i] != '\0');
    format_bucket[e] = '\0';
    return format_bucket;
}
