/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** get_type_hashmap
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"
#include <stdarg.h>
#include <string.h>

const int *get_array(hashmap_t *map, const char *key, int *size)
{
    unsigned int index = hash(key, map->size);
    node_t *current = map->buckets[index];
    while (current) {
        if (my_strcmp(current->key, key) == 0
        && current->value.type == ARRAY_VALUE) {
            *size = current->value.array_value.size;
            return current->value.array_value.data;
            break;
        }
        current = current->next;
    }
    *size = 0;
    return NULL;
}

__attribute__((always_inline)) inline
int get_int(hashmap_t *map, const char *result)
{
    unsigned int index = hash(result, map->size);
    node_t *current = map->buckets[index];
    while (current) {
        if (my_strcmp(current->key, result) == 0
        && current->value.type == INT_VALUE) {
            return current->value.int_value;
            break;
        }
        current = current->next;
    }
    return -1;
}

int get_intf(hashmap_t *map, const char* key, ...)
{
    char buffer[100]; char *result = NULL; int32_t num = 0;
    int32_t tmp_num = 0; int32_t num_digits = 0; int32_t buffer_index = 0;
    int32_t index = 0; va_list ap; va_start(ap, key);
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] != '%')
            buffer[buffer_index++] = key[i];
        if (key[i] == '%' && key[i + 1] == 'd') {
            num = va_arg(ap, int);
            tmp_num = num;
            num_digits = 0;
            get_intf_extend(num, tmp_num, &num_digits);
            index = buffer_index + num_digits - 1;
            tmp_num = num;
            get_intf_extend_extend(tmp_num, &index, buffer);
            buffer_index += num_digits; i++;
        }
    }
    buffer[buffer_index] = '\0';
    result = my_strdup(buffer); va_end(ap);
    return get_int(map, result);
}

__attribute__((always_inline)) inline
char *get_string(hashmap_t *map, const char *key)
{
    unsigned int index = hash(key, map->size);
    node_t *current = map->buckets[index];

    while (current) {
        if (my_strcmp(current->key, key) == 0) {
            return current->value.type == STRING_VALUE ?
            current->value.string_value : NULL;
        }
        current = current->next;
    }
    return "UNDIFINED";
}

char *get_stringf(hashmap_t *map, const char* key, ...)
{
    char buffer[100]; char *result = NULL; int32_t num = 0;
    int32_t tmp_num = 0; int32_t num_digits = 0; int32_t buffer_index = 0;
    int32_t index = 0; va_list ap; va_start(ap, key);
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] != '%')
            buffer[buffer_index++] = key[i];
        if (key[i] == '%' && key[i + 1] == 'd') {
            num = va_arg(ap, int);
            tmp_num = num;
            num_digits = 0;
            get_intf_extend(num, tmp_num, &num_digits);
            index = buffer_index + num_digits - 1;
            tmp_num = num;
            get_intf_extend_extend(tmp_num, &index, buffer);
            buffer_index += num_digits; i++;
        }
    }
    buffer[buffer_index] = '\0';
    result = my_strdup(buffer); va_end(ap);
    return get_string(map, result);
}
