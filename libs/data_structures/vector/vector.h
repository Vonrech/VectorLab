#ifndef MAIN_C_VECTOR_H
#define MAIN_C_VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);

void outputVector(vector v);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkRoFit(vector *v);

void deleteVector(vector *v);

bool isEmpty(vector v);

bool isFull(vector v);

int getVectorValue(vector v, size_t i);

void pushBack(vector *v, int x);

void popBack(vector *v);

#endif //MAIN_C_VECTOR_H
