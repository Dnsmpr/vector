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
    vector v = vec_init(cap, s);
    char* n10 = "xx";
    char* n1 = "tt";
    char* v2 = "bb";
    char* v3 = "cc";
    char* v4 = "dd";
    char* v5 = "ee";
    char* v6 = "ff";
    char* v7 = "gg";
    append(v, v1);
    append(v, v2);
    append(v, v3);
    print(v);
    printf("\n");
    deleteb(v);
    print(v);
    printf("\n");
    append(v, v4);
    append(v, v5);
    append(v, v6);
    append(v, v7);
    char* v8 = "zz";
    front(v, v8);
    char* v9 = "hh";
    add_at_index(v, 5, v9);
    add_at_index(v, 1, v9);
    add_at_index(v, 2, v9);
    add_at_index(v, 3, v9);
    append(v, v1);
    append(v, v1);
    front(v, v1);
    front(v, v1);

    append(v, n1);
    front(v, n1);
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
    append(v, n10);
    print(v);
    printf("%ld\n", get_size(v));
    printf("%d\n", is_empty(v));
    char* val = pop(v);
    printf("%s\n", val);
    printf("%ld\n", get_capacity(v));
    shrink(v);
    printf("%ld\n", get_capacity(v));
    printf("copy -------- \n\n");
    vector ve2 = clone(v);
    replace(ve2, 1, v8);
    print(ve2);
    printf("\n\n-------- real -------- \n\n");
    print(v);
    printf("\n\n-------- reverse -------- \n\n");
    reverse(v);
    print(v);
    free(val);
    destroy(ve2);
    destroy(v);
    return 0;
}