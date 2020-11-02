#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
// 解决中文乱码  https://www.cnblogs.com/fanlumaster/p/13492736.html
int main_t(void){
    int a = 20;
    int b = 20;
    if (a > b){
        printf("a<b\n");
    }
    else if (a == b){
        printf("a==b");
    }
    else{
        printf("a>b\n");

    }

    return 0;

}
