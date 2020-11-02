/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/17 上午 10:47
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

//func函数名其实是代表函数的入口地址

//如何去定义一个指向函数的指针
int myfunc(int a,char b){
    printf("int myfunc(int a,char b) !\n");
    return 0;
}

int con1(int a,int b)
{
    return a + b;
}

//1. 函数就可以做另外一个函数的参数
void doLogic(int(*pFunc)(int, int))
{
    int a = 10;
    int b = 20;
    int ret = pFunc(a,b);
    printf("ret = %d\n", ret);
}

void test26_1(){
    //1.定义函数类型，通过类型来定义函数指针
    typedef int(FUN_TYPE)(int,char);
    FUN_TYPE *pFunc = myfunc;

    pFunc(10, 'a');
    (*pFunc)(20, 'b');
    myfunc(30,'c');

    //2. 直接定义函数指针类型
    typedef int(*FUNC_P)(int, char);
    FUNC_P pFunc2 = myfunc;
    pFunc2(20,'d');

    //3. 直接定义函数指针变量

    //把指针转换为函数指针类型写法
    int(*pFunc3)(int, char) = NULL;
    pFunc3 = myfunc;
    pFunc3(50,'p');

    printf("pFunc3 size:%d\n", sizeof(pFunc3));
}

int main26() {

    //test26_1();
    doLogic(con1);
    return 0;
}
