//
// Created by wangshu on 2019/12/13.
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
    link_List->tail = NULL;
    link_List->head = NULL;
   /* Node node = (Node)malloc(sizeof(node)); //LIST_HEAD_INIT(node);
    node->prev = node;
    node->tail = node;
    link_List->length = 0;
    link_List->tail = node;
    link_List->head = node;*/
    return link_List;
}

Node init_node(){
    //LIST_HEAD(node_);
    Node _node = (Node)malloc(sizeof(node)*1);
    _node->tail = _node;
    _node->prev = _node;
    return _node;
}

int add_head(LinkList  _linkList,Node _node){
    int i = add_new(_linkList,_node,NULL,_linkList->head);
    _linkList->head = _node;
    if(_linkList->length == 1){
        _linkList->tail = _node;
    }
    return i;
}

int add_tail(LinkList  _linkList,Node _node){
    int i = add_new(_linkList,_node,_linkList->tail,NULL);
    _linkList->tail = _node;
    if(_linkList->length == 1){
        _linkList->head = _node;
    }
    return i;
}

/**
 *  prev->tail = next;
 *  next->prev = prev;
 */
int add_new(LinkList _linkList,Node new,Node prev,Node next){
    if(prev != NULL){//如果前驱不为空：
        prev->tail = new;
    }
    if(next != NULL){//如果后继不为空
        next->prev = new;
    }
    new->prev = prev;
    new->tail = next;
    _linkList->length++;
    return 1;
}
int get_length(LinkList _linkList){
    return _linkList->length;
}
void traversal(LinkList _linkList){
    if(_linkList == NULL || _linkList->length == 0){
        printf("链表为空或长度为0\n");
        return;
    }
    Node  n = _linkList->head;
    for(int i = 0;i<_linkList->length;++i){
        printf("_linkList-> %d 的地址 = %#x\n",(i+1),n);
        n = n->tail;
    }
}
/**
 *
 *    1  -> 2 -> 3
 *    1  <- 2 <- 3
 */
int delete_node(LinkList _linkList,Node node){
    if(_linkList == NULL){
        return 0;
    }
    Node node1 = _linkList->head;
    if(node == node1){
        node1->tail->prev = node1->tail;
        _linkList->head = node1->tail;
        _linkList->length--;
        free(node);
        return 1;
    }
    if(node == _linkList->tail){
        node1 =  _linkList->tail;
        node1->prev->tail = node1->prev;
        _linkList->tail = node1->prev;
        _linkList->length--;
        free(node);
        return 1;
    }
    node1 = node1->tail;
    for(int i=1;i<_linkList->length-1;++i){
        if(node1 == node){
            node1->prev->tail = node1->tail;
            node1->tail->prev = node1->prev;
            _linkList->length--;
            free(node1);
            return 1;
        }
        node1 = node1->tail;
    }
    return -1;//未找到元素
}