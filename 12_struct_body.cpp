#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort2(int arr[], int len) {
    for (int i=0; i < len-1; i++)
        for (int j = i+1; j < len; j++)
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int gcd(int m, int n){   //定义函数
    while (m){
        int temp = m;
        m = n%m;
        n = temp;
    }
    return n;
}

struct Person{
    char name[64];
    int age;
};

void printPersons(struct Person *persons,int len){
    for (int i = 0; i < len; ++i){
        printf("Name:%s Age:%d\n",persons[i].name,persons[i].age);
    }
}

//多个结构体变量
void test12_2(){
    //在栈上分配结构体数组空间
    struct Person persons[] = {
            { "aaa", 20 },
            { "bbb", 30 },
            { "ccc", 40 },
            { "ddd", 50 },
            { "eee", 60 },
            { "fff", 70 },
    };

    int len = sizeof(persons) / sizeof(struct Person);
    printPersons(persons, len);

    //在堆上分配结构体数组空间
    struct Person *ps = (struct Person *)malloc(sizeof(struct Person) * 6);
    for (int i = 0; i < 6;++i){
        //strcpy((ps+i)->name,"Lilei");
        sprintf( ps[i].name, "Name_%d", i + 1 ); // 赋值
        //ps[i].age = 100 + i;
        (ps+i)->age = 100 + i;
    }

    printPersons(ps, 6);
}

void test12_3(){
    struct Person person1 = { "aaa", 20 };
    struct Person person2 = { "bbb", 30 };

    //赋值操作
    person1 = person2;

    printf("Name:%s Age:%d\n",person1.name,person1.age);
    printf("Name:%s Age:%d\n",person2.name,person2.age);
}

struct Teacher
{
    char *name; // 字符串
    int age;
};


void test12_5()
{
    struct Teacher teacher1;
    teacher1.name = (char *)malloc(sizeof(char)* 64);
    memset(teacher1.name, 0, 64);
    strcpy(teacher1.name, "aaa");
    teacher1.age = 20;

    struct Teacher teacher2;
    teacher2.name = (char *)malloc(sizeof(char)* 128);
    memset(teacher2.name, 0, 128);
    strcpy(teacher2.name, "bbbbbbbbbbbbb");
    teacher2.age = 30;

    printf("Name:%s Age:%d\n", teacher1.name,teacher1.age);
    printf("Name:%s Age:%d\n", teacher2.name, teacher2.age);


    printf("teacher1 size: %d\n",sizeof(teacher1));
    printf("teacher2 size: %d\n", sizeof(teacher2));


    if (teacher1.name != NULL)
    {
        free(teacher1.name);
        teacher1.name = NULL;
    }

    teacher1.name = (char *)malloc(strlen(teacher2.name) + 1);
    strcpy(teacher1.name, teacher2.name);
    teacher1.age = teacher2.age;

    printf("---------------\n");
    printf("Name:%s Age:%d\n", teacher1.name, teacher1.age);
    printf("Name:%s Age:%d\n", teacher2.name, teacher2.age);

    //释放堆内存
    if (teacher1.name != NULL){
        free(teacher1.name);
        teacher1.name = NULL;
    }

    if (teacher2.name != NULL){
        free(teacher2.name);
        teacher2.name = NULL;
    }

}

int main12(){
    test12_5();

    return 0;
}