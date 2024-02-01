#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct vector vector;
typedef void (*v_func)(vector*);
typedef void (*func)(void*, vector*);


typedef struct vector_impl {
    uint64_t size;
    uint64_t capacity;
    void** item_list;
    size_t bytes;
} vector_impl;

typedef struct vector {
    vector_impl vec;
    func append;
    v_func print;
} vector;

vector* vec_init(uint64_t size, size_t bytes);
void append(void* item,  vector* vec);
void print(vector* vec);
size_t get_size(vector* vec);
bool is_empty(vector* vec);



#endif // LIST_H