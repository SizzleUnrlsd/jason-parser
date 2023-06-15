/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** init_constructor
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

file_t *constructor_file(void)
{
    file_t *file = malloc(sizeof(file_t));
    if (file == NULL)
        return NULL;
    *file = (file_t) {
        .open_file = &open_file,
        .read_file = &read_file,
        .stat_copy = &stat_copy
    };
    return file;
}

str_t* constructor_str(void)
{
    str_t* str_method = malloc(sizeof(str_t));
    if (str_method == NULL)
        return NULL;
    *str_method = (str_t) {
        .my_strlen = &my_strlen,
        .my_strdup = &my_strdup,
        .my_strcpy = &my_strcpy,
        .my_strcat = &my_strcat,
        .my_strcmp = &my_strcmp,
        .my_strncpy = &my_strncpy,
        .my_strncmp = &my_strncmp,
        .my_strstr = &my_strstr,
        .find_string_index = &find_string_index,
        .extract_substring = &extract_substring
    };
    return str_method;
}

char_t *constructor_char(void)
{
    char_t *char_method = malloc(sizeof(char_t));
    if (char_method == NULL)
        return NULL;
    *char_method = (char_t) {
        .char_isdigit = &char_isdigit,
        .is_char = &is_char,
        .is_delimiter = &is_delimiter,
        .index_of_char = &index_of_char
    };
    return char_method;
}

memory_t *constructor_memory(void)
{
    memory_t *memory = malloc(sizeof(memory_t));
    if (memory == NULL)
        return NULL;
    *memory = (memory_t) {
        .re_alloc = &re_alloc,
        .my_memcpy = &my_memcpy
    };
    return memory;
}

method_t *constructor_method(void)
{
    method_t *method = malloc(sizeof(method_t));
    if (method == NULL)
        return NULL;
    *method = (method_t) {
        .file = constructor_file(),
        .str_m = constructor_str(),
        .char_m = constructor_char(),
        .memory = constructor_memory()
    };
    return method;
}
