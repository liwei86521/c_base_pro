#include <iostream>
#include <cstring>

using namespace std;

//1. 主调函数分配内存，被调函数使用内存  指针的输入特性
void printString(const char *str)
{
    printf("打印内容:%s\n", str + 2);
}

void printStringArray(char **arr,int len)
{
    //arr[0]是char*类型的
    for (int i = 0; i < len; ++i)
    {
        printf("%s\n",arr[i]);
    }
}

void test13() {
    //堆上分配内存
    char * s = (char *) malloc(sizeof(char) * 100);
    //memset(s, 0, 100);
    strcpy(s, "I am Polly!");
    printString(s);

    //栈上分配
    char* strs[] = {
            "aaaaa",
            "bbbbb",
            "ccccc",
            "ddddd",
            "eeeee",
    };

    int len = sizeof(strs) / sizeof(strs[0]);
    printStringArray(strs, len);

}

//2. 输出特性 被调函数分配内存，主调函数使用内存
void allocateSpace(char **temp)
{
    char *p = (char *)malloc(100);
    memset(p, 0, 100); // memset是C/C++语言初始化函数。作用是将某一块内存中的内容全部设置为指定的值,这个函数通常为新申请的内存做初始化工作
    strcpy(p, "hello world!");
    *temp = p; //指针的间接赋值
}

void test17()
{
    char *p = NULL;
    allocateSpace(&p);
    printf("p = %s\n", p);

    if (p != NULL)
    {
        free(p); //释放内存
        p = NULL;
    }
}

//指针的类型，不单单决定指针的步长，还决定解引用的时候从给定地址开始取类型大小的字节数
void test11_1()
{
    char *p = NULL;
    printf("%d\n", p); // 0
    printf("%d\n", p + 1); // 1

    printf("----------------\n");
    int *p2 = NULL;
    printf("%d\n", p2); // 0
    printf("%d\n", p2 + 1); // 4

    printf("----------------\n");


    char buf[1024] = { 0 };
    int a = 100;
    memcpy(buf+1,&a,sizeof(int));

    char *p3 = buf;
    printf("*(int *)(p3 + 1) = %d\n", *(int *)(p3 + 1));
}


struct Person
{
    int a;
    char b;
    char buf[64];
    int d;
};

void test11_2()
{
    struct Person p = { 10, 'a', "hello world!", 100 };
    printf("a off:%d\n", offsetof(struct Person,b));

    printf("d off%d\n", offsetof(struct Person, d));
    printf("d = %d\n", *(int *)((char *)&p + offsetof(struct Person, d)));
}

void changePointer(int **val)
{
    *val =(int *)0x008;
}

void test11_3()
{
    int* p = NULL;
    changePointer(&p);

    printf("p = %x\n", p);
}


int main17(){
    test11_3();
    //test13();
    //test17();

    return 0;
}