/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** hash_map_json
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void delete_token_extend(hashmap_t *map, node_t *current,
                            node_t *prev, uint32_t index)
{
    if (prev) {
        prev->next = current->next;
    } else {
        map->buckets[index] = current->next;
    }
    free(current->key);
    if (current->value.type == STRING_VALUE) {
        free(current->value.string_value);
    }
    free(current);
    return;
}

void delete_token(hashmap_t *map, const char *key)
{
    uint32_t index = hash(key, map->size);
    node_t *current = map->buckets[index];
    node_t *prev = NULL;
    while (current) {
        if (my_strcmp(current->key, key) == 0) {
            delete_token_extend(map, current, prev, index);
            return;
        }
        prev = current;
        current = current->next;
    }
}

uint32_t hash(const char *key, int size)
{
    unsigned int hash = 5381;
    int c = 0;
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % size;
}

void insert_in_hash_map(hashmap_t *map, ...)
{
    va_list ap;
    va_start(ap, map);
    char *key = va_arg(ap, char*);
    char *value = va_arg(ap, char*);
    char *type = va_arg(ap, char*);
    int *array = va_arg(ap, int*);
    int len_array = va_arg(ap, int);
    if (my_strcmp(type, "INTEGER") == 0)
        insert_int(map, key, my_atoi(value));
    if (my_strcmp(type, "STRING") == 0)
        insert_string(map, key, value);
    if (my_strcmp(type, "ARRAY") == 0) {
        insert_array(map, key, array, len_array);
    }
    va_end(ap);
    return;
}
