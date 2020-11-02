#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
// 解决中文乱码  https://www.cnblogs.com/fanlumaster/p/13492736.html
int main04(void){
    int a = 40;
    int b = 50;

    int c = a > b ? a:b;

    printf("c ---> %d", c);
    return 0;


}
