#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct HashSet
{
    int size;
    struct Node **table;
};

struct HashSet *create_hash_set(int size)
{
    struct HashSet *hash_set = (struct HashSet *)malloc(sizeof(struct HashSet));
    hash_set->size = size;
    hash_set->table = (struct Node **)malloc(sizeof(struct Node *) * size);
    for (int i = 0; i < size; i++)
    {
        hash_set->table[i] = NULL;
    }
    return hash_set;
}

int hash_code(struct HashSet *hash_set, int key)
{
    if (key < 0)
    {
        return -(key % hash_set->size);
    }
    return key % hash_set->size;
}

void insert(struct HashSet *hash_set, int key)
{
    int index = hash_code(hash_set, key);
    struct Node *list = hash_set->table[index];
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = list;
    while (temp)
    {
        if (temp->data == key)
        {
            return;
        }
        temp = temp->next;
    }
    newNode->data = key;
    newNode->next = list;
    hash_set->table[index] = newNode;
}

void remove_element(struct HashSet *hash_set, int key)
{
    int index = hash_code(hash_set, key);
    struct Node *list = hash_set->table[index];
    struct Node *temp = list;
    struct Node *prev = NULL;
    while (temp)
    {
        if (temp->data == key)
        {
            if (prev)
            {
                prev->next = temp->next;
            }
            else
            {
                hash_set->table[index] = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int contains(struct HashSet *hash_set, int key)
{
    int index = hash_code(hash_set, key);
    struct Node *list = hash_set->table[index];
    struct Node *temp = list;
    while (temp)
    {
        if (temp->data == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void display(struct HashSet *hash_set)
{
    for (int i = 0; i < hash_set->size; i++)
    {
        struct Node *list = hash_set->table[i];
        struct Node *temp = list;
        printf("table[%d] = ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void free_memory(struct HashSet *hash_set)
{
    for (int i = 0; i < hash_set->size; i++)
    {
        struct Node *list = hash_set->table[i];
        struct Node *temp = list;
        while (temp)
        {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(hash_set->table);
    free(hash_set);
}

int main()
{
    struct HashSet *set = create_hash_set(10);

    for (int i = 0; i < 10; i++)
    {
        insert(set, i);
    }

    display(set);

    printf("Contains 5: %d\n", contains(set, 5));

    free_memory(set);
}