#include <stdio.h>
#include <stdlib.h>

struct vector
{
    int *data;
    int size;
    int capacity;
};

void vector_init(struct vector *v)
{
    v->size = 0;
    v->capacity = 4;
    v->data = malloc(sizeof(int) * v->capacity);
}

void vector_push_back(struct vector *v, int value)
{
    if (v->size >= v->capacity)
    {
        v->capacity *= 2;
        v->data = realloc(v->data, sizeof(int) * v->capacity);
    }
    v->data[v->size++] = value;
}

int vector_get(struct vector *v, int index)
{
    if (index >= v->size || index < 0)
    {
        printf("Index out of bounds\n");
        exit(1);
    }
    return v->data[index];
}

void vector_free(struct vector *v)
{
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    free(v);
    v = NULL;
}

int vector_length(struct vector *v)
{
    return v->size;
}

void display(struct vector *v)
{
    for (int i = 0; i < vector_length(v); i++)
    {
        printf("%d ", vector_get(v, i));
    }
    printf("\n");
}

int main()
{
    struct vector *v = malloc(sizeof(struct vector));
    vector_init(v);

    for (int i = 0; i < 10; i++)
    {
        vector_push_back(v, i);
    }

    display(v);

    vector_free(v);
}