#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct vector vector;
typedef void (*v_func)(vector*);
typedef void* (*vp_func)(vector*);
typedef void (*func)(void*, vector*);
typedef size_t (*s_func)(vector*);
typedef bool (*b_func)(vector*);


typedef struct vector_impl {
    uint64_t size;
    uint64_t capacity;
    void** item_list;
    size_t bytes;
} vector_impl;

typedef struct vector {
    vector_impl vec;
    func append;
    func front;
    v_func destroy;
    v_func print;
    s_func get_size;
    b_func is_empty;
    vp_func pop;


} vector;

vector* vec_init(uint64_t size, size_t bytes);
void append(void* item,  vector* vec);
void print(vector* vec);
size_t get_size(vector* vec);
bool is_empty(vector* vec);
void* pop(vector* vec);
void front(void* item, vector* vec);
void destroy(vector* vec);



#endif // LIST_H