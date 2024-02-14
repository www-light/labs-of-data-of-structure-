#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000    //图书表可能达到的最大长度
using namespace std;
typedef struct
{//图书信息定义
    char no[20];    //图书ISBN
    char name[50];   //图书名字
    float price;   //图书价格
}Book;
typedef struct LNode
{//图书信息表的链式存储结构
    Book data;    	   //结点的数据域
    int length;       //链表的表长，即图书表中图书个数
    struct LNode* next; //指针域
}LNode, * LinkList;
int DupRemoval_L(LinkList& L)
{//图书去重
    LinkList newllist = new LNode;
    LinkList p1 = new LNode;
    newllist->next = NULL;
    LinkList p = new LNode;
    p = L;
    int flag = 0;
    LinkList tail = new LNode;
    tail->next = NULL;
    tail = newllist;
    while (p->next)
    {
        p1 = newllist;
        p = p->next;
        flag = 0;
        while (p1->next)
        {
            p1 = p1->next;
            if (p1!=NULL&&strcmp(p->data.no, p1->data.no) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            LinkList one = new LNode;
            one->next = NULL;
            one->data = p->data;
            tail->next = one;
            tail = one;
        }
    }
    L = newllist;
    return 1;
}
int InitList_L(LinkList& L)
{//构造一个空的单链表L
    L = new LNode;
    L->next = NULL;
    return OK;
}
int Input_L(LinkList& L)
{
    LinkList p = L;      //初始化p指向链表的头结点
    int n;
    cin >> n;
    while (n--)             	     //后插法创建链表
    {
        LinkList q = new LNode;        //生成新结点*q
        cin >> q->data.no >> q->data.name >> q->data.price;//输入数据
        q->next = NULL;                                 //尾指针置为NULL
        p->next = q;                   //将新结点*q插入尾结点*p之后
        p = q;                         //更新指针p，将p指向新的尾结点*q
    }
    return OK;
}
int  Length_L(LinkList& L)
{//求链表的表长，即图书表中图书个数
    LinkList p = L;                 //初始化p指向链表的头结点
    L->length = 0;                  //初始化链表的表长L->length为0
    while (p->next)                //下一个结点存在时
    {
        L->length++;              //链表的表长+1
        p = p->next;                //更新指针p，指向下一个结点
    }
    return OK;
}
int Output_L(LinkList L)
{//链表的输出
    Length_L(L);
    cout << L->length << endl;   //去重后的图书数目
    LinkList p = L;           //初始化p指向链表的头结点
    while (p->next)                	//下一个结点存在时
    {
        cout << p->next->data.no << " " << p->next->data.name << " " << fixed << setprecision(2) << p->next->data.price << endl;
        p = p->next;    //更新指针p，指向下一个结点
    }
    return OK;
}
int main()
{
    LinkList L;                         //定义一个LinkList类型的变量L
    InitList_L(L);                      //初始化一个空的链表L
    Input_L(L);                         //输入链表数据
    DupRemoval_L(L);                   //查重删除
    Output_L(L);                        //链表的输出
    return 0;
}