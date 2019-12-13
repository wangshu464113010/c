//
// Created by ELIAN-FM-JSJ297 on 2019/12/13.
//

#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

typedef  struct list_node{ //链表
    struct node * prev;
    struct node * tail;
} node;

typedef struct node* Node;

typedef struct linkList{
    Node list;
    int size;
    int length;
    Node tail;  //链表中的头节点
    Node head;  //链表中的尾节点
    void * data;
}linkList;
typedef linkList* LinkList;

typedef struct data{
    Node node;
    void * yourData;
}data;

LinkList init();
int add(LinkList  _linkList,Node _list);



#endif //PROJECT_LIST_H
