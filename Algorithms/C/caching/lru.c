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
} LRUCache;

LRUCache *LRUCacheCreate(int capacity)
{
    LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->head = (struct Node *)malloc(sizeof(struct Node));
    cache->tail = (struct Node *)malloc(sizeof(struct Node));
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;

    cache->size = 0;
    cache->capacity = capacity;

    return cache;
}

void LRUCacheAddNode(LRUCache *obj, struct Node *node)
{
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

void LRUCacheRemoveNode(struct Node *node)
{
    struct Node *prev = node->prev;
    struct Node *next = node->next;
    prev->next = next;
    next->prev = prev;
}

void LRUCacheMoveToHead(LRUCache *obj, struct Node *node)
{
    LRUCacheRemoveNode(node);
    LRUCacheAddNode(obj, node);
}

void LRUCacheFreeNode(struct Node *node)
{
    free(node);
}

int LRUCacheGet(LRUCache *obj, int key)
{
    int iterations = 0;
    struct Node *node = obj->head->next;
    while (node != obj->tail)
    {
        if (node->key == key)
        {
            LRUCacheMoveToHead(obj, node);
            return node->value;
        }
        node = node->next;
        iterations++;
    }
    return -1;
}

void LRUCachePut(LRUCache *obj, int key, int value)
{
    struct Node *node = obj->head->next;
    while (node != obj->tail)
    {
        if (node->key == key)
        {
            node->value = value;
            LRUCacheMoveToHead(obj, node);
            return;
        }
        node = node->next;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->key = key;
    new_node->value = value;
    LRUCacheAddNode(obj, new_node);
    obj->size++;
    if (obj->size > obj->capacity)
    {
        struct Node *tail = obj->tail->prev;
        LRUCacheRemoveNode(tail);
        LRUCacheFreeNode(tail);
        obj->size--;
    }
}

void LRUCacheFree(LRUCache *obj)
{
    struct Node *node = obj->head->next;
    while (node != obj->tail)
    {
        struct Node *temp = node;
        node = node->next;
        LRUCacheFreeNode(temp);
    }
    free(obj->head);
    free(obj->tail);
    free(obj);
}

void display_as_array(LRUCache *obj)
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
    LRUCache *cache = LRUCacheCreate(5);

    for (int i = 1; i <= 5; i++)
    {
        LRUCachePut(cache, i, i * 2 + 3);
    }

    display_as_array(cache);

    printf("Getting key 3: %d\n", LRUCacheGet(cache, 3));

    LRUCacheFree(cache);

    return 0;
}
