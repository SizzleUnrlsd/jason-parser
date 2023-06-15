/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** new_delete_hashmap
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

hashmap_t *new_hashmap(int size)
{
    hashmap_t *map = malloc(sizeof(hashmap_t));
    map->size = size;
    map->count = 0;
    map->buckets = malloc(sizeof(node_t *) * size);
    if (!map->buckets) {
        return NULL;
    }
    my_memset_zero(map->buckets, 0, sizeof(node_t *) * size);
    return map;
}

void free_hashmap_extend(node_t *current)
{
    while (current) {
        node_t *temp = current;
        current = current->next;
        free(temp->key);
        if (temp->value.type == STRING_VALUE) {
            free(temp->value.string_value);
        }
        free(temp);
    }
    return;
}

void free_hashmap(hashmap_t *map)
{
    for (int i = 0; i < map->size; i++) {
        node_t *current = map->buckets[i];
        free_hashmap_extend(current);
    }
    free(map->buckets);
    free(map);
}
