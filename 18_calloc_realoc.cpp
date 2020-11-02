/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/15 上午 09:07
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

void test18_1()
{
    int *p =  (int *)calloc(10,sizeof(int));
    for (int i = 0; i < 10; ++i)
    {
        p[i] = i + 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", p[i]);
    }


    if (p != NULL)
    {
        free(p);
        p = NULL;
    }
}

void test18_2()
{
    int *p = (int *)malloc(sizeof(int)* 10);
    for (int i = 0; i < 10; ++i)
    {
        p[i] = i + 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", p[i]);
    }

    printf("\n");
    printf("%d\n", p);

    p = (int *)realloc(p, sizeof(int)* 200);
    printf("%d\n",p);

    for (int i = 0; i < 15; ++i)
    {
        printf("%d ", p[i]);
    }
}

int main18() {
    test18_2();

    return 0;
}

