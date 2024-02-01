#include <List.h>

vector* vec_init(uint64_t capacity, size_t bytes) {
    vector* vec_handler = malloc(sizeof(vector));
    if (vec_handler == NULL) {
        return NULL;
    }
    vec_handler->vec.bytes = bytes;
    vec_handler->vec.item_list = malloc(sizeof(void*) * capacity);
    if (vec_handler->vec.item_list == NULL) {
        return NULL;
    }

    vec_handler->vec.size = 0;
    vec_handler->vec.capacity = capacity;
    vec_handler->append = append;
    vec_handler->print = print;
    return vec_handler;
}

void append(void* item, vector* vec) {
    if (vec->vec.size == vec->vec.capacity) {
        vec->vec.item_list = realloc(vec->vec.item_list, 2 * (vec->vec.capacity) * sizeof(void*));
        if (vec->vec.item_list == NULL) {
            return;
        }
        vec->vec.capacity *= 2;

    }
    void* new_item = malloc(vec->vec.bytes);
    memmove(new_item, item, vec->vec.bytes);
    vec->vec.item_list[vec->vec.size++] = new_item;
}

void print(vector* vec) {
    for (int i = 0; i < vec->vec.size; i++) {
        printf("%p\n", vec->vec.item_list[i]);
    }
}

