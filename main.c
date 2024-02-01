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
    
    return 0;
}