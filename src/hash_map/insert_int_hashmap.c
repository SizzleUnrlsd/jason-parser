/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** insert_type_hashmap
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

void insert_int_extend(const char *key, int value,
node_t *new_node, node_t *current)
{
    while (current->next) {
        if (my_strcmp(current->key, key) == 0) {
            current->value.type = INT_VALUE;
            current->value.int_value = value;
            free(new_node->key);
            free(new_node);
            return;
        }
        current = current->next;
    }
    return;
}

void insert_int(hashmap_t *map, const char *key, int value)
{
    unsigned int index = hash(key, map->size);
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = my_strdup(key);
    new_node->value.type = INT_VALUE;
    new_node->value.int_value = value;
    new_node->next = NULL;
    if (!map->buckets[index]) {
        map->buckets[index] = new_node;
        map->count++;
        return;
    }
    node_t *current = map->buckets[index];
    insert_int_extend(key, value, new_node, current);
    if (my_strcmp(current->key, key) == 0) {
        current->value.type = INT_VALUE;
        current->value.int_value = value;
        free(new_node->key);
        free(new_node);
    } else
        current->next = new_node;
}
