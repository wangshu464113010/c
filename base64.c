//
// Created by wangshu on 2020/1/15.
//
/**
 * 0=A,...,63=/
 */
 #include <stdio.h>
 #include <stdlib.h>
const char* base64_array = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


char* toNumberSystem(int number,int x){
	char* ret_c = (char*)calloc(8, sizeof(char));
	for(int i=7;i>=0;--i){
		ret_c[i] = number % x;
		number /= x;
		if(number == 0){
			break;
		}
	}
	for(int i =0;i<8;++i){
        printf("%d",ret_c[i]);
	}
	printf("\n");
	return ret_c;
}
