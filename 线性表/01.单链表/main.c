#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*带头结点的单链表*/
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
/*初始化链表*/
bool InitList(LinkList L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
	{
		return false;
	}
	L->next = NULL;
	return true;
}
/*头插法*/
LinkList List_HeadInsert(LinkList L) {
	LNode*s; int x;
	L->next = NULL;
	scanf("%d", &x);
	while (x!=999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
/*尾插法*/
LinkList CreatList(LinkList L) {
	int x;
	LNode* s, * last = L;
	scanf("%d", &x);
	while (x != 999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		last->next = s;
		last = s;
		scanf("%d", &x);
	}
	last->next = NULL;
	return L;
}
/*按位查找*/
LNode* GetElem(LinkList L, int i) {
	LNode* p = L->next;
	int j = 1;
	if (i == 0) {
		return L;
	}
	if (i < 1) {
		return NULL;
	}
	while (p && j<i) {
		p = p->next;
		j++;
	}
	printf("\n第%d位置的数为：%d",i, p->data);
	return p;
}
/*按值查找*/
LNode* LocateElem(LinkList L, int e) {
	int j = 1;
	LNode* p = L->next;
	while (p&&p->data!=e)
	{
		p = p->next;
		j++;
	}
	if (p!=NULL)
	{
		printf("\n在表的第%d位找到值为%d的结点", j, e);
	}
	else
	{
		printf("\n未找到值为%d的结点", e);
	}
	return p;
}
/*插入数据*/
void InsertList(LinkList L, int i, int e) {
	int j = 0;
	LNode* s, * p = L;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p != NULL) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		printf("\n插入元素成功!   ");
	}
	else {
		printf("插入元素失败");
	}
}
/*删除元素*/
void delList(LinkList L, int i) {
	int j = 0;
	int x;
	LNode* s, * p = L;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p != NULL&&j==i-1) {
		s = p->next;
		x = s->data;
		p->next = s->next;
		free(s);
		printf("\n删除第%d位上的元素%d成功!   ", i, x);
	}
	else {
		printf("删除失败");
	}
}
/*******************************/

/*遍历所有的数值*/
void Print(LinkList L) {
	LinkList p;
	p = L->next;
	printf("遍历所有的值为:");
	while (p) {
		printf("\n%d", p->data);
		p = p->next;
	}
}
/*初始化链表*/
LinkList InitList1() {
	LinkList head;
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	return head;

}
/*头插法创建链表*/
void Create(LinkList head,int n) {
	LinkList s;
	printf("输入\n");
	for (int i = 0; i < n; i++) {
		s = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &s->data);
		s->next = head->next;
		head->next = s;
	}
	printf("结束");
}



/*按位查找*/
void printn(LinkList L, int n) {
	int i = 1;
	if (n <= 0) {
		printf("没找到");
		return;
	}
	if (L->next == NULL) {
		printf("没找到");
		return;
	}
	LinkList p=L->next;
	while (i<n&&p->next!=NULL) {
		p = p->next;
		i++;
	}
	if (i == n) {
		printf("\n%d", p->data);
		return;
	}
	printf("没找到");
}
int main() {
	LNode L;
	InitList(&L);
	//List_HeadInsert(&L);
	CreatList(&L);
	Print(&L);
	GetElem(&L, 3);
	LocateElem(&L, 3);
	InsertList(&L, 2, 100);
	Print(&L);
	delList(&L, 4);
	Print(&L);
/*******************************/
	/*LinkList L = InitList1();
	Create(L,10);
	Print(L);
	printn(L, 5);*/
	return 0;
}
