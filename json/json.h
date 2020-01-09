//
// Created by wangshu on 2020/1/9.
//

#ifndef PROJECT_JSON_H
#define PROJECT_JSON_H

typedef struct c_Json{
    struct c_Json* left;
    struct c_Json* right;
    struct c_Json* child;
}json;
typedef json* Json;

#endif //PROJECT_JSON_H
