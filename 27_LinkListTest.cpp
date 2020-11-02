#include <iostream>
#include <cstring>
#include <stdio.h>
#include "LinkList.h"

using namespace std;

void test_27_1(){
    //初始化链表 100 200 666 300 400 500 600
    struct LinkNode *header =  Init_LinkList();
    //打印链表
    Foreach_LinkList(header);
    //插入数据
    InsertByValue_LinkList(header, 200, 666);
    //打印链表
    printf("\n-------------------\n");
    Foreach_LinkList(header);

    // 删除节点
    RemoveByValue_LinkList(header,200);
    printf("\n-------------------\n");
    Foreach_LinkList(header);

    Reverse_LinkList(header);
    printf("\n-------------------\n");
    Foreach_LinkList(header);

    Destroy_LinkList(header); //销毁链表

}

int main27() {
    test_27_1();

    return 0;
}
