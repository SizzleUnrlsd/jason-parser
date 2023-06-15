/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** set_json_object_in_hashmap
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

void set_json_object_in_hashmap_extend_extend(object_item_t **json_object,
                                    hashmap_t *map, uint_fast32_t i)
{
    if (my_strcmp("BOOLEAN", json_object[i]->type) == 0) {
        insert_in_hash_map(map, json_object[i]->key,
        json_object[i]->value, "STRING", NULL);
        return;
    }
    if (my_strcmp("ARRAY", json_object[i]->type) == 0
    && (my_strcmp("ARRAY OBJECT", json_object[i]->array->type) == 0)
    && json_object[i]->array->type != NULL) {
        for (uint32_t e = 0; json_object[i]->array->object[e] != NULL; e++) {
            set_json_object_in_hashmap(\
            json_object[i]->array->object[e]->token, map);
        }
        return;
    }
    return;
}

void set_json_object_in_hashmap_extend(object_item_t **json_object,
                                    hashmap_t *map, uint_fast32_t i)
{
    if (my_strcmp("ARRAY", json_object[i]->type) == 0
    && (my_strcmp("ARRAY INTEGER", json_object[i]->array->type) == 0)
    && json_object[i]->array->type != NULL) {
        insert_in_hash_map(map, json_object[i]->key,
        json_object[i]->value, "ARRAY", json_object[i]->array->data.i,
        json_object[i]->array->len_data.len_integer_array);
        return;
    }
    if (my_strcmp("STRING", json_object[i]->type) == 0) {
        insert_in_hash_map(map, json_object[i]->key,
        json_object[i]->value, "STRING",  NULL, 0);
        return;
    }
    if (my_strcmp("INTEGER", json_object[i]->type) == 0) {
        insert_in_hash_map(map, json_object[i]->key,
        json_object[i]->value, "INTEGER", NULL, 0);
        return;
    }
    return;
}

void set_json_object_in_hashmap(object_item_t **json_object, hashmap_t *map)
{
    for (uint_fast32_t i = 0; json_object[i] != NULL; i++) {
        set_json_object_in_hashmap_extend(json_object, map, i);
        set_json_object_in_hashmap_extend_extend(json_object, map, i);
    }
    return;
}
