/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** jsaon_token_array
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

void no_object_in_array(method_t *method, jason_array_t *array,
                                char **str, char *first_token)
{
    char *extract = extract_substring   \
    (*str, 0, find_end_char_index_spe_array(*str, 0, ']'));
    char *analyse_array = my_strdup(extract);
    analyse_array[0] = '[';
    intarray_t int_array = parse_string(extract);
    array->type = "ARRAY INTEGER";
    array->data.i = int_array.numbers;
    array->len_data.len_integer_array = int_array.length;
    (*str) = my_strstr(*str, "]");
    (void)first_token;
    return;
    (void) method;
}

void object_in_array_extend(jason_array_t *array,
uint_fast32_t count_object_in_array, uint32_t element_object, uint_fast32_t i)
{
    array->object[i] =
    malloc(sizeof(object_item_t) * count_object_in_array);
    array->object[i]->token =
    malloc(sizeof(object_item_t) * element_object);


    return;
}

jason_array_t *object_in_array(method_t *method,
                jason_array_t *array, char **str)
{
    char *extract = extract_substring \
    (*str, 0, find_end_char_index_spe_array(*str, 0, ']'));
    *str = my_strstr(*str, "}],"); extract++;
    uint_fast32_t count_object_in_array = count_occurrences(extract, "},{") + 1;
    char *spe_str_for_object = NULL;
    uint32_t element_object = 0;
    array->len_array = count_object_in_array;
    array->type = "ARRAY OBJECT";
    array->object = malloc(sizeof(object_item_t) * count_object_in_array);
    for (uint_fast32_t i = 0; i != count_object_in_array; i++) {
        spe_str_for_object =
        extract_substring(extract, 0, index_of_char(extract, '}'));
        element_object = count_element_in_object(spe_str_for_object);
        object_in_array_extend(array, count_object_in_array, element_object, i);
        parser_json(array->object[i]->token, method, &extract, element_object);
        if (extract == NULL)
            return (extract == NULL) ? (array->object[i + 1] = NULL, array) : 0;
        extract = my_strstr(extract, "{");
    }
    return array;
}

jason_array_t * token_array(char **str, method_t *method,
                jason_array_t *array, char *first_token)
{
    array = malloc(sizeof(jason_array_t));
    (*str) = my_strstr(*str, "[");
    if (find_end_char_index_spe_array(*str, 0, ']') < 2)
        array->value = "NONE";
    if (!detect_object_in_array(*str) &&
    find_end_char_index_spe_array(*str, 0, ']') > 2)
        no_object_in_array(method, array, str, first_token);
    if (detect_object_in_array(*str) &&
    find_end_char_index_spe_array(*str, 0, ']') > 2)
        object_in_array(method, array, str);
    return array;
}
