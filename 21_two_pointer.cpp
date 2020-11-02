/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/15 上午 11:04
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
void test21_1();
void printArray(int **arr,int len);


int main21_2() {

    test21_1();
    return 0;
}

void printArray(int **arr,int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d ",*arr[i]);
    }
}

void test21_1()
{

    //堆上分配指针数组
    int **pArray = (int **)malloc(sizeof(int *)* 6);

    //栈上分配数据空间
    int a1 = 100;
    int a2 = 200;
    int a3 = 300;
    int a4 = 400;
    int a5 = 500;
    int a6 = 600;

#if 0
    pArray[0] = &a1;
	pArray[1] = &a2;
	pArray[2] = &a3;
	pArray[3] = &a4;
	pArray[4] = &a5;
	pArray[5] = &a6;
#endif

    *(pArray + 0) = &a1;
    *(pArray + 1) = &a2;
    *(pArray + 2) = &a3;
    *(pArray + 3) = &a4;
    *(pArray + 4) = &a5;
    *(pArray + 5) = &a6;


    printArray(pArray, 6);

    //释放数组内存
    if (pArray != NULL)
    {
        free(pArray);
        pArray = NULL;
    }

}