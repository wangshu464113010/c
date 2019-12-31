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
    LinkList  link_List = (LinkList)malloc(sizeof( linkList));
    Node node = (Node)malloc(sizeof(node)); //LIST_HEAD_INIT(node);
    node->prev = node;
    node->tail = node;
    link_List->length = 0;
    link_List->tail = node;
    link_List->head = node;
    return link_List;
}
int add_head(LinkList  _linkList,Node _node){
    int i = add_new(_linkList,_node,NULL,_linkList->head);
    _linkList->head = _node;
    return i;
}

int add_tail(LinkList  _linkList,Node _node){
    int i = add_new(_linkList,_node,_linkList->tail,NULL);
    _linkList->tail = _node;
    return i;
}

/**
 *  prev->tail = next;
 *  next->prev = prev;
 */
int add_new(LinkList _linList,Node new,Node prev,Node next){
    if(prev != NULL){//如果前驱不为空：
        prev->tail = new;
    }
    if(next != NULL){//如果后继不为空
        next->prev = new;
    }
    new->prev = prev;
    new->tail = next;
    _linList->length++;
    return 1;
}
