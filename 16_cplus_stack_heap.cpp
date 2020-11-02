#include <iostream>
#include <cstring>

using namespace std;

//定义变量的时候一定要初始化，很多的Bug产生都是由于没有初始化造成的。
void allocateSpace(char *p)
{
    p = (char *) malloc(100);
    memset(p,0,100);
    strcpy(p, "hello world!");
}
void test02(){
    char *p = NULL;
    allocateSpace(p);
    printf("p = %s\n",p);
}

void allocateSpace02(char **p){
    char *temp = (char *) malloc(100);
    //memset(temp, 0, 100);
    strcpy(temp, "hello world!");

    *p = temp;
}

void test03(){
    char *p = NULL;
    allocateSpace02(&p);
    printf("p = %s\n", p);
}



int main16(){


    return 0;
}