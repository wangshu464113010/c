//
// Created by wangshu on 2020/3/27.
//

#ifndef PROJECT_XML_H
#define PROJECT_XML_H

#include "../list.h"
#include "../map/arrayMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 *  &lt;   <
 *  &gt;   >(合法)
 *  &amp;  &
 *  &apos; '
 *  &quot; "
 *
 */

typedef struct xml_node{
    char *name;//标签名
    //char *annotation;//注释
    ARRAY_MAP attributes;//属性集合(里面包含map集合)
    LinkList children;//子标签(xml)
}xml_node;
typedef xml_node* XML_NODE;

typedef struct xml{
    char* fileName;
    char* encoding;
    XML_NODE root;

}xml;
typedef xml* XML;

XML xml_init(char* _name);
XML xml_create_root(char* _rootNodeName);
XML xml_add_child(XML _father,char* _childNodeName);
int xml_add_attribute(XML _this,char* _attributeName,char* _attributeValue);



#endif //PROJECT_XML_H
