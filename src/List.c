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
    vec_handler->pop = pop;
    vec_handler->is_empty = is_empty;
    vec_handler->get_size = get_size;
    vec_handler->destroy = destroy;
    vec_handler->front = front;
    return vec_handler;
}

void resize(vector* vec) {
    vec->vec.item_list = realloc(vec->vec.item_list,
     2 * (vec->vec.capacity) * sizeof(void*));
    if (vec->vec.item_list == NULL) {
        return;
    }
    vec->vec.capacity *= 2;
}

void check_for_resize(vector* vec) {
    if (vec->vec.size == vec->vec.capacity) {
    resize(vec);
    }
}

void append(void* item, vector* vec) {
    check_for_resize(vec);
    void* new_item = malloc(vec->vec.bytes);
    if (new_item == NULL) {
        return;
    }
    memmove(new_item, item, vec->vec.bytes);
    vec->vec.item_list[vec->vec.size++] = new_item;
}

void front(void* item, vector* vec) {
    check_for_resize(vec);
    for (int i = vec->vec.size - 1; i >= 0; i--) {
        vec->vec.item_list[i + 1] = vec->vec.item_list[i];
        vec->vec.item_list[i] = NULL;
    }

    void* new_item = malloc(vec->vec.bytes);
    if (new_item == NULL) {
        return;
    }

    memmove(new_item, item, vec->vec.bytes);
    vec->vec.item_list[0] = new_item;
    vec->vec.size++;
}

void add_at_index(vector* vec, size_t index, void* item) {
    if (index >= vec->vec.size) {
        append(item, vec);
        return;
    }
    check_for_resize(vec);
    for (int i = vec->vec.size; i >= index; i--) {
        vec->vec.item_list[i + 1] = vec->vec.item_list[i];
        vec->vec.item_list[i] = NULL;
    }

    void* new_item = malloc(vec->vec.bytes);
    if (new_item == NULL) {
        return;
    }
    memmove(new_item, item, vec->vec.bytes);
    vec->vec.item_list[index] = new_item;
    vec->vec.size++;
}

void replace(vector* vec, size_t index, void* item) {
    if (index >= vec->vec.size) {
        append(item, vec);
        return;
    }
    void* new_item = malloc(vec->vec.bytes);
    if (new_item == NULL) {
        return;
    }
    memmove(new_item, item, vec->vec.bytes);
    free(vec->vec.item_list[index]);
    vec->vec.item_list[index] = new_item;
}

void destroy(vector* vec) {
    for (int i = 0; i < vec->vec.size; i++) {
        free(vec->vec.item_list[i]);
    }
    free(vec->vec.item_list);
    free(vec);
}

void* pop(vector* vec) {
    if (vec->vec.size == 0) {
        return NULL;
    }
    vec->vec.size--;
    void* item = vec->vec.item_list[vec->vec.size];
    void* copy = malloc(vec->vec.bytes);

    if (copy == NULL) {
        return NULL;
    }

    memmove(copy, item, vec->vec.bytes);
    free(item);

    return copy;
}

void deletef(vector* vec) {
    if (!(vec->vec.size > 0)) {
        return;
    }
    free(vec->vec.item_list[0]);

    for (int i = 1; i < vec->vec.size; i++) {
        vec->vec.item_list[i - 1] = vec->vec.item_list[i];
    }

    vec->vec.size--;
}

void deleteb(vector* vec) {
    if(!(vec->vec.size > 0)) {
        return;
    }
    free(vec->vec.item_list[vec->vec.size - 1]);
    vec->vec.size--;
}

void shrink(vector* vec) {
    vec->vec.item_list = realloc(vec->vec.item_list,vec->vec.size * sizeof(void*));
    vec->vec.capacity = vec->vec.size;
}

size_t get_size(vector* vec) {
    return vec->vec.size;
}

bool is_empty(vector* vec) {
    return vec->vec.size == 0;
}

void print(vector* vec) {
    printf("[");
    for (int i = 0; i < vec->vec.size; i++) {
        if (vec->vec.item_list[i] == NULL) {
            printf("%s, ", "NULL");
        }
        printf("%s, ", vec->vec.item_list[i]);
    }
    printf("]");
}

