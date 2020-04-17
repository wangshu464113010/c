//
// Created by wangshu on 2020/4/13.
//

#include "arrayMap.h"

size_t amap_default_hashcode(void* _key){
    return (size_t)(_key) % 10;
}
int amap_default_equal(void* _key1,void* _key2){
    return _key1 == _key2;
}
ARRAY_MAP arrayMap_init(){
    ARRAY_MAP a_map = (ARRAY_MAP)malloc(1 * sizeof(struct array_map));
    a_map->size = 0;
    //a_map->data = (LinkList)calloc(10, sizeof(linkList));
    a_map->data = (_ARRAY_)calloc(10, sizeof(_array_));
    a_map->hash_code = amap_default_hashcode;
    a_map->equal = amap_default_equal;
    return a_map;
}

int arrayMap_put(ARRAY_MAP _map,void* _key,void* _value){
    int key_hash = _map->hash_code(_key);
    LinkList l = _map->data[key_hash].list;
    if(!l){
        l = linklist_init();
        _map->data[key_hash].list = l;
    }
    for(int i=1;i<=linklist_get_length(l);++i){
        ARRAY_ENTRY a = (ARRAY_ENTRY)linklist_get(l,i);
        if(a && a->key == _key){
            a->value = _value;
            return 1;
        }
    }
    linklist_add(l,array_entry_init(_key,_value));
    return 1;
}
void* arrayMap_get(ARRAY_MAP _map,void* _key){
    size_t hash = _map->hash_code(_key);
    LinkList l = _map->data[hash].list;
    for(int i = 1 ;i<=linklist_get_length(l) ;++i){
        ARRAY_ENTRY a = (ARRAY_ENTRY)linklist_get(l,i);
        if(a && _map->equal(_key,a->key)){
            return a->value;
        }
    }
    return NULL;
}

ARRAY_ENTRY array_entry_init(void* _key,void* _value){
    ARRAY_ENTRY ae = (ARRAY_ENTRY) malloc(1* sizeof(array_entry));
    ae->key = _key;
    ae->value = _value;
    return ae;
}