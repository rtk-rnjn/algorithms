#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct
{
    int key;
    int value;
} Node;

typedef struct
{
    Node *nodes;
    int size;
} LRUCache;

LRUCache *LRUCacheCreate(int capacity)
{
    LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->nodes = (Node *)malloc(sizeof(Node) * capacity);
    cache->size = capacity;
    for (int i = 0; i < capacity; i++)
    {
        cache->nodes[i].key = -1;
        cache->nodes[i].value = -1;
    }
    return cache;
}

int LRUCacheGet(LRUCache *obj, int key)
{
    for (int i = 0; i < obj->size; i++)
    {
        if (obj->nodes[i].key == key)
        {
            int value = obj->nodes[i].value;
            for (int j = i; j > 0; j--)
            {
                obj->nodes[j].key = obj->nodes[j - 1].key;
                obj->nodes[j].value = obj->nodes[j - 1].value;
            }
            obj->nodes[0].key = key;
            obj->nodes[0].value = value;
            return value;
        }
    }
    return -1;
}

void LRUCachePut(LRUCache *obj, int key, int value)
{
    for (int i = 0; i < obj->size; i++)
    {
        if (obj->nodes[i].key == key)
        {
            for (int j = i; j > 0; j--)
            {
                obj->nodes[j].key = obj->nodes[j - 1].key;
                obj->nodes[j].value = obj->nodes[j - 1].value;
            }
            obj->nodes[0].key = key;
            obj->nodes[0].value = value;
            return;
        }
    }
    for (int i = obj->size - 1; i > 0; i--)
    {
        obj->nodes[i].key = obj->nodes[i - 1].key;
        obj->nodes[i].value = obj->nodes[i - 1].value;
    }
    obj->nodes[0].key = key;
    obj->nodes[0].value = value;
}

void LRUCacheFree(LRUCache *obj)
{
    free(obj->nodes);
    free(obj);
}

int main()
{
    LRUCache *cache = LRUCacheCreate(2);

    LRUCachePut(cache, 1, 1);
    LRUCachePut(cache, 2, 2);

    printf("%d\n", LRUCacheGet(cache, 1));

    LRUCachePut(cache, 3, 3);

    printf("%d\n", LRUCacheGet(cache, 2));

    LRUCachePut(cache, 4, 4);

    printf("%d\n", LRUCacheGet(cache, 1));
    printf("%d\n", LRUCacheGet(cache, 3));
    printf("%d\n", LRUCacheGet(cache, 4));

    LRUCacheFree(cache);

    return 0;
}
