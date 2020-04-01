//
// Created by wangshu on 2019/12/13.
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

#define MY_LIST_INIT(a) { a.prev = &a;\
            a.tail = &a; }

typedef struct list_node{ //链表结构
    struct list_node * prev; //前驱
    struct list_node * tail; //后继
} node;

typedef node* Node;

typedef struct myList{
    void* data; // 数据
   // Node node;  //前后指针
    struct list_node l_node;
} myList;
typedef myList* MyList;

typedef struct linkList{
    int length;  //长度
    Node head;  //链表中的头节点
    Node tail;  //链表中的尾节点
    MyList list;
} linkList;
typedef linkList* LinkList;



MyList init_myList();


LinkList init();
int get_length(LinkList _linList);
int linklist_add(LinkList  _linkList,void* newData);//默认加载最后面
void* linklist_get(LinkList  _linkList,int i);
void* linklist_get_last(LinkList  _linkList);
void* linklist_get_first(LinkList  _linkList);

void* linklist_delete(LinkList  _linkList,int i);

int add_head(LinkList  _linkList,Node _node);
int add_tail(LinkList  _linkList,Node _node);
int add_new(LinkList _linkList,Node new,Node prev,Node next);//添加一个节点
void traversal(LinkList _linkList);
int delete_node(LinkList _linkList,Node node);


Node init_node();
int node_add_new(Node new,Node prev);//添加一个节点
int node_delete(Node node);//删除一个节点



#endif //PROJECT_LIST_H
