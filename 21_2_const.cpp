/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/15 上午 11:02
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

struct Person
{
    char name[64];
    int age;
    int ID;
    double score;
};

//规避地址传递的副作用(在使用对象指针的情况下，有可能意外修改数据)
void PrintPerson(const struct Person *person) // 指针只占4个字节
{
    //person->ID = 128; // const 修饰的不能改变值, 如果const struct Person *person 每次要消耗80个字节
    //struct Person *p = (struct Person *)person;

    //printf("Name:%s Age:%d ID:%d Score:%f\n",person.name,person.age,person.ID,person.score);
    printf("Name:%s Age:%d ID:%d Score:%f\n",person->name,person->age,person->ID,person->score);

}

void test21()
{
    struct Person person = { "Trump", 30, 250, 59.9 };
    PrintPerson(&person);
    //PrintPerson(person);
}

int main21() {

    //test21();

    return 0;
}
