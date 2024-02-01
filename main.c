#include <stdio.h>
#include <stdint.h>
#include "List.h"

typedef struct test {
    int size;
    int height;
} test;

int main(int argc, char* argv[]) {
    uint64_t cap = 4;
    size_t s = sizeof(int);
    vector* v = vec_init(cap, s);
    char* v1 = "aa";
    char* v2 = "bb";
    char* v3 = "cc";
    char* v4 = "dd";
    char* v5 = "ee";
    char* v6 = "ff";
    char* v7 = "gg";
    v->append(v1, v);
    v->append(v2, v);
    v->append(v3, v);
    v->append(v4, v);
    v->append(v5, v);
    v->append(v6, v);
    v->append(v7, v);
    char* v8 = "zz\0";
    front(v8, v);
    v->print(v);
    printf("%ld\n", v->get_size(v));
    printf("%d\n", v->is_empty(v));
    char* val = v->pop(v);
    printf("%s\n", val);
    printf("%ld\n", v->get_size(v));
    return 0;
}