#include "vector.h"
#include "stdio.h"

vector createVector(size_t n) {
    vector v;
    v.capacity = n;
    v.size = 0;
    v.data = (int *) malloc(sizeof(int) * v.capacity);

    if (v.capacity == n)
        return v;
    else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void outputVector(vector v) {
    for (int i = 0; i < v.size; i++)
        printf("%d ", v.data[i]);
    printf("\n");
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;

    if (newCapacity < v->size)
        v->size = newCapacity;

    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkRoFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector v) {
    return v.size == 0 ? 1 : 0;
}

bool isFull(vector v) {
    return v.size == v.capacity ? 1 : 0;
}

int getVectorValue(vector v, size_t i) {
    return v.data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(*v)) {
        if (v->capacity == 0)
            reserve(v, 1);
        else
            reserve(v, v->capacity * 2);

    }

    v->size++;
    v->data[v->size-1] = x;
}

void popBack(vector *v) {
    if (v->size > 0)
        v->size--;
}