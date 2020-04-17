//
// Created by wangshu on 2020/1/9.
//
#include "json.h"

JSON json_init(){
    JSON j = (JSON)calloc(1, sizeof(json));
    return j;
}

int json_add_int(JSON _this,char* _name,int _value){
    (_this)->name = (_name);
            (_this)->valueint = (_value);
            (_this)->type = (CJSON_Number);
   //_this->valueint = 10;
    //ADD_int_or_double_or_string(_this,_name,_value,CJSON_Number,valueint)

    return 1;

}
int json_add_double(JSON _this,char* _name, double _value);
int json_add_string(JSON _this,char* _name, char* _value);