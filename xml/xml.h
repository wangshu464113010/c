//
// Created by wangshu on 2020/3/27.
//

#ifndef PROJECT_XML_H
#define PROJECT_XML_H

#include "../list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct xml{
    char *name;//标签名
    LinkList attributes;//属性集合(里面包含map集合)
    LinkList children;//子标签(xml)
}xml;
typedef xml* XML;

char* generate(xml x);

XML xml_init(char* _name);
XML xml_create_root(char* _name);
XML xml_add_children(XML _xml,char* _name);



#endif //PROJECT_XML_H
