//
// Created by wangshu on 2020/1/15.
//
/**
 * 0=A,...,63=/
 */
 #include <stdio.h>
 #include <stdlib.h>
const char* base64_array = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


char* convertNumberSystem(int number,int x){
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

int base64_encode(char* srcString,long long srcLength,char* destStr,long long destLength){
    //计算空间
    char * destString = (char*)malloc(sizeof(char) * 100);
    char * p = destString;
    for(int i=0;i<srcLength/3;++i){
        /**     A               B    C   D
         *    0x41             0x42 0x43 0x44
         *    010000 01/0100 0010
         *     Q       U
         */
        *destString++ = base64_array[(srcString[0] >> 2) & 0x3f];
        *destString++ = base64_array[(srcString[0] << 4) & 0x30 | ((srcString[1] >> 4) & 0x0f)];
        *destString++ = base64_array[(srcString[1] << 2) & 0x3c | ((srcString[2] >> 6) & 0x03)];
        *destString++ = base64_array[srcString[2] & 0x3f];
        srcString += 3;
    }
    if(srcLength%3 == 1){
        *destString++ = base64_array[(srcString[0] >> 2) & 0x3f];
        *destString++ = base64_array[(srcString[0] << 4) & 0x30 | ((srcString[1]>>4) & 0x0f)];
        *destString++ = '=';
        *destString++ = '=';
    }else if(srcLength%3 == 2){
        *destString++ =base64_array[(srcString[0] >> 2) & 0x3f];
        *destString++ =base64_array[((srcString[0] << 4) & 0x30) | ((srcString[1] >> 4) & 0x0f)];
        *destString++ =base64_array[(srcString[1] << 2) & 0x3c];//?j+1
        *destString++ ='=';
    }
    *destString = '\0';
    printf("destString = %s",p);
    return 0;
}
