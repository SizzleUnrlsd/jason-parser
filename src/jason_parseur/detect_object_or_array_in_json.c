/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** detect_object_or_array_in_json
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

void son_dentify_object_or_array_extend(method_t *method, char **bucket,
                                                            char **token)
{
    int32_t(*strlen_lcl)(char const *str) = method->str_m->my_strlen;
    int32_t(*find_string_index_local)(char *json, char *target)
    = method->str_m->find_string_index;
    char *(*extract_substring_lcl)(char *str, uint32_t start, uint32_t end)
    = method->str_m->extract_substring;
    if (find_string_index_local(*bucket, ",\"") != -1) {
        (*token) = extract_substring_lcl
        (*bucket, 0, find_string_index(*bucket, ",\""));
    } else {
        (*token) = extract_substring_lcl
        (*bucket, 0, strlen_lcl(bucket[0]) - 1);
    }
    return;
}

void son_dentify_object_or_array_extend_extend(method_t *method, char **bucket,
                                                                char **token)
{
    int32_t(*strlen_lcl)(char const *str) = method->str_m->my_strlen;
    int32_t(*index_of_char_lcl)(char *str, char c)
    = method->char_m->index_of_char;
    char *(*extract_substring_lcl)(char *str, uint32_t start, uint32_t end)
    = method->str_m->extract_substring;
    if ((index_of_char_lcl(*bucket, ',')) != -1) {
        (*token) = extract_substring_lcl
        (*bucket, 0, index_of_char_lcl(*bucket, ','));
    } else {
        (*token) = extract_substring_lcl
        (*bucket, 0, strlen_lcl(bucket[0]) - 1);
    }
    return;
}

void json_dentify_object_or_array(method_t *method,
                        char **bucket, char **token)
{
    switch (detect_array(bucket)) {
        case true:
            son_dentify_object_or_array_extend(method, bucket, token);
            break;
        default:
            son_dentify_object_or_array_extend_extend(method, bucket, token);
            break;
    }
    return;
}
