#include <iostream>
#include <string>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

int main06(void){
    int i, j;
    // 9 9 乘法表
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d*%d=%d\t", j, i, i*j);
        }
        printf("\n");
    }

    return 0;
}

