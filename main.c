#include <stdio.h>
#include <stdint.h>
#include "List.h"

int main(int argc, char* argv[]) {
    uint64_t cap = 4;
    size_t s = sizeof(int);
    vector* v = vec_init(cap, s);
    int val1 = 1;
    int val2 = 2;
    int val3 = 3;
    int val4 = 4;
    int val5 = 5;
    void* p1 = &val1;
    void* p2 = &val2;
    void* p3 = &val3;
    void* p4 = &val4;
    void* p5 = &val5;
    v->append(p1, v);
    v->append(p2, v);
    v->append(p3, v);
    v->append(p4, v);
    v->append(p5, v);
    v->print(v);
    vector* v2 = vec_init(cap, s);
    printf("%ld\n", v->get_size(v));
    printf("%d\n", v->is_empty(v));
    printf("%d\n", is_empty(v2));
    int* val = pop(v);
    printf("%d\n", *val);
    printf("%ld\n", v->get_size(v));
    return 0;
}