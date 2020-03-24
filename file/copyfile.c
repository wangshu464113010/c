//
// Created by wangshu on 2020/3/24.
//
#include <stdio.h>
#include <stdlib.h>
#include "copyfile.h"
/**
	宏延续运算符（\）
	一个宏通常写在一个单行上。但是如果宏太长，一个单行容纳不下，则使用宏延续运算符（\）。
	字符串常量化运算符（#）
	在宏定义中，当需要把一个宏的参数转换为字符串常量时，则使用字符串常量化运算符（#）。在宏中使用的该运算符有一个特定的参数或参数列表。
**/
#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")

int copyFile(){
    FILE *fp = fopen("../file/1.png","r+b");
    FILE *f = fopen("../file/paste.png","w+b");
    char buff[1024];
    int count;
    while(!feof(fp)){
        count = fread(buff,sizeof(char),1024,fp);
        int n = feof (fp);
        printf ("%d,%d\n", count, n);
        fwrite(buff,sizeof(char),1024,f);
    }
    fclose(fp);
    fclose(f);
    return 0;
}

/**FILE *fp = fopen("./a.sql","r");

    char buff[255];
    fgets(buff,255,fp);
    printf("%s\n", buff);
    fclose(fp);*/

/**
	printf("line = %d\n", __LINE__); //当前行号
	printf("ANSI = %d\n", __STDC__); //当编译器以 ANSI 标准编译时，则定义为 1。
	printf("file = %s\n", __FILE__); //当前文件名
	printf("data time = %s %s\n", __DATE__,__TIME__); //当前系统的日期和时间
**/

/**
标记粘贴运算符（##）
宏定义内的标记粘贴运算符（##）会合并两个参数。它允许在宏定义中两个独立的标记被合并为一个标记。例如：
code:
	#include <stdio.h>
	#define tokenpaster(n) printf ("token" #n " = %d", token##n)
	int main(void){
	   int token34 = 40;
	   tokenpaster(34);
	   return 0;
	}
当上面的代码被编译和执行时，它会产生下列结果：

token34 = 40
这是怎么发生的，因为这个实例会从编译器产生下列的实际输出：

printf ("token34 = %d", token34);

*/

/**
defined() 运算符
预处理器 defined 运算符是用在常量表达式中的，用来确定一个标识符是否已经使用 #define 定义过。
如果指定的标识符已定义，则值为真（非零）。如果指定的标识符未定义，则值为假（零）。下面的实例演示了 defined() 运算符的用法：
#include <stdio.h>

#if !defined (MESSAGE)
   #define MESSAGE "You wish!"
#endif

int main(void)
{
   printf("Here is the message: %s\n", MESSAGE);
   return 0;
}
当上面的代码被编译和执行时，它会产生下列结果：

Here is the message: You wish!
**/

/**  //可变参数列表
#include <stdio.h>
#include <stdarg.h>
double average(int num,...){
    va_list valist;
    double sum = 0.0;
    int i;
    // 为 num 个参数初始化 valist
    va_start(valist, num);

    // 访问所有赋给 valist 的参数
    for (i = 0; i < num; i++)
    {
       sum += va_arg(valist, int);
    }
    // 清理为 valist 保留的内存
    va_end(valist);

    return sum/num;
}
int main(){
   printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
   printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
}
**/
