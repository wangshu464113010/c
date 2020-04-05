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


LinkList linklist_init(){
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

int linklist_get_length(LinkList _linkList){
    return _linkList->length;
}
int linklist_add_index(LinkList  _linkList,void* _newData,int _index){
    //初始化节点
    MyList myList1 = init_myList();
    myList1->data = _newData;
    NODE_INIT_NULL(myList1->l_node);
    Node n_p = &myList1->l_node;

    if(_index <= 1){//_index <= 1 ，添加在第一个
        if(_linkList->length){
            node_add_node_prev_new(n_p,_linkList->head);
        }else{//链表长度为0
            _linkList->tail = n_p;
        }
        _linkList->head = n_p;
    }else if (_index >= _linkList->length){//_index >= length时，添加在最后面
        if(_linkList->length){//判断长度是否为0
            node_add_node_next_new(n_p,_linkList->tail);//默认加到最后面
        }else{//如果链表长度是0
            _linkList->head = n_p;
        }
        _linkList->tail = n_p;
    }else{
        Node node1 = node_offsetof(_linkList->head,_linkList->tail,_index,_linkList->length);//找到第_index 节点
        node_add_node_prev_new(n_p,node1);//添加在第 _index 节点的前面
    }
    _linkList->length++;
    return 1;
}
int linklist_add_first(LinkList  _linkList,void* _newData) {
    return linklist_add_index(_linkList, _newData,1);;
}
int linklist_add_last(LinkList  _linkList,void* _newData) {
    return linklist_add(_linkList, _newData);
}
int linklist_add(LinkList  _linkList,void* _newData){
    MyList myList1 = init_myList();
    myList1->data = _newData;
//    LIST_HEAD(Mylist_node);
//    MY_LIST_INIT(myList1->l_node);
    NODE_INIT_NULL(myList1->l_node);

    Node n_p = &myList1->l_node;
    if(_linkList->length){//判断长度是否为0
        node_add_node_next_new(n_p,_linkList->tail);//默认加到最后面
    }else{//如果链表长度是0
        _linkList->head = n_p;
    }
    _linkList->tail = n_p;
    _linkList->length++;
    return 1;
}
void* linklist_get(LinkList  _linkList,int _i){
    if(_i <= 1){
        return linklist_get_first(_linkList);
    }
    if(_i >= _linkList->length){
        return linklist_get_last(_linkList);
    }
    Node node1 ;//= node_offsetof(_linkList->head,_linkList->tail,_i,_linkList->length);// = _linkList->head;
    if(_i <= _linkList->length>>1){
        node1 = _linkList->head;
        while ( --_i ){
            node1 = node1->tail;
        }
    }else{
        node1 = _linkList->tail;
        while ( _linkList->length - _i++ ){
            node1 = node1->prev;
        }
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
void* linklist_delete(LinkList  _linkList,int _i){
    void* _data = NULL;
    if(_i < 1 || _i > _linkList->length){
        return NULL;
    }else if(_i == 1){//第一个元素
        MyList l = container_of(_linkList->head, struct myList ,l_node);
        _data = l->data;
        if(_linkList->length == 1){
            _linkList->head = NULL;
            _linkList->tail = NULL;
        }else{
            _linkList->head = _linkList->head->tail;
            _linkList->head->prev = NULL;
        }
        free(l);
    }else if(_i == _linkList->length){//最后一个元素
        MyList l = container_of(_linkList->tail, struct myList ,l_node);
        _data = l->data;
        if(_linkList->length == 1){
            _linkList->head = NULL;
            _linkList->tail = NULL;
        }else{
            _linkList->tail = _linkList->tail->prev;
            _linkList->tail->tail = NULL;
        }
        free(l);
    }else{
        Node node1 = node_offsetof(_linkList->head,_linkList->tail,_i,_linkList->length);//i 节点
        MyList l = container_of(node1, struct myList ,l_node);
        _data = l->data;
        node_delete(node1);
        free(l);
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
int node_add_node_prev_new(Node _new,Node _tail) {//_prev节点前添加一个节点
    Node prev = _tail->prev;//获取prev的前驱  prev -> new -> _tail
    if(prev){ //prev不是头节点
        _new->prev = prev;
        prev->tail = _new;
    }
    _new->tail = _tail;
    _tail->prev = _new;
    return 1;
}

int node_add_node_next_new(Node _new,Node _prev){//节点后添加一个新的节点
    Node next = _prev->tail;//获取prev的后继  _prev -> new -> next
    if(next){ //prev不是尾节点
        _new->tail = next;
        next->prev = _new;
    }
    _new->prev = _prev;
    _prev->tail = _new;
    return 1;
}
/**
 *
 * @param _prev 链表头节点
 * @param _tail 链表尾节点
 * @param _i    位置
 * @param _length  链表的长度
 * @return 链表的第_i个节点
 */
Node node_offsetof(Node _prev,Node _tail,int _i,int _length){//寻找链表中的第 _i 个位置的节点
    Node node1;
    if(_i <= _length>>1){
        node1 = _prev;
        while ( --_i ){
            node1 = node1->tail;
        }
    }else{
        node1 = _tail;
        while ( _length - _i++ ){
            node1 = node1->prev;
        }
    }
    return node1;
}

int node_delete(Node _node){
    Node _next = _node->tail;//获取prev的后继  _prev -> _node -> _next
    Node _prev = _node->prev;
    _prev->tail = _next;
    _next->prev = _prev;
    /*Node n = _node;
    free(n);*/
    return 1;
}