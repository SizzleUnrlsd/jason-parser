/*
** EPITECH PROJECT, 2023
** parser_json
** File description:
** jason_struct
*/

#ifndef JASON_STRUCT_H_
    #define JASON_STRUCT_H_
    #include <stdint.h>

    typedef struct file_s {
        int32_t (*open_file)(char *path);
        int32_t (*read_file)(int32_t fd, char *buffer, size_t nbytes);
        int32_t (*stat_copy)(char const *str);
    } file_t;

    int32_t open_file(char *path);
    int32_t read_file(int32_t fd, char *buffer, size_t nbytes);
    int32_t stat_copy(char const *str);

    typedef struct str_s {
        int32_t (*my_strlen)(char const *str);
        char *(*my_strdup)(char const *src);
        char *(*my_strcpy)(char *dest, char const *src);
        char *(*my_strcat)(char *dest, char const *src);
        int32_t (*my_strcmp)(char const *s1, char const *s2);
        char *(*my_strncpy)(char *dest, char const *src, int n);
        int32_t (*my_strncmp)(char const *s1, char const *s2, int n);
        char *(*my_strstr)(const char *haystack, const char *needle);
        int32_t (*find_string_index)(char* json, char* target);
        char *(*extract_substring) \
        (char *source, uint32_t start_index, uint32_t end_index);
    } str_t;

    int my_strlen(char const *str);
    char *my_strdup(char const *src);
    char *my_strcpy(char *dest, char const *src);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strncpy(char *dest, char const *src, int n);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strchr(const char* str, int c);
    char *my_strstr(const char *haystack, const char *needle);
    int32_t find_string_index(char* json, char* target);
    char *extract_substring \
    (char *source, uint32_t start_index, uint32_t end_index);

    typedef struct char_s {
        int (*char_isdigit)(char c);
        bool (*is_char)(char **str, char c);
        bool (*is_delimiter)(char c);
        int (*index_of_char)(char *str, char c);
    } char_t;

    bool is_char(char **str, char c);
    bool is_delimiter(char c);
    int index_of_char(char *str, char c);


    typedef struct memory_s {
        void *(*re_alloc)(void* ptr, size_t size);
        void *(*my_memcpy)(void *dest, const void *src, size_t n);
    } memory_t;

    void* re_alloc(void* ptr, size_t size);
    void *my_memcpy(void *dest, const void *src, size_t n);

    typedef struct method_s {
        file_t *file;
        str_t *str_m;
        char_t *char_m;
        memory_t *memory;
    } method_t;

    typedef struct object_item_s {
        char *key;
        char *value;
        char *type;
        struct jason_array_s *array;
        struct object_item_s **token;
        uint32_t occurence;
        char padded[4];
    } object_item_t;

    typedef struct jason_array_s {
        struct object_item_s **object;
        struct jason_array_s *array;
        char *value;
        char *type;
        union data {
            char *str;
            int32_t *i;
        }data;
        union len_data{
            int32_t len_integer_array;
            int32_t len_string_array;
        }len_data;
        int32_t len_array;
    } jason_array_t;

    enum object {
        STRING = 0,
        OBJECT = 1,
        ARRAY = 2,
        FLOAT = 3,
        INTEGER = 4,
        BOOLEAN = 5,
        NONE = 6,
        ROOM = 7,
    };

    typedef struct intarray_s {
        int* numbers;
        int length;
        char padded[4];
    } intarray_t;


#endif /* !JASON_STRUCT_H_ */
