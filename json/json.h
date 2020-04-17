//
// Created by wangshu on 2020/1/9.
//

#ifndef PROJECT_JSON_H
#define PROJECT_JSON_H

#include <stdio.h>
#include <stdlib.h>
/**
 *  left data  right
 *         child
 */

#define CJSON_False 0
#define CJSON_True 1
#define CJSON_NULL 2
#define CJSON_Number 3
#define CJSON_Double 4
#define CJSON_String 5
#define CJSON_Array 6
#define CJSON_Object 7

/*#define ADD_int_or_double_or_string (_this,_name,_value,_typeValue,Type) \
             _this->name = (_name);                 \
            _this->Type = (_value);               \
            _this->type = (_typeValue);
*/


typedef struct c_Json{
    struct c_Json* left;
    struct c_Json* right;
    struct c_Json* child;
    int array_length;

    int type;
    char* valuestring;
    int valueint;
    double valuedouble;

    char* name;

}json;
typedef json* JSON;

JSON json_init();
int json_add_int(JSON _this,char* _name,int _value);
int json_add_double(JSON _this,char* _name, double _value);
int json_add_string(JSON _this,char* _name, char* _value);

#endif //PROJECT_JSON_H
