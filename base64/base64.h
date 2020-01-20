//
// Created by wangshu on 2020/1/15.
//

#ifndef PROJECT_BASE64_H
#define PROJECT_BASE64_H
#include <stdio.h>
#include <stdlib.h>

char* convertNumberSystem(int number,int x);
int base64_encode(char* srcString,long long srcLength,char* destString,long long destLength);
#endif //PROJECT_BASE64_H
