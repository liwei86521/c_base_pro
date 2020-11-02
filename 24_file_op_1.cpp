/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/15 下午 05:27
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
void test24_1();

int main24() {
    test24_1();

    return 0;
}


void test24_1()
{
    FILE *f =  fopen("D:\\Program_Files\\JetBrains\\CLionProjects\\pro_02\\text.txt","r");
    if (NULL == f){
        printf("打开文件失败!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(f)) != EOF){
        printf("%c", ch);
    }


    //关闭文件
    fclose(f);
    f = NULL;
}