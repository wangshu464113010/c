//
// Created by wangshu on 2020/4/7.
//
#include "map.h"
size_t map_default_hashcode1(void* _key){
    //return (size_t)&(_key);
    size_t  i = 10;
    return i;
}
int map_default_equal(void* _key1,void* _key2){
    return _key1 == _key2;
}
MAP map_init(){
    MAP _map_ = (MAP)malloc(sizeof(map));
    _map_->equal = map_default_equal;
    _map_->hash_code = map_default_hashcode1;

    _map_->node = (ENTRY)calloc(MAP_DEFAULT_SIZE*32,sizeof(entry));
    _map_->node_length = MAP_DEFAULT_SIZE;
    _map_->length = 0;
    return _map_;
}

MAP map_init_withFun( size_t (*_hash_code)(void* _key),int (*_equal)(void* _key1,void* _key2)){
    MAP _map_ = (MAP)malloc(sizeof(struct map));
    _map_->node = (ENTRY)calloc(MAP_DEFAULT_SIZE*32,sizeof(entry));
    _map_->node_length = MAP_DEFAULT_SIZE;
    _map_->equal = _equal;
    _map_->hash_code = _hash_code;
    _map_->length = 0;
    return _map_;
}
int map_put(MAP _map,void* _key,void* _value){
    size_t _keyHashCode = _map->hash_code(_key);
    ENTRY entry = &_map->node[_keyHashCode];

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