//
// Created by wangshu on 2020/1/14.
//

#ifndef PROJECT_DATA_H
#define PROJECT_DATA_H

#include "../list.h"

typedef struct data{
    Node node;
    void * yourData;
}data;
typedef data* Data;

int add_data(LinkList linkList,void* data);

#endif //PROJECT_DATA_H
