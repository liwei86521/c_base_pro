#include <iostream>
#include <string>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

int main05(void){
    int a;
    printf("please input a num --> ");
    scanf("%d", &a);

    switch (a/10) {
        case 10:
            printf("greter ++");
            break;
        case 9:
            printf("greter +");
            break;
        case 8:
            printf("good +");
            break;
        case 7:
            printf("good");
            break;
        case 6:
            printf("pass");
            break;
        default:
            printf("no pass \n");
            break;

    }

    return 0;

}
