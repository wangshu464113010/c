#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    LinkList l = init();
    printf("offsetof = %d\n",offsetof(linkList,length));

    printf("(size_t) &((TYPE *)0)->MEMBER = %d\n",(int)&((linkList*)0)->length);
    printf("Hello, World!\n");
    return 0;
}

