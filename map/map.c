//
// Created by wangshu on 2020/4/7.
//
#include "map.h"
int map_default_hashcode(void* _key){
    return MAP_DEFAULT_HASHCODE(_key);
}
int map_default_equal(void* _key1,void* _key2){
    return MAP_DEFAULT_EQUAL(_key1,_key2);
}
MAP map_init(){
    MAP _map_ = (MAP)malloc(sizeof(map));
    _map_->equal = map_default_equal;
    _map_->hash_code = map_default_hashcode;

    _map_->node = (ENTRY)malloc(sizeof(entry) * MAP_DEFAULT_SIZE);
    _map_->node_length = MAP_DEFAULT_SIZE;
    _map_->length = 0;
    return _map_;
}

MAP map_init_withFun(int (*_hash_code)(void* _key),int (*_equal)(void* _key1,void* _key2)){
    MAP _map_ = (MAP)malloc(sizeof(struct map));
    _map_->node = (ENTRY)malloc(sizeof(entry) * MAP_DEFAULT_SIZE);
    _map_->node_length = MAP_DEFAULT_SIZE;
    _map_->equal = _equal;
    _map_->hash_code = _hash_code;
    _map_->length = 0;
    return _map_;
}
int map_put(MAP _map,void* _key,void* _value){
    int _keyHashCode = _map->hash_code(_key);
    if(_keyHashCode)
        return 1;
}
int map_get(MAP _map,void* _key){
    return 1;
}
int map_remove(MAP _map,void* _key){
    return 1;
}
int map_length(MAP _map){
    return _map->length;
}