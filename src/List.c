#include <List.h>

vector vec_init(uint64_t capacity, size_t bytes) {
    vector_impl* vec_handler = malloc(sizeof(vector_impl));
    if (vec_handler == NULL) {
        return NULL;
    }
    vec_handler->bytes = bytes;
    vec_handler->item_list = malloc(sizeof(void*) * capacity);
    if (vec_handler->item_list == NULL) {
        return NULL;
    }

    vec_handler->size = 0;
    vec_handler->capacity = capacity;
    return (vector) vec_handler;
}

void resize(vector vec) {
    vec = (vector_impl*) vec;
    vec->item_list = realloc(vec->item_list,
     2 * (vec->capacity) * sizeof(void*));
    if (vec->item_list == NULL) {
        return;
    }
    vec->capacity *= 2;
}

void check_for_resize(vector vec) {
    vec = (vector_impl*) vec;
    if (vec->size == vec->capacity) {
    resize(vec);
    }
}

void append(vector vec, void* item) {
    vec = (vector_impl*) vec;
    check_for_resize(vec);
    void* new_item = malloc(vec->bytes);
    if (new_item == NULL) {
        return;
    }
    memmove(new_item, item, vec->bytes);
    vec->item_list[vec->size++] = new_item;
}

void front(vector vec, void* item) {
    vec = (vector_impl*) vec;
    check_for_resize(vec);
    for (int i = vec->size - 1; i >= 0; i--) {
        vec->item_list[i + 1] = vec->item_list[i];
        vec->item_list[i] = NULL;
    }

    void* new_item = malloc(vec->bytes);
    if (new_item == NULL) {
        return;
    }

    memmove(new_item, item, vec->bytes);
    vec->item_list[0] = new_item;
    vec->size++;
}

void add_at_index(vector vec, size_t index, void* item) {
    vec = (vector_impl*) vec;
    if (index >= vec->size) {
        append(item, vec);
        return;
    }
    check_for_resize(vec);
    for (int i = vec->size; i >= index; i--) {
        vec->item_list[i + 1] = vec->item_list[i];
        vec->item_list[i] = NULL;
    }

    void* new_item = malloc(vec->bytes);
    if (new_item == NULL) {
        return;
    }
    memmove(new_item, item, vec->bytes);
    vec->item_list[index] = new_item;
    vec->size++;
}

void replace(vector vec, size_t index, void* item) {
    vec = (vector_impl*) vec;
    if (index >= vec->size) {
        append(item, vec);
        return;
    }
    void* new_item = malloc(vec->bytes);
    if (new_item == NULL) {
        return;
    }
    memmove(new_item, item, vec->bytes);
    free(vec->item_list[index]);
    vec->item_list[index] = new_item;
}

void destroy(vector vec) {
    vec = (vector_impl*) vec;
    for (int i = 0; i < vec->size; i++) {
        free(vec->item_list[i]);
    }
    free(vec->item_list);
    free(vec);
}

void* pop(vector vec) {
    vec = (vector_impl*) vec;
    if (vec->size == 0) {
        return NULL;
    }
    vec->size--;
    void* item = vec->item_list[vec->size];
    void* copy = malloc(vec->bytes);

    if (copy == NULL) {
        return NULL;
    }

    memmove(copy, item, vec->bytes);
    free(item);

    return copy;
}

void deletef(vector vec) {
    vec = (vector_impl*) vec;
    if (!(vec->size > 0)) {
        return;
    }
    free(vec->item_list[0]);

    for (int i = 1; i < vec->size; i++) {
        vec->item_list[i - 1] = vec->item_list[i];
    }

    vec->size--;
}

void deleteb(vector vec) {
    vec = (vector_impl*) vec;
    if(!(vec->size > 0)) {
        return;
    }
    free(vec->item_list[vec->size - 1]);
    vec->size--;
}

void shrink(vector vec) {
    vec = (vector_impl*) vec;
    vec->item_list = realloc(vec->item_list,vec->size * sizeof(void*));
    vec->capacity = vec->size;
}

vector clone(vector vec) {
    vector v_copy = malloc(sizeof(vector_impl));
    if (v_copy == NULL) {
        return NULL;
    }

    v_copy->bytes = vec->bytes;
    v_copy->capacity = vec->capacity;
    v_copy->size = vec->size;

    void** i_copy = malloc(sizeof(void*) * vec->size);

    if(i_copy == NULL) {
        free(v_copy);
    }

    for (int i = 0; i < vec->size; i++) {
        // TODO free everything if malloc fails.
        void* item_copy = malloc(vec->bytes);
        memmove(item_copy, vec->item_list[i], vec->bytes);
        i_copy[i] = item_copy;
    }
    v_copy->item_list = i_copy;

    return v_copy;
}

size_t get_size(vector vec) {
    vec = (vector_impl*) vec;
    return vec->size;
}

bool is_empty(vector vec) {
    vec = (vector_impl*) vec;
    return vec->size == 0;
}

void print(vector vec) {
    vec = (vector_impl*) vec;
    printf("[");
    for (int i = 0; i < vec->size; i++) {
        if (vec->item_list[i] == NULL) {
            printf("%s, ", "NULL");
        }
        printf("%s, ", vec->item_list[i]);
    }
    printf("]");
}

