//
// Created by wangshu on 2020/4/13.
//

#ifndef PROJECT_ARRAYMAP_H
#define PROJECT_ARRAYMAP_H

#include <stdlib.h>
#include <stdio.h>
#include "../list.h"
typedef struct array_entry{
   // int hash;
    void* key;
    void* value;
} array_entry;
typedef array_entry* ARRAY_ENTRY;
/***
 *  data [ 1 2 3 4 5 6 7 8 9 10]
 *         l l l l l l l l l l
 */
typedef struct _array_{
    int hash;
    LinkList list;
}_array_;
typedef _array_* _ARRAY_;
typedef struct array_map{
    int size;
    _ARRAY_ data;
    size_t (*hash_code)(void *key);
    int (*equal)(void* key1,void* key2);
}array_map;
typedef array_map* ARRAY_MAP;

size_t amap_default_hashcode(void* _key);
int amap_default_equal(void* _key1,void* _key2);
ARRAY_MAP arrayMap_init();
int arrayMap_put(ARRAY_MAP _map,void* _key,void* _value);
void* arrayMap_get(ARRAY_MAP _map,void* _key);

ARRAY_ENTRY array_entry_init();


#endif //PROJECT_ARRAYMAP_H
