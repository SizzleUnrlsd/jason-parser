/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** hash_map_struct
*/

#ifndef HASH_MAP_STRUCT_H_
    #define HASH_MAP_STRUCT_H_

    typedef struct value_s {
        union {
            int int_value;
            char *string_value;
            struct {
                int *data;
                int size;
                char padded[4];
            } array_value;
        };
        enum { INT_VALUE, STRING_VALUE, ARRAY_VALUE } type;
        char padded[4];
    } value_s;

    typedef struct node_s {
        char *key;
        value_s value;
        struct node_s *next;
    } node_t;

    typedef struct hashmap_s {
        node_t **buckets;
        int size;
        int count;
    } hashmap_t;

#endif /* !HASH_MAP_STRUCT_H_ */
