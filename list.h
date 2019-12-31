//
// Created by ELIAN-FM-JSJ297 on 2019/12/13.
//

#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

// 获取"MEMBER成员"在"结构体TYPE"中的位置偏移
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

// 根据"结构体(type)变量"中的"域成员变量(member)的指针(ptr)"来获取指向整个结构体变量的指针
#define container_of(ptr, type, member) ({          \
      const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
      (type *)( (char *)__mptr - offsetof(type,member) );})

#define LIST_HEAD_INIT(name) { &(name),&(name)}
#define LIST_HEAD(name) \
        struct list_node name = LIST_HEAD_INIT(name)

typedef  struct list_node{ //链表
    struct list_node * prev;
    struct list_node * tail;
} node;

typedef node* Node;

typedef struct linkList{
    int length;
    Node head;  //链表中的头节点
    Node tail;  //链表中的尾节点
} linkList;
typedef linkList* LinkList;

typedef struct data{
    Node node;
    void * yourData;
}data;

LinkList init();
int add_head(LinkList  _linkList,Node _node);
int add_tail(LinkList  _linkList,Node _node);
int add_new(LinkList _linList,Node new,Node prev,Node next);//添加一个节点


#endif //PROJECT_LIST_H
