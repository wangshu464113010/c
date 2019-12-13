//
// Created by ELIAN-FM-JSJ297 on 2019/12/13.
//
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

LinkList init(){
    /*List _list = (List)malloc(sizeof(struct list) * length);
    _list->prev = NULL;
    _list->tail = NULL;
    if(!_list){
        exit(0);
        return NULL;
    }*/
    LinkList  link_List = (LinkList)malloc(sizeof(linkList));
    link_List->length = 0;
    link_List->size = 0;
    link_List->list = NULL;
    link_List->tail = NULL;
    link_List->head = NULL;
    return link_List;
}
int add(LinkList  _linkList,Node _node){
    Node node = _linkList->list;
    node->tail = _node;
    _node->prev = node;
    _linkList->length++;
    _linkList->tail = _node;
    return 1;
}
