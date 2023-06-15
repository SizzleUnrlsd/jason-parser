/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** jason_parseur
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

void format_result(char **result)
{
    uint_fast32_t len_result = my_strlen(result[0]);
    if (result[0][len_result - 1] == '}')
        result[0][len_result - 1] = '\0';
    return;
}

void parser_json_extend(object_item_t **item, method_t *method,
                                    char **bucket, uint32_t i)
{
    if (my_strcmp(item[i]->type, "ARRAY") != 0)
        format_result(&item[i]->value);
    if (my_strcmp(item[i]->type, "ARRAY") == 0) {
        item[i]->array =
        token_array(bucket, method, item[i]->array, item[i]->key);
    }
    return;
}

object_item_t **parser_json(object_item_t **item, method_t *method,
                            char **bucket, uint32_t occurence)
{
    char *token = NULL; uint_fast32_t static_count = 0;
    for (uint_fast32_t i = 0; i != occurence; i++) {
        if (*bucket == NULL)
            return (*bucket == NULL) ? (item[static_count] = NULL, item) : 0;
        static_count++;
        item[i] = malloc(sizeof(object_item_t));
        (bucket[0][0] == '{' ? is_char(bucket, '{') : 0);
        json_dentify_object_or_array(method, bucket, &token);
        parse_key_value(token, &item[i]->key, &item[i]->value);
        item[i]->type = detect_structural_character(&item[i]->value);
        parser_json_extend(item, method, bucket, i);
        if (*bucket == NULL)
            return (*bucket == NULL) ? (item[static_count] = NULL, item) : 0;
        *bucket = my_strstr(*bucket, ",");
        *bucket != NULL && bucket[0][0] == ',' ? is_char(bucket, ',') : 0;
    }
    item[occurence] = NULL;
    return item;
}
