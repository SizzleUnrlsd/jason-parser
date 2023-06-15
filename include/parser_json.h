/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** parser_json
*/

#ifndef PARSER_JSON_H_
    #define PARSER_JSON_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <stddef.h>
    #include <stdarg.h>

    #include "jason_struct.h"
    #include "hash_map_struct.h"

    #define SET_STRCMP int32_t(*strcmp_lcl)(const char *, const char *)
    #define SET_STRSTR char *(*strstr_lcl) \
    (const char *haystack, const char *needle)

    typedef struct hashmap_s hashmap_t;

    char *json_formatting(method_t *method, char *bucket);
    method_t *constructor_method(void);
    method_t *constructor_method(void);
    object_item_t **parser_json(object_item_t **item, method_t *method,
    char **bucket,  uint32_t occurence);
    jason_array_t *token_array(char **str, method_t *method,
    jason_array_t *array, char *first_token);
    int32_t find_end_char_index_spe_array(char *jsonStr, int start,
    const char end);
    bool detect_object_in_array(char *bucket);
    uint32_t count_occurrences(char* str, char* target);
    int32_t count_element_in_object(char *bucket);
    bool is_delimiter(char c);
    int32_t find_string_index(char* json, char* target);
    char *detect_structural_character(char **str);
    bool detect_array(char **bucket);
    void parse_key_value(char *json_str, char **keys, char **val);
    char *token_string(char **str);
    intarray_t parse_string(const char* input);

    void json_dentify_object_or_array(method_t *method,
    char **bucket, char **token);

    int init_hash_map(uint32_t size_map);
    hashmap_t *new_hashmap(int size);
    void insert_in_hash_map(hashmap_t *map, ...);
    void dispay_hash_map(hashmap_t *map);
    void insert_string(hashmap_t *map, const char *key, const char *value);
    void appeal_hashmap(hashmap_t *map, char *key);

    char *get_string(hashmap_t *map, const char *key);
    char *get_stringf(hashmap_t *map, const char* key, ...);
    int get_intf(hashmap_t *map, const char *key, ...);
    void delete_token(hashmap_t *map, const char *key);
    void free_hashmap(hashmap_t *map);
    hashmap_t *json_parser(char *path);

    hashmap_t *new_hashmap(int size);
    void free_hashmap(hashmap_t *map);
    void insert_int(hashmap_t *map, const char *key, int value);
    void insert_string(hashmap_t *map, const char *key, const char *value);
    void insert_array(hashmap_t *map, const char *key,
    const int *data, int size);
    char *get_string(hashmap_t *map, const char *key);
    const int *get_array(hashmap_t *map, const char *key, int *size);
    unsigned int hash(const char *key, int size);
    void get_intf_extend_extend(int tmp_num, int *index, char *buffer);
    void get_intf_extend(int num, int temp_num, int *num_digits);

#endif /* !PARSER_JSON_H_ */
