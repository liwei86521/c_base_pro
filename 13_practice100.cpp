#include <iostream>
#include <string.h>
#include <ctype.h>
#include "fun.h"
using namespace std;

void str_test();

int main13()
{
    cout << "hello" << endl;
    //system("pause");

    return 0;
}




void str_test() {
    char s1[]={'a', 'b', '#', '5', 'u'}; // //普通字符数组
    printf("s1 = %s\n", s1); // 乱码，因为没有’\0’结束符

    char s2[]={'a','b','#','5','u', '\0'}; // 字符串 因为有'\0'结束符
    printf("s2 = %s\n", s2);

    char str[] = "abcdefg";
    printf("str = %s\n", str);

    printf("%d %d",strlen(s2), strlen(str));
}

