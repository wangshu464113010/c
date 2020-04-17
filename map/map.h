//
// Created by wangshu on 2020/4/7.
//

#ifndef PROJECT_MAP_H
#define PROJECT_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include "../list.h"
#define MAP_DEFAULT_SIZE 10
#define MAP_DEFAULT_HASHCODE(_key) (int)(_key);
#define MAP_DEFAULT_EQUAL(_key1,_key2) (_key1) == (_key2);

typedef struct entry{
    int hash;
    void* key;
    void* value;
} entry;
typedef entry* ENTRY;

typedef struct map{
    int length;
    ENTRY node;
    int node_length;
    size_t (*hash_code)(void *key);
    int (*equal)(void* key1,void* key2);
}map;

typedef map* MAP;

size_t map_default_hashcode1(void* _key);
int map_default_equal(void* _key1,void* _key2);

MAP map_init();
MAP map_init_withFun(size_t (* _hash_code)(void* _key),int (* _equal)(void* _key1,void* _key2));

int map_put(MAP _map,void* _key,void* _value);
int map_get(MAP _map,void* _key);
int map_remove(MAP _map,void* _key);

int map_length(MAP _map);

#endif //PROJECT_MAP_H
