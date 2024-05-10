#include <stdio.h>
#include <stdlib.h>

#define SIZE_INCREMENT 10

typedef struct
{
    int *array;
    int size;
    int capacity;
} ArrayList;

ArrayList *create_array_list()
{
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->size = 0;
    list->capacity = SIZE_INCREMENT;
    list->array = (int *)malloc(sizeof(int) * list->capacity);
    return list;
}

void free_list(ArrayList *list)
{
    free(list->array);
    free(list);
}

void add(ArrayList *list, int value)
{
    if (list->size == list->capacity)
    {
        list->capacity += SIZE_INCREMENT;
        list->array = (int *)realloc(list->array, sizeof(int) * list->capacity);
    }
    list->array[list->size++] = value;
}

int get(ArrayList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return -1;
    }
    return list->array[index];
}

void set(ArrayList *list, int index, int value)
{
    if (index < 0 || index >= list->size)
    {
        return;
    }
    list->array[index] = value;
}

void remove_at(ArrayList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return;
    }
    for (int i = index; i < list->size - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
}

void print(ArrayList *list)
{
    printf("[");
    for (int i = 0; i < list->size; i++)
    {
        printf("%d, ", list->array[i]);
    }
    printf("\b\b]\n");
}

int size(ArrayList *list)
{
    return list->size;
}

int pop(ArrayList *list)
{
    if (list->size == 0)
    {
        return -1;
    }
    return list->array[--list->size];
}

int main()
{
    ArrayList *list = create_array_list();

    int temp = 3;
    while (temp-- != -1)
    {
        for (int i = 0; i < 20; i++)
        {
            add(list, i);
        }

        for (int i = 0; i < 10; i++)
        {
            pop(list);
        }
    }

    print(list);

    set(list, 0, 100);

    free_list(list);

    return 0;
}
