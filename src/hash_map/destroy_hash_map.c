/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-clement-antoine.xavier
** File description:
** destroy_hash_map
*/
#include "../../include/parser_json.h"
#include "../../include/lib.h"

void destroy_hash_map(hashmap_t *map)
{
    delete_token(map, "\"assets\"");
    delete_token(map, "\"detection\"");
    delete_token(map, "\"name\"");
    delete_token(map, "\"attack\"");
    delete_token(map, "\"positionX\"");
    delete_token(map, "\"positionY\"");
    delete_token(map, "\"vitesse\"");
    delete_token(map, "\"life\"");
    delete_token(map, "\"view\"");
    delete_token(map, "\"defence\"");
    delete_token(map, "\"type\"");
    delete_token(map, "\"attaque_0\"");
    delete_token(map, "\"attaque_1\"");
    delete_token(map, "\"puissance_0\"");
    delete_token(map, "\"puissance_1\"");
    delete_token(map, "\"precision_0\"");
    delete_token(map, "\"precision_1\"");
    delete_token(map, "\"pp_0\"");
    delete_token(map, "\"pp_1\"");
    return;
}
