/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <string.h>
    #include <sys/types.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <stddef.h>
    #include <stdint.h>

    #include "parser_json.h"

    float str_to_float(char *str);
    int int_to_str(int32_t num, char* str);
    void float_to_str(float num, char* str, int32_t precision);
    void* re_alloc(void* ptr, size_t size);
    char *my_getch(int a);
    int my_put_nbr(long nb);
    int char_isalpha(char c);
    int char_isdigit(char c);
    int char_isspace(char c);
    int stat_copy(char const *str);
    int my_get_nbr(char const *str);
    char my_putchar(char c, int fd);
    int my_get_key(int a, char *str);
    int my_putstr(char const *str, int fd);
    char **my_str_to_word_array_custom(char *str, char c);


    int len_array(char **array);
    int is_bin(char const *path);
    int is_dir(char const *path);
    char *remove_back_n(char *src);
    int is_same_char(char const *path);
    void print_array(char **array, char c);
    void sort_in_int_array(int *a, int len);
    char *concat_char_str(char concat, char *str, int futur, int a);

    char *open_file_conf(void);
    char *determine_type_var(char *type);
    char *search_token(char *path, char *to_find);

    char *detect_structural_character(char **str);

    void set_json_object_in_hashmap(object_item_t **json_object,
    hashmap_t *map);
    void destroy_hash_map(hashmap_t *map);

    int my_memset_zero(void *buffer, char c, size_t size);
    int my_atoi(char *str);

#endif /* !LIB_H_ */
