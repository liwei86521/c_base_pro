/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/15 下午 04:35
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stddef.h>

using namespace std;

struct Person{
    char *name;
    int age;
};

//分配内存
struct Person** allocateSpace()
{
    struct Person **temp = (struct Person **)malloc(sizeof(struct Person *) * 3);

    for (int i = 0; i < 3; ++i){
        temp[i] = (struct Person *)malloc(sizeof(struct Person));

        temp[i]->name = (char *)malloc(sizeof(char)* 64);

        sprintf(temp[i]->name, "Name_%d", i + 1);

        temp[i]->age = 100 + i;
    }


    return temp;
}

//打印
void printPerson(struct Person **person){
    if (NULL == person){
        return;
    }

    for (int i = 0; i < 3; ++i){
        printf("Name:%s Age:%d\n",person[i]->name,person[i]->age);
    }
}

//释放内存
void freeSpace(struct Person **person){
    if (NULL == person){
        return;
    }

    for (int i = 0; i < 3; ++i){
        if (person[i] == NULL){
            continue;
        }

        if (person[i]->name != NULL){
            printf("Name:%s的内存被释放!\n", person[i]->name);
            free(person[i]->name);
            person[i]->name = NULL;
        }


        free(person[i]);
        person[i] = NULL;
    }

    free(person);
    person = NULL;
}

void test122()
{
    struct Person **person = NULL;
    person = allocateSpace();
    printPerson(person);
    freeSpace(person);
    person = NULL;
}


struct A
{
    char a1; //0
    int a2; //4-7
};

void test123(){
    struct A a = { 'b', 20 };
    printf("A.a2:%d\n", *(int *)((char *)&a + offsetof(struct A, a2)));
    printf("A.a2:%d\n",   *((int *)&a + 1)); // 因为是 int * 所以 +1 就是跳4个字节

}

struct C
{
    int a;
    double b;
};

struct B
{
    char a;
    int b;
    struct C c;
};

void test124(){
    struct B b = { 'a', 20, 30, 3.14 };

    int off1 = offsetof(struct B, c);
    int off2 = offsetof(struct C, b);
    //printf("%d %d \n", off1, off2);

    printf("%f\n", *(double *)(((char *)&b + off1) + off2));
    printf("%d\n", (((char *)&b + off1) + off2) );// 6946272
    printf("%d\n", &(b.c.b)); // 地址和上面是一样的 6946272
    printf("%f\n", ((struct C *)((char *)&b + off1))->b );
}


//1. 第一个元素偏移量是0
//2. 从第二个元素开始计算偏移量
struct Student{
    int a; //0-3
    char b; //4-7
    double c; //8-15
    float d;//16-19
};

void test125()
{
    printf("%d\n", sizeof(struct Student)); // 24
    struct Student stu = { 3, 'a', 30.0, 3.14 };

    int off1 = offsetof(struct Student, c);
    int off2 = offsetof(struct Student, d);
    //printf("%d %d \n", off1, off2);

    printf("%f\n", *(double *)((char *)&stu + off1)); // 取c得值
    printf("%f\n", stu.c); // 取c得值

    printf("%f\n", *(float *)((char *)&stu + off2));

}


int main122(){

    //test123();
    test125();

    return 0;
}