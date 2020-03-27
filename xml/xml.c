//
// Created by wangshu on 2020/3/27.
//

#include "xml.h"

char* generate(xml x){
    char *s = (char*) calloc(1024, sizeof(char));
    if(s == NULL){
        exit(0);
    }
    strcpy(s,"<");
    strcat(s,x.name);
    if(!x.attributes){
        strcat(s," ");
    }
    /** 添加属性 */
    strcat(s,">");
    /** 添加子标签 */

    strcat(s,"</");
    strcat(s,x.name);
    strcat(s,">");
    printf("xml s = %s\n",s);
    return s;
}
