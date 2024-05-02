#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    int value;
    struct Node *next;
    struct Node *prev;
};

typedef struct
{
    struct Node *head;
    struct Node *tail;
    int size;
    int capacity;
} MRUCache;

MRUCache *MRUCacheCreate(int capacity)
{
    MRUCache *cache = (MRUCache *)malloc(sizeof(MRUCache));
    cache->head = (struct Node *)malloc(sizeof(struct Node));
    cache->tail = (struct Node *)malloc(sizeof(struct Node));
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;

    cache->size = 0;
    cache->capacity = capacity;

    return cache;
}

void MRUCacheAddNode(MRUCache *obj, struct Node *node)
{
    node->next = obj->tail;
    node->prev = obj->tail->prev;
    obj->tail->prev->next = node;
    obj->tail->prev = node;
}

void MRUCacheRemoveNode(struct Node *node)
{
    struct Node *prev = node->prev;
    struct Node *next = node->next;
    prev->next = next;
    next->prev = prev;
}

void MRUCacheMoveToTail(MRUCache *obj, struct Node *node)
{
    MRUCacheRemoveNode(node);
    MRUCacheAddNode(obj, node);
}

void MRUCacheFreeNode(struct Node *node)
{
    free(node);
}

void MRUCachePut(MRUCache *obj, int key, int value)
{
    struct Node *node = obj->head->next;
    while (node != obj->tail)
    {
        if (node->key == key)
        {
            node->value = value;
            MRUCacheMoveToTail(obj, node);
            return;
        }
        node = node->next;
    }

    if (obj->size == obj->capacity)
    {
        struct Node *node = obj->head->next;
        MRUCacheRemoveNode(node);
        MRUCacheFreeNode(node);
        obj->size--;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->key = key;
    new_node->value = value;
    MRUCacheAddNode(obj, new_node);
    obj->size++;
}

int MRUCacheGet(MRUCache *obj, int key)
{
    struct Node *node = obj->head->next;
    while (node != obj->tail)
    {
        if (node->key == key)
        {
            MRUCacheMoveToTail(obj, node);
            return node->value;
        }
        node = node->next;
    }

    return -1;
}

void MRUCacheFree(MRUCache *obj)
{
    struct Node *node = obj->head->next;
    while (node != obj->tail)
    {
        struct Node *temp = node;
        node = node->next;
        MRUCacheFreeNode(temp);
    }

    free(obj->head);
    free(obj->tail);
    free(obj);
}

void display_as_array(MRUCache *obj)
{
    struct Node *node = obj->head->next;
    printf("[");
    while (node != obj->tail)
    {
        printf("[key=%d value=%d], ", node->key, node->value);
        node = node->next;
    }
    printf("\b\b]\n");
}

int main()
{
    MRUCache *cache = MRUCacheCreate(5);

    for (int i = 1; i <= 5; i++)
    {
        MRUCachePut(cache, i, i * 2 + 3);
    }

    display_as_array(cache);

    printf("Getting key 3: %d\n", MRUCacheGet(cache, 3));

    MRUCacheFree(cache);

    return 0;
}
