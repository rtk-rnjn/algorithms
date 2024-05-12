#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE_INCREMENT 10

typedef struct
{
    char *key;
    char *value;
} hashmap_entry;

typedef struct
{
    hashmap_entry *entries;
    int size;
    int capacity;
} hashmap;

hashmap *create_hashmap()
{
    hashmap *map = (hashmap *)malloc(sizeof(hashmap));
    map->size = 0;
    map->capacity = HASH_SIZE_INCREMENT;
    map->entries = (hashmap_entry *)malloc(sizeof(hashmap_entry) * map->capacity);
    return map;
}

void free_hashmap(hashmap *map)
{
    for (int i = 0; i < map->size; i++)
    {
        free(map->entries[i].key);
        free(map->entries[i].value);
    }
    free(map->entries);
    free(map);
}

void put(hashmap *map, char *key, char *value)
{
    if (map->size == map->capacity)
    {
        map->capacity += HASH_SIZE_INCREMENT;
        map->entries = (hashmap_entry *)realloc(map->entries, sizeof(hashmap_entry) * map->capacity);
    }
    map->entries[map->size].key = (char *)malloc(strlen(key) + 1);
    map->entries[map->size].value = (char *)malloc(strlen(value) + 1);
    strcpy(map->entries[map->size].key, key);
    strcpy(map->entries[map->size].value, value);
    map->size++;
}

char *get(hashmap *map, char *key)
{
    for (int i = 0; i < map->size; i++)
    {
        if (strcmp(map->entries[i].key, key) == 0)
        {
            return map->entries[i].value;
        }
    }
    return NULL;
}

void remove_entry(hashmap *map, char *key)
{
    for (int i = 0; i < map->size; i++)
    {
        if (strcmp(map->entries[i].key, key) == 0)
        {
            free(map->entries[i].key);
            free(map->entries[i].value);
            for (int j = i; j < map->size - 1; j++)
            {
                map->entries[j] = map->entries[j + 1];
            }
            map->size--;
            return;
        }
    }
}

int main()
{
    hashmap *map = create_hashmap();

    char key1[5] = "key1";
    char value1[7] = "value1";
    put(map, key1, value1);

    char key2[5] = "key2";
    char value2[7] = "value2";
    put(map, key2, value2);

    printf("%s\n", get(map, key1));
    printf("%s\n", get(map, key2));

    remove_entry(map, key1);

    char *value = get(map, key1);
    if (value == NULL)
    {
        printf("Key not found\n");
    }
    else
    {
        printf("%s\n", value);
    }

    free_hashmap(map);

    return 0;
}
