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
XML xml_init(char* _name){
    XML _xml_ = (XML)malloc(sizeof(xml));
    _xml_->name = _name;
    _xml_->attributes = NULL;
    _xml_->children = NULL;
    return _xml_;
}
XML xml_create_root(char* _name){
    return xml_init(_name);
}
XML xml_add_children(XML _xml,char* _name){
    XML _xml_children_ = xml_init(_name);
    if(!_xml->children){
        _xml->children = init();
    }
    if(!get_length(_xml->children)){
        linklist_add_first(_xml->children,_xml_children_);
    }else{
        linklist_add_last(_xml->children,_xml_children_);
    }
    return _xml;
}

