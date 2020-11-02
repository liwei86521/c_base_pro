#include <iostream>
#include <cstring>

using namespace std;

//值传递
void ValueSwap(int m,int n){
    int temp = m;
    m = n;
    n = temp;
}
//地址传递
void PointerSwap(int* m,int* n){
    int temp = *m;
    *m = *n;
    *n = temp;
}
//引用传递
void ReferenceSwap(int& m,int& n){
    int temp = m;
    m = n;
    n = temp;
}
void test(){
    int a = 10;
    int b = 20;
    //值传递
    ValueSwap(a, b);
    cout << "a:" << a << " b:" << b << endl;
    //地址传递
    PointerSwap(&a, &b);
    cout << "a:" << a << " b:" << b << endl;
    //引用传递
    ReferenceSwap(a, b);
    cout << "a:" << a << " b:" << b << endl;
}

char *getString()
{
    char str[] = "hello world!";

    return str;
}




int main15(){


    return 0;
}