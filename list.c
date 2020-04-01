//
// Created by wangshu on 2019/12/13.
//
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

MyList init_myList(){
    MyList myL = (MyList)malloc(sizeof(myList));
    myL->data = NULL;
    return myL;
}


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
    link_List->list = NULL;
   // link_List->list = init_myList();
   /* Node node = (Node)malloc(sizeof(node)); //LIST_HEAD_INIT(node);
    node->prev = node;
    node->tail = node;
    link_List->length = 0;
    link_List->tail = node;
    link_List->head = node;*/
    return link_List;
}

int get_length(LinkList _linkList){
    return _linkList->length;
}

int linklist_add(LinkList  _linkList,void* newData){//默认加到最后面
    MyList myList1 = init_myList();

    myList1->data = newData;
//    LIST_HEAD(Mylist_node);
    MY_LIST_INIT(myList1->l_node);
    /*myList1->l_node.prev = &myList1->l_node;
    myList1->l_node.tail = &myList1->l_node;*/
    Node n_p = &myList1->l_node;
    if(_linkList->length){
        node_add_new(n_p,_linkList->tail);
    }else{
        _linkList->head = n_p;
    }
    _linkList->tail = n_p;
    _linkList->length++;
    return 1;
}
void* linklist_get(LinkList  _linkList,int i){
    Node node1 = _linkList->head;
    while ( --i ){
        node1 = node1->tail;
    }
    // 根据"结构体(type)变量"中的"域成员变量(member)的指针(ptr)"来获取指向整个结构体变量的指针
    //#define container_of(ptr, type, member)
    MyList l =  container_of(node1, struct myList ,l_node);
    return l->data;
}
void* linklist_get_last(LinkList  _linkList){
    return container_of(_linkList->tail, struct myList ,l_node)->data;
}
void* linklist_get_first(LinkList  _linkList){
    return container_of(_linkList->head, struct myList ,l_node)->data;
}
void* linklist_delete(LinkList  _linkList,int i){
    void* _data = NULL;
    if(i == 1){
        MyList l = container_of(_linkList->head, struct myList ,l_node);
        _data = l->data;
        if(_linkList->length == 1){
            _linkList->head = NULL;
            _linkList->tail = NULL;
        }else{
            _linkList->head = _linkList->head->tail;
        }
        free(l);
    }else if(i == _linkList->length){

    }else{
        Node node1 = _linkList->head;
        while ( --i ){
            node1 = node1->tail;
        }
        node_delete(node1);
    }
    _linkList->length--;
    return _data;
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

// Node
Node init_node(){
    //LIST_HEAD(node_);
    Node _node = (Node)malloc(sizeof(node)*1);
    _node->tail = NULL;
    _node->prev = NULL;
    return _node;
}

int node_add_new(Node new,Node prev){//节点后添加一个新的节点
    Node next = prev->tail;//获取prev的后继  prev -> new -> next
    if(next != prev){ //prev不是尾节点
        new->tail = next;
        next->prev = new;
    }
    new->prev = prev;
    prev->tail = new;
    return 1;
}

int node_delete(Node _node){

    Node _next = _node->tail;//获取prev的后继  _prev -> _node -> _next
    Node _prev = _node->prev;
    _prev->tail = _next;
    _next->prev = _prev;
    Node n = _node;
    free(n);
    return 1;
}