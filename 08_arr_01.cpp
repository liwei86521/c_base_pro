#include <iostream>
//#include <string>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void test08_1();

using namespace std;

//可读性 要比 效率更重要
void printArray(int arr[],int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d ",arr[i]);
        //printf("%d ", *(arr + i));
    }
}

void printArrayStr(char **arr, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%s\n", arr[i]);
    }
}

void SelectSort(char **arr,int len){
    for (int i = 0; i < len; ++i)
    {
        int min = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (strcmp(arr[j],arr[min]) < 0)
            {
                min = j;
            }
        }

        //swap
        if (min != i){
            char *temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void test08_2()
{

    char* pArr[] = { "ddd", "ccc", "fff", "hhh", "ppp", "rrr" };
    //pArr是什么类型的？ char **类型的
    int len = sizeof(pArr) / sizeof(char *);

    printArrayStr(pArr, len);
    SelectSort(pArr, len); //选择排序
    printf("-------------------\n");
    printArrayStr(pArr, len);

}

//如何定义一个可以指向数组的指针
void test08_3(){
    int arr[5] = { 1, 22, 3, 4, 5 };

    //1. 我们先定义数组类型，再定义数组指针类型
    typedef int(ARRAY_TYPE)[5];
    ARRAY_TYPE myarray; // 等价于  int myarray[5];
    for (int i = 0; i < 5; ++i){
        myarray[i] = 100 + i;
    }

    for (int i = 0; i < 5; ++i){
        printf("%d " ,myarray[i]);
    }

    //对数组名取地址代表指向整个数组的指针
    ARRAY_TYPE *pArray = &arr;;

    //1. *pArray 表示拿到pArray指针指向的整个数组
    //2. *pArray类型就是数组名，指向首元素类型的指针
    printf("\n*(*pArray + 1) : %d\n", *(*pArray + 1)); // *(*pArray + 1) : 22

    //2. 直接定义数组指针类型
    typedef int(*ARRAY_POINTER)[5];
    ARRAY_POINTER pArr = &arr;

    //3. 直接定义数组指针变量   推荐
    int(*pArrParam)[5] = &arr;

}

int main08(void){
    //test08_2();
    test08_3();
    return 0;
}

void test08_1() {
    int scores[10] = {99, 89, 78, 67, 56, 34, 99, 21, 80, 80 };
    //1. sizeof  2.对数组名取地址&arr
//以上两种情况下，数组名不是指向首元素的指针, 以上两种请款下，数组名是数组类型
//！除了以上两点之外，数据名在其他任何情况下都是指向首元素的指针

    //printf("&arr + 1 addr : %d\n", &scores+1); // &arr + 1 addr : 6880792

    //可以通过数据类型求出大小
//int len = sizeof(scores) / sizeof(int);
    int len = sizeof(scores) / sizeof(scores[0]); //可以通过数组元素求出大小
    printf("len %d \n", len);
    //printArray(scores,len);

}
