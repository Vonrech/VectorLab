#include "vector.h"
#include "stdio.h"

vector createVector(size_t n) {
    if (n <= sizeof(int)) {
        int b[n];
        vector a = {b, 0, n};
        return a;
    } else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void reserve(vector *v, size_t newCapacity){
    if (newCapacity == 0)
        v->data = NULL;

    if (newCapacity < v->size)
        v->size = newCapacity;

    v->capacity = newCapacity;
}

void clear(vector *v){
    v->size = 0;
}

void shrinkRoFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v){
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}
