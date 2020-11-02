#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct LNode{
    int          data;
    struct LNode *next;
}LNode, *LinkList;

LinkList CreateList(int n); //  函数声明
void print(LinkList h);

void static_linklist(){ // 建立静态链表并遍历
    struct LNode node1 = { 10, NULL };
    struct LNode node2 = { 20, NULL };
    struct LNode node3 = { 30, NULL };
    struct LNode node4 = { 40, NULL };
    struct LNode node5 = { 50, NULL };
    struct LNode node6 = { 60, NULL };

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    //先定义一个辅助指针变量
    struct LNode *pCurrent = &node1;
    while (pCurrent != NULL){
        printf("%d ",pCurrent->data);
        pCurrent = pCurrent->next; //指针移动到下一个元素的首地址
    }

}

void test_d_linklist(){
    LinkList Head=NULL;
    int n;

    scanf("%d",&n);
    Head=CreateList(n);

    printf("your list --> ：\n");
    print(Head);

    printf("\n\n");
}

int main14()
{
    test_d_linklist();
    //static_linklist();
    return 0;
}

LinkList CreateList(int n)
{
    LinkList header, pRear ;
    int i;
    header=(LNode*)malloc(sizeof(LNode));
    if(!header) return 0;
    header->data = -1; // header 不存储有效data
    header->next=NULL;

    pRear=header;
    for(i=1;i<=n;i++)
    {
        LinkList newnode=(LinkList)malloc(sizeof(LNode)); //给新节点分配内存
        printf("please input the %d elem val:",i);
        scanf("%d",&(newnode->data)); // 给新节点赋值
        newnode->next=NULL;

        pRear->next=newnode; //新节点插入到链表中
        pRear=newnode; //更新尾部指针指向
    }
    return header;
}

void print(LinkList h)
{   // 因为 head 没有赋值 只是分配了内存 ,所以不能  LinkList p=h
    LinkList p=h -> next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
