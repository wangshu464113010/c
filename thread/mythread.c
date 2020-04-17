//
// Created by wangshu on 2020/4/13.
//

#include "mythread.h"

void first_demo(){
    pthread_t t1,t2;
    char* m1 = "thread one";
    char* m2 = "thread two";
    if(!pthread_create(&t1,NULL,(void*)&print_message_function,(void*)m1)){
       printf("thread one create success\n");
    }else{
        printf("thread one create fail\n");
    }
    if(!pthread_create(&t2,NULL,(void*)&print_message_function,(void*)m2)){
        printf("thread two create success\n");
    }else{
        printf("thread two create fail\n");
    }
    void *retval;
    int tmp1,tmp2;
    ///tmp1 = pthread_join(t1, &retval);

}


void print_message_function(void* _ptread){
    for(int i=0 ;i<CONST_INT ;++i){
        printf("print : %s = %d \n",(char*)_ptread, i);
    }
}
