#include "parser_json.h"

int main(void)
{
    int32_t size = 0;
    hashmap_t *map = json_parser("example.json");
    if (!map) {
        return 84;
    }
    printf("name : %s\n", get_string(map, "\"name\""));
    printf("age : %d\n", get_intf(map, "\"age\""));
    printf("city : %s\n", get_string(map, "\"city\""));
    
    printf("interest :");
    get_array(map, "\"interest\"", &size);
    for (int32_t i = 0; i != size; i++) {
        printf("%d ", get_array(map, "\"interest\"", &size)[i]);
    }

    printf("\ndata : ");
    get_array(map, "\"data\"", &size);
    for (int32_t i = 0; i != size; i++) {
        printf("%d ", get_array(map, "\"data\"", &size)[i]);
    }
    printf("\n");

    printf("width : %d\n", get_intf(map, "\"width\""));
    printf("opacity : %d\n", get_intf(map, "\"opacity\""));
    printf("type : %s\n", get_string(map, "\"type\""));
    printf("id : %d\n", get_intf(map, "\"id\""));
    printf("test : %s\n", get_string(map, "\"test\""));
    return 0;
}
