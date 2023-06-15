/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** json_parser
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

hashmap_t *json_parser(char *path)
{
    uint32_t loop = 500;
    hashmap_t *map = new_hashmap(500);
    method_t *method = constructor_method();
    object_item_t **json_object = malloc(sizeof(object_item_t *) * loop);
    int32_t stat_relative_path = method->file->stat_copy(path);

    if (!map || !method || !json_object || stat_relative_path == -1) {
        exit(84);
    }

    char *bucket = malloc(sizeof(char) * (stat_relative_path + 1));
    if (!bucket) {
        exit(84);
    }

    method->file->read_file(method->file->open_file(path),
    bucket, stat_relative_path);
    bucket[stat_relative_path] = '\0';

    char *format_bucket = json_formatting(method, bucket);
    json_object = parser_json(json_object, method, &format_bucket, 500);

    set_json_object_in_hashmap(json_object, map);
    return map;
}
