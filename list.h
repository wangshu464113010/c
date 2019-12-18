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

typedef  struct list_node{ //链表
    struct node * prev;
    struct node * tail;
} node;

typedef struct node* Node;

typedef struct linkList{
    int size;
    int length;
    Node tail;  //链表中的头节点
    Node head;  //链表中的尾节点
}linkList;
typedef linkList* LinkList;

typedef struct data{
    Node node;
    void * yourData;
}data;

LinkList init();
int add(LinkList  _linkList,Node _list);



#endif //PROJECT_LIST_H
