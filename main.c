#include <stdio.h>
#include <stdint.h>
#include "List.h"

typedef struct test {
    int size;
    int height;
} test;

int myComp(void* a, void* b) {
    int ai = *(const int*)a;
    int bi = *(const int*)b;
    return (ai > bi) - (ai < bi);
}

int main(int argc, char* argv[]) {

    uint64_t cap = 8;
    size_t bytes = sizeof(test*);
    vector v  = init(cap, bytes);

    for (int i = 0; i < 15; i++) {
        test t1 = {
            t1.height = 10 + 5*i,
            t1.size = 20 + 19-3*i
        };
        append(v, &t1);
    }

    test n1 = {
        n1.height = -100,
        n1.size = -100
    };

    replace(v, 0, &n1);
    addAtIndex(v, 0, &n1);

    for (int i = 0; i < getSize(v); i++) {
        test* t = getItemAtIndex(v, i);
        
        printf("adr:%p\tsize:%d\theight:%d\n", t, t->size, t->height);
    }
    destroy(v);


    /*
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
    int v8 = 9;
    front(v, v8);
    int v9 = 10;
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

    deleteFront(v);
    deleteFront(v);
    deleteFront(v);
    deleteFront(v);
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


    printf("\n\n -------- SORTED --------\n\n");
    printf("%ld\n\n", get_size(v) - 1);
    sort(v, myComp, 0, get_size(v) - 1);
    print(v);
    destroy(v);
    */
    return 0;
}