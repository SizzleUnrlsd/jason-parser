/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** insert_array_hashmap
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

void insert_array_extend(const char *key, ...)
{
    va_list ap;
    va_start(ap, key);
    const int *data = va_arg(ap, const int *);
    int size = va_arg(ap, int);
    node_t *new_node = va_arg(ap, node_t *);
    node_t *current = va_arg(ap, node_t *);
    while (current->next) {
        if (my_strcmp(current->key, key) == 0) {
            current->value.type = ARRAY_VALUE;
            free(current->value.array_value.data);
            current->value.array_value.data = malloc(sizeof(int) * size);
            my_memcpy
            (current->value.array_value.data, data, sizeof(int) * size);
            current->value.array_value.size = size;
            (void)new_node;
            return;
        }
        current = current->next;
    }
    va_end(ap);
}

void insert_array_extend_extend(const char *key, ...)
{
    va_list ap;
    va_start(ap, key);
    const int *data = va_arg(ap, const int *);
    int size = va_arg(ap, int);
    node_t *new_node = va_arg(ap, node_t *);
    node_t *current = va_arg(ap, node_t *);
    if (my_strcmp(current->key, key) == 0) {
        current->value.type = ARRAY_VALUE;
        free(current->value.array_value.data);
        current->value.array_value.data = malloc(sizeof(int) * size);
        my_memcpy(current->value.array_value.data, data, sizeof(int) * size);
        current->value.array_value.size = size;
        free(new_node->key);
        free(new_node);
    } else
        current->next = new_node;
    va_end(ap);
    return;
}

void insert_array(hashmap_t *map, const char *key, const int *data, int size)
{
    unsigned int index = hash(key, map->size);
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = my_strdup(key);
    new_node->value.type = ARRAY_VALUE;
    new_node->value.array_value.data = malloc(sizeof(int) * size);
    my_memcpy(new_node->value.array_value.data, data, sizeof(int) * size);
    new_node->value.array_value.size = size;
    new_node->next = NULL;
    if (!map->buckets[index]) {
        map->buckets[index] = new_node;
        map->count++;
        return;
    }
    node_t *current = map->buckets[index];
    insert_array_extend(key, data, size, new_node, current);
    insert_array_extend_extend(key, data, size, new_node, current);
    return;
}
