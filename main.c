#include <stdio.h>
#include <stdint.h>
#include "List.h"

typedef struct test {
    int size;
    int height;
} test;

int main(int argc, char* argv[]) {
    uint64_t cap = 4;
    char* v1 = "aa";
    size_t s = sizeof(strlen(v1) + 1);
    vector* v = vec_init(cap, s);
    char* n10 = "xx";
    char* n1 = "tt";
    char* v2 = "bb";
    char* v3 = "cc";
    char* v4 = "dd";
    char* v5 = "ee";
    char* v6 = "ff";
    char* v7 = "gg";
    v->append(v1, v);
    v->append(v2, v);
    v->append(v3, v);
    v->print(v);
    printf("\n");
    deleteb(v);
    v->print(v);
    printf("\n");
    v->append(v4, v);
    v->append(v5, v);
    v->append(v6, v);
    v->append(v7, v);
    char* v8 = "zz";
    v->front(v8, v);
    char* v9 = "hh";
    add_at_index(v, 5, v9);
    add_at_index(v, 1, v9);
    add_at_index(v, 2, v9);
    add_at_index(v, 3, v9);
    v->append(v1, v);
    v->append(v1, v);
    v->front(v1, v);
    v->front(v1, v);

    v->append(n1, v);
    v->front(n1, v);
    replace(v, 1, n10);
    replace(v, 100, n10);
    deleteb(v);
    deleteb(v);
    replace(v, 5, n10);

    deletef(v);
    deletef(v);
    deletef(v);
    deletef(v);
    replace(v, 1, n10);
    v->append(n10, v);
    v->print(v);
    printf("%ld\n", v->get_size(v));
    printf("%d\n", v->is_empty(v));
    char* val = v->pop(v);
    printf("%s\n", val);
    printf("%ld\n", v->vec.capacity);
    shrink(v);
    printf("%ld\n", v->vec.capacity);
    free(val);

    v->destroy(v);
    return 0;
}