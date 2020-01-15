#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "base64.h"
void openCalc();
void setEnCodeUTF8();
void testLinkList();
extern char* base64_array;
int main() {
    setEnCodeUTF8();
    toNumberSystem(10,2);
    printf("base64_array = %s\n",base64_array);
    char* a = "ABCD";
    printf("a+3 = %c\n",*(a+3));
    printf("a+4 = %d\n",*(a+4));
    while(*a){
        printf("a = %#x\n",a);
        a++;
    }
    return 0;
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