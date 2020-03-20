//
// Created by wangshu on 2020/1/9.
//

#ifndef PROJECT_JSON_H
#define PROJECT_JSON_H
/**
 *  left data  right
 *         child
 */

#define CJSON_False 0
#define CJSON_True 1
#define CJSON_NULL 2
#define CJSON_Number 3
#define CJSON_String 4
#define CJSON_Array 5
#define CJSON_Object 6


typedef struct c_Json{
    struct c_Json* left;
    struct c_Json* right;
    struct c_Json* child;

    int type;
    char *valuestring;			/* The item's string, if type==cJSON_String */
    int valueint;				/* The item's number, if type==cJSON_Number */
    double valuedouble;			/* The item's number, if type==cJSON_Number */

    char *string;				/* The item's name string, if this item is the child of, or is in the list of subitems of an object. */

}json;
typedef json* JSON;

#endif //PROJECT_JSON_H
