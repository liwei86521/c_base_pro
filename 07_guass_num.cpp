#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

int main07(void){
    //加入随机数种子
    srand((unsigned int)time(NULL));
    int num = rand()%100+1;//1-100
    printf("num is --> %d \n", num);
    int value;
    while (1)//for(;;)
    {
        printf("please input your guass number");
        scanf("%d", &value);
        if (value > num)
            printf("number too large \n");
        else if (value < num)
            printf("number too small \n");
        else
        {
            printf("got it \n");
            break;
        }
    }

    return 0;
}
