/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/15 上午 11:18
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
//1. 按位取反 ~
void test23_1()
{
    int number = 2; //010   101  负数使用补码存储
    printf("~number : %d\n", ~number); // -3
}

//2. 位与 &
void test23_2(){
    int number = 2;
    if ((number & 1) == 0)
    {
        printf("%d是偶数!\n",number);
    }
    else
    {
        printf("%d是奇数!\n",number);
    }
}

//3. 位或 |
void test23_3()
{
    int num1 = 5;
    int num2 = 3;

    printf("num1 | num2 = %d\n", num1 | num2);
}

//4 位抑或 ^
void test23_4()
{
    int num1 = 5;
    int num2 = 9;

#if 0
    int temp = num1; // swap a b
	num1 = num2;
	num2 = temp;
#endif

    printf("num1:%d num2:%d\n", num1, num2);

    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;

    printf("num1:%d num2:%d\n",num1,num2);

}

int main23() {

//    test23_3();
//    test23_4();


    return 0;
}
