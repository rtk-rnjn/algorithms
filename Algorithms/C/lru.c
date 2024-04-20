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

LRUCache *lRUCacheCreate(int capacity)
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

int lRUCacheGet(LRUCache *obj, int key)
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

void lRUCachePut(LRUCache *obj, int key, int value)
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

void lRUCacheFree(LRUCache *obj)
{
    free(obj->nodes);
    free(obj);
}

int main()
{
    LRUCache *cache = lRUCacheCreate(2);

    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);

    printf("%d\n", lRUCacheGet(cache, 1));

    lRUCachePut(cache, 3, 3);

    printf("%d\n", lRUCacheGet(cache, 2));

    lRUCachePut(cache, 4, 4);

    printf("%d\n", lRUCacheGet(cache, 1));
    printf("%d\n", lRUCacheGet(cache, 3));
    printf("%d\n", lRUCacheGet(cache, 4));

    lRUCacheFree(cache);

    return 0;
}
