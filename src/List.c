#include <List.h>

#define SWAP_FAIL -1

/* Definition of the internal structure for the vector, including its size, capacity,
 * an array of pointers to elements, and the size of each element. */
typedef struct vector_impl {
    size_t size;        // Current number of elements in the vector
    size_t capacity;    // Maximum number of elements before resizing is needed
    void** item_list;   // Array of pointers to the elements
    size_t bytes;       // Size of each element in bytes
} vector_impl;

vector init(const size_t capacity, const size_t bytes) {
    vector_impl* vec_handler = malloc(sizeof(vector_impl));
    if (vec_handler == NULL) {
        return NULL;
    }
    vec_handler->bytes = bytes;
    vec_handler->item_list = malloc(sizeof(void*) * capacity);
    if (vec_handler->item_list == NULL) {
        free(vec_handler);
        return NULL;
    }

    vec_handler->size = 0;
    vec_handler->capacity = capacity;
    return (vector) vec_handler;
}

status resize(vector vec) {
    vec->item_list = realloc(vec->item_list,
     2 * (vec->capacity) * sizeof(void*));
    if (vec->item_list == NULL) {
        return OUT_OF_MEMORY;
    }
    vec->capacity *= 2;
    return OK;
}

status checkForResize(vector vec) {
    if (vec->size == vec->capacity) {
        return resize(vec);
    }
    return OK;
}

status append(vector vec, const void* item) {
    status s;
    if ((s = checkForResize(vec)) != OK) {
        return s;
    }
    void* new_item = malloc(vec->bytes);
    if (new_item == NULL) {
        return OUT_OF_MEMORY;
    }
    memmove(new_item, item, vec->bytes);
    vec->item_list[vec->size++] = new_item;
    return OK;
}

status front(vector vec, const void* item) {
    status s;
    if ((s = checkForResize(vec)) != OK) {
        return s;
    }
    for (int i = vec->size - 1; i >= 0; i--) {
        vec->item_list[i + 1] = vec->item_list[i];
        vec->item_list[i] = NULL;
    }

    void* new_item = malloc(vec->bytes);
    if (new_item == NULL) {
        return OUT_OF_MEMORY;
    }

    memmove(new_item, item, vec->bytes);
    vec->item_list[0] = new_item;
    vec->size++;
    return OK;
}

status addAtIndex(vector vec, const size_t index, void* item) {
    status s;
    if (index >= vec->size) {
        return append(item, vec);
    }

    if (index <= 0) {
        return front(vec, item);

    }
    if ((s = checkForResize(vec)) != OK) {
        return s;
    }
    for (int i = vec->size; i >= index; i--) {
        vec->item_list[i + 1] = vec->item_list[i];
        vec->item_list[i] = NULL;
    }

    void* new_item = malloc(vec->bytes);
    if (new_item == NULL) {
        return OUT_OF_MEMORY;
    }
    memmove(new_item, item, vec->bytes);
    vec->item_list[index] = new_item;
    vec->size++;
    return OK;
}

status replace(vector vec, size_t index, void* item) {
    if (index >= vec->size) {
        return append(item, vec);
    }
    void* new_item = malloc(vec->bytes);
    if (new_item == NULL) {
        return OUT_OF_MEMORY;
    }
    memmove(new_item, item, vec->bytes);
    free(vec->item_list[index]);
    vec->item_list[index] = new_item;
    return OK;
}

void destroy(vector vec) {
    for (int i = 0; i < vec->size; i++) {
        free(vec->item_list[i]);
    }
    free(vec->item_list);
    free(vec);
}

void* pop(vector vec) {
    if (vec->size == 0) {
        return NULL;
    }
    vec->size--;
    void* item = vec->item_list[vec->size];
    return item;
}

status deleteFront(vector vec) {
    if (vec->size == 0) {
        return EMPTY_VECTOR;
    }
    free(vec->item_list[0]);

    for (int i = 1; i < vec->size; i++) {
        vec->item_list[i - 1] = vec->item_list[i];
    }

    vec->size--;
    return OK;
}

status deleteBack(vector vec) {
    if (vec->size == 0) {
        return EMPTY_VECTOR;
    }
    free(vec->item_list[vec->size - 1]);
    vec->size--;
    return OK;
}

status shrink(vector vec) {
    vec->item_list = realloc(vec->item_list,vec->size * sizeof(void*));
    if (vec->item_list == NULL) {
        return OUT_OF_MEMORY;
    }
    vec->capacity = vec->size;
    return OK;
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
        return NULL;
    }

    for (int i = 0; i < vec->size; i++) {
        void* item_copy = malloc(vec->bytes);
        if (item_copy == NULL) {
            destroy(v_copy);
            return NULL;
        }
        memmove(item_copy, vec->item_list[i], vec->bytes);
        i_copy[i] = item_copy;
    }
    v_copy->item_list = i_copy;

    return v_copy;
}

void reverse(vector vec) {
    if (vec->size <= 1) {
        return;
    }
    void* temp;

    for (int i = 0; i < (vec->size) / 2; i++) {
        temp = vec->item_list[i];
        vec->item_list[i] = vec->item_list[vec->size - 1 - i];
        vec->item_list[vec->size - 1 - i] = temp;
    }
}

bool contains(const vector vec, const void* item) {
    for (int i = 0; i < vec->size; i++) {
        if (item == vec->item_list[i]) {
            return true;
        }
    }
    return false;
}

void* getItemAtIndex(const vector vec, const size_t index) {
    if (index > vec->size) {
        return vec->item_list[index];
    }
    return vec->item_list[index];
}

size_t getSize(const vector vec) {
    return vec->size;
}

size_t getCapacity(const vector vec) {
    return vec->capacity;
}

bool isEmpty(const vector vec) {
    return vec->size == 0;
}

void print(const vector vec) {
    printf("[");
    for (int i = 0; i < vec->size; i++) {
        if (vec->item_list[i] == NULL) {
            printf("%s, ", "NULL");
        }
        printf("%s, ", vec->item_list[i]);
    }
    printf("]");
}

void printi(const vector vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("%d ", *(int*)vec->item_list[i]);
    }
}

status swap(void* a, void* b, const size_t bytes) {
    void* temp = malloc(bytes);

    if (temp == NULL) {
        return OUT_OF_MEMORY;
    }

    memmove(temp, a, bytes);
    memmove(a, b, bytes);
    memmove(b, temp, bytes);

    free(temp);
    return OK;
}

int partition(vector vec, const compare c, int low, int high) {
    
    void* pivot = vec->item_list[low];
    int i = low;
    int j = high;
    size_t bytes = vec->bytes;

    while (i < j) {
        while (c(vec->item_list[i], pivot) <= 0) {
            i++;
        }

        while (c(vec->item_list[j], pivot) > 0) {
            j--;
        }

        if (i < j) {
            if (swap(vec->item_list[i], vec->item_list[j], bytes) != OK) {
                return SWAP_FAIL;
            }
        }

    }

    if (swap(vec->item_list[j], vec->item_list[low], bytes) != OK) {
        return SWAP_FAIL;
    }

    return j;
}

void sort(vector vec, const compare c, int low, int high) {
    if (low < high) {
        int j = partition(vec, c, low, high);
        if(j == SWAP_FAIL) {
            return;
        }
        sort(vec, c, low, j - 1);
        sort(vec, c, j + 1, high);
    }
}
