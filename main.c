#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "base64/base64.h"
#include "./file/copyfile.h"
void openCalc();
void setEnCodeUTF8();
void testLinkList();
int* Swap(int *a, int *b);
extern char* base64_array;
int main() {
    setEnCodeUTF8();
    char *oldName = "../file/1.png";
    char *newName = "../file/paste.png";
    copyFile(oldName,newName);


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