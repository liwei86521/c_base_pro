/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/15 上午 10:06
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;


void test19_1() //%*s或%*d	跳过数据
{

#if 1
    char *str = "12345abcde";
	char buf[1024] = { 0 };
	sscanf(str,"%*d%s" , buf); // 格式化已有的str
	printf("buf:%s\n", buf);

#else

    //忽略字符串到空格或者\t
    char *str = "abcde\t12345";
    char buf[1024] = { 0 };
    sscanf(str, "%*s%s", buf);
    printf("buf:%s\n", buf);

#endif
}

//%[width]s	读指定宽度的数据
void test19_2()
{
    char *str = "12345abcde";
    char buf[1024] = { 0 };
    sscanf(str, "%6s", buf);
    printf("buf:%s\n", buf);
}
//%[a-z]	匹配a到z中任意字符(尽可能多的匹配)
void test19_3()
{
    char *str = "12345abcde";
    char buf[1024] = { 0 };
    sscanf(str, "%*d%[a-c]", buf);
    printf("buf:%s\n", buf);
}

//%[aBc]	匹配a、B、c中一员，贪婪性
void test19_4()
{
    char *str = "aABbcde";
    char buf[1024] = { 0 };
    sscanf(str, "%[aAb]", buf);
    printf("buf:%s\n", buf);
}

//%[^a] 	匹配非a的任意字符，贪婪性
void test19_5()
{
    char *str = "aABbcde";
    char buf[1024] = { 0 };
    sscanf(str, "%[^c]", buf);
    printf("buf:%s\n", buf);

}
//%[^a-z]	表示读取除a-z以外的所有字符
void test19_6()
{
    char *str = "aABbcde12345";
    char buf[1024] = { 0 };
    sscanf(str, "%[^0-9]", buf);
    printf("buf:%s\n", buf);
}


void test19_7()
{
    char *ip = "127.0.0.1";
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    sscanf(ip, "%d.%d.%d.%d", &num1, &num2, &num3, &num4);

    printf("num1:%d\n", num1);
    printf("num2:%d\n", num2);
    printf("num3:%d\n", num3);
    printf("num4:%d\n", num4);
}

void test19_8()
{
    char *str = "abcde#12uiop@0plju";
    char buf[1024] = { 0 }; // %*[^#] 跳过 非# 数据
    sscanf(str, "%*[^#]#%[^@]" , buf); //%*s或%*跳过数据
    printf("buf:%s\n", buf);

}

int main19() {
    test19_3();
    test19_7();
    test19_8();

    return 0;
}
