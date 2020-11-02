#include "fun.h"
int maxNum(int a, int b){

    return (a>b)? a:b;
}



//求字符串长度
int length(char *s)
{
    int i=0;
    char* p = s;
    while(*p!='\0')
    {
        i++;
        p++;
    }
    return i;
}

// 翻转字符串输出
void reverse(char* s)
{
    int len;
    len = length(s); // 获取字符串长度

    // 交换 ...
    int i = 0;
    char c;
    while (i <= len / 2 - 1)
    {
        c = s[i];
        s[i] =s[len - 1 - i];
        s[len - 1 - i] = c;

        i++;
    }
}

void print_arr_str() {
    const char *s[]={"man", "woman", "girl", "boy", "sister"};//一个字符串数组
    const char **q;
    int k;
    for(k=0;k<5;k++)
    {
        //q=&s[k];       /*在这里填入内容*/
        printf("%s\n",s[k]);
    }
}

void oct2ten() {
    char s[] = "16"; // 字符串
    int res = 0, i=0;
    while (s[i] != '\0'){
        res = res*8 + s[i]-'0';
        i++;
    }
    printf("刚输入的8进制数转化为十进制为\n%d\n",res);
}