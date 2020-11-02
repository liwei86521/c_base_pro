#include <iostream>
#include <cstring>
#include <stdio.h>
#include "LinkList.h"
using namespace std;

//初始化链表
struct LinkNode *Init_LinkList(){
    //创建头结点
    struct LinkNode *header = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    header->data = -1; // header 不存储有效data
    header->next =NULL;

    //尾部指针  方便创建链表
    struct LinkNode *pRear = header;

    int val = -1; //结束标志
    while (true){
        printf("input insert data:\n");
        scanf("%d",&val);
        if (val == -1){
            break;
        }

        //先创建新节点
        struct LinkNode *newnode = (struct LinkNode *)malloc(sizeof(struct LinkNode));
        newnode->data = val;
        newnode->next = NULL;

        //新节点插入到链表中
        pRear->next = newnode;

        //更新尾部指针指向
        pRear = newnode;
    }

    return header;
}

//遍历
void Foreach_LinkList(struct LinkNode *header){
    if (NULL == header){
        return;
    }

    //辅助指针变量
    struct LinkNode *pCurrent = header->next;// 因为 header 不存有效数据所以 header->next

    while (pCurrent != NULL){
        printf("%d ",pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

//在oldval 前面插入 newval 节点
void InsertByValue_LinkList(struct LinkNode *header, int oldval, int newval) {
    if (NULL == header){
        return;
    }

    //两个辅助指针变量
    struct LinkNode *pPrev = header;
    struct LinkNode *pCurrent = pPrev->next;

    while (pCurrent != NULL){
        if (pCurrent->data == oldval){
            break;
        }

        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }

#if 0
    //如果pCurrent为NULL  说明链表中不存在值为oldval的结点
	if (pCurrent == NULL){
		return;
	}
#endif

    //先创建新结点
    struct LinkNode *newnode = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    newnode->data = newval;
    newnode->next = NULL;

    //新节点插入到链表中
    newnode->next = pCurrent;
    pPrev->next = newnode;
}

//删除值为val的结点
void RemoveByValue_LinkList(struct LinkNode *header, int delValue){
    if (NULL == header){
        return;
    }

    //两个辅助指针变量
    struct LinkNode *pPrev = header;
    struct LinkNode *pCurrent = pPrev->next;

    while (pCurrent != NULL){
        if (pCurrent->data == delValue){
            break;
        }
        //移动两个辅助指针
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }

    if (NULL == pCurrent)
    {
        return;
    }

    //重新建立待删除节点的前驱和后继结点关系
    pPrev->next = pCurrent->next;
    free(pCurrent); //释放删除节点内存  非常重要
    pCurrent = NULL;
}

void Destroy_LinkList(struct LinkNode *header){
    if (NULL == header){
        return;
    }

    //辅助指针变量
    struct LinkNode *pCurrent = header;
    while (pCurrent != NULL){
        //先保存下当前结点的下一个节点地址
        struct LinkNode *pNext = pCurrent->next;
        //释放当前结点内存
        printf("%d节点被销毁!\n", pCurrent->data);
        free(pCurrent);

        //指针向后移动
        pCurrent = pNext;
    }
}

void Reverse_LinkList(struct LinkNode *header) {
    if (NULL == header){
        return ;
    }
    struct LinkNode * newHeader = NULL;
    struct LinkNode * cur = header->next;// 因为 header不存储数据

    while (cur != NULL) {
        struct LinkNode * temp = cur->next;
        cur->next = newHeader;
        newHeader = cur;
        cur = temp;
    }

    header->next = newHeader;
}