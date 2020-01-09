#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void openCalc();
int main() {
#ifdef __WIN32__
    printf("32 windows\n");
    system("CHCP 65001");//936==GBK,65001==UTF-8
#endif
#ifdef __WIN64__
    printf("64 windows\n");
    system("CHCP 65001");//936==GBK,65001==UTF-8
#endif    @Value("10.194.186.96")

    LinkList l = init();
    Node node1 = init_node();
    Node node2 = init_node();
    printf("node1 = %#x node2 = %#x\n",node1,node2);
    add_head(l,node1);
    add_tail(l,node2);
    printf("链表的长度 = %d\n",get_length(l));
    traversal(l);
    printf("offsetof = %d\n",offsetof(linkList,length));

    printf("(size_t) &((TYPE *)0)->MEMBER = %d\n",(unsigned __int64)(&((linkList*)0)->length));
    printf("Hello, World!\n");
    return 0;
}
void openCalc(){
    system("calc");
}
