#include "vector.h"

vector createVector(size_t n) {
    int *data;
    if (!(data = (int *) malloc(sizeof(int) * n))) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int *) malloc(v->capacity * sizeof(int));
    if (!v->data) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else if (newCapacity == 0) {
        v->data = NULL;
        v->size = newCapacity;
    } else if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(v)) {
        if (v->capacity == 0)
            reserve(v, 1);
        else
            reserve(v, v->capacity * 2);
    }
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "empty vector ");
        exit(1);
    }
    v->size--;
}

int *atVector(vector *v, size_t index) {
    if (v->size <= index) {
        fprintf(stderr, "IndexError: a[%d] is not exists", index);
        exit(1);
    }
    return &v->data[index]; // или так v->data + index
}

int *back(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector empty");
        exit(1);
    }
    return v->data + v->size - 1;
}

int *front(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector empty");
        exit(1);
    }
    return v->data;
}