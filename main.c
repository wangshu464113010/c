#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "base64/base64.h"
#include "./file/copyfile.h"
#include "xml/xml.h"
void openCalc();
void setEnCodeUTF8();
void testLinkList();
int* Swap(int *a, int *b);
extern char* base64_array;
struct my_s{
    int a;int b;char c;
};

int main() {
     setEnCodeUTF8();//编码问题
    /*char *oldName = "../file/1.png"; //复制文件
    char *newName = "../file/paste.png";
    copyFile(oldName,newName);*/
    /* xml x ;
    x.name="bean";
    generate(x);*/
    // testLinkList();
    //start------------------宏container_of测试--------------------------container_of(ptr, type, member)
    /*struct my_s* s = (struct my_s*)malloc(sizeof(struct my_s));
    s->a = 10;s->b = 1000;
    struct my_s* s1 = container_of(&(s->a), struct my_s, a);
    //printf("s = %x\n",s);

    //printf("s1 = %x\n",s1);
   // printf("s1.b = %d\n",s1->b);

    myList * ml1 = (myList*)malloc(sizeof(myList));
    char* as = "12456";
    ml1->data = as;
    //node* list_n1= (node*)malloc(sizeof(node));
    LIST_HEAD(node1);
    ml1->l_node=node1;
    printf("ml1.l_node = %x\n",&(ml1->l_node));
    printf("node1 = %x\n",&node1);


    printf("ml1.data = %s\n",ml1->data);

   // node node1 = ml1->l_node;
    myList* ml2 = container_of(&ml1->l_node, struct myList, l_node);
    printf("ml2.data = %s\n",ml2->data);*/

    //end------------------宏container_of测试--------------------------container_of(ptr, type, member)

    LinkList l = init();
    char* a = "打扫房间时空裂缝进口量";
    char* b = "你哈奥";
    char* c = "abcdefghijkl";
    linklist_add(l,a);
    linklist_add(l,b);
    linklist_add(l,c);
    linklist_add(l,"SADFSDAGASDGsda");
    /*linklist_add_first(l,"aa");
    linklist_add_first(l,"vd");
    linklist_add_first(l,"v4");
    linklist_add_first(l,"v3");
    linklist_add_first(l,"v2");
    linklist_add_first(l,"v1");*/
   // printf("linkList[last] = %s\n",(char*)linklist_get_last(l));
    linklist_add_last(l,"last1");
   // printf("linkList[last] = %s\n",(char*)linklist_get_last(l));
    linklist_add_last(l,"last2");
   // printf("linkList[last] = %s\n",(char*)linklist_get_last(l));
    linklist_add_last(l,"last3");
  //  printf("linkList[last] = %s\n",(char*)linklist_get_last(l));
    linklist_add_last(l,"last3");
   /* printf("linkList[13] = %s\n",(char*)linklist_get(l,13));
    printf("linkList[14] = %s\n",(char*)linklist_get(l,14));*/
  //  printf("linkList[2] = %s\n",(char*)linklist_get(l,2));
    linklist_add_index(l,"123456",0);
  //  printf("linkList[5] = %s\n",(char*)linklist_get(l,5));
  //  printf("linkList[6] = %s\n",(char*)linklist_get(l,6));


    /*linklist_add(l,"必定粉红色的积分卡仕达");
    linklist_add(l,"q");
    linklist_add(l,"a");
    linklist_add(l,"z");
    linklist_add(l,"w");//9
    linklist_add(l,"s");
    linklist_add(l,"必定粉红色的积分1");*/
    Node n = l->head;
    int j = 0;
    while (n){
        n = n->tail;
        ++j;
    }
    printf(" j = %d\n",j);

 //   printf("linkList[1] = %s\n",(char*)linklist_get(l,1));
  //  printf("linkList[3] = %s\n",(char*)linklist_get(l,3));
    printf(" length = %d\n",get_length(l));
   // printf("linkList[11] = %s\n",(char*)linklist_get(l,11));
 //   printf("linkList[last] = %s\n",(char*)linklist_get_last(l));
  //  printf("linkList[first] = %s\n",(char*)linklist_get_first(l));
     char* delete = (char*)linklist_delete(l,3);
     printf("delete = %s\n",delete);
    printf("linkList[first] = %s\n",(char*)linklist_get_first(l));
  //  char* delete = (char*)linklist_delete(l,1);
  //  printf("delete = %s\n",delete);
//    printf("linkList[first] = %s\n",(char*)linklist_get_first(l));



    /**
     int* (*pSwap) (int *, int *);//下面定义一个函数指针，这是一个指针，指向一个返回值为int *的函数
     int a = 99, b= 100;
     int * c;
     c=Swap(&a,&b);
     pSwap=Swap;//得到这个函数的地址
     printf("返回的数值是,a原来是99，现在是: %d\n",*c);
     printf("返回的数值是,a原来是99，现在是: %d\n",*pSwap(&a, &b));
     */
    /*printf("base64_array = %s\n",base64_array);
    char str[] = "123456789";
    char * s ="";
    base64_encode(str, strlen(str),s,1);*/
    return 0;
}

int* Swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return a;
}

void openCalc(){
    system("calc");
}
void setEnCodeUTF8(){
/*#ifdef __WIN32__
    printf("32 windows\n");
    system("CHCP 65001");//936==GBK,65001==UTF-8
#endif*/
#ifdef __WIN64__
    //printf("64 windows\n");
    system("CHCP 65001");//936==GBK,65001==UTF-8
#endif
}
void testLinkList(){
    LinkList l = init();
    Node node1 = init_node();
    Node node2 = init_node();
    Node node3 = init_node();
    printf("node1 = %#x node2 = %#x node3 = %#x\n",node1,node2,node3);
    add_head(l,node1);
    add_tail(l,node2);
    add_tail(l,node3);
    printf("链表的长度 = %d\n",get_length(l));
    traversal(l);
    delete_node(l,node3);
    printf("node1 = %#x \n",node3);
    printf("链表的长度 = %d\n",get_length(l));
    traversal(l);
    printf("offsetof = %d\n",offsetof(linkList,length));

    printf("(size_t) &((TYPE *)0)->MEMBER = %d\n",(unsigned __int64)(&((linkList*)0)->length));
    printf("Hello, World!\n");
}