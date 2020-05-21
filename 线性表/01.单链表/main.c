#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*��ͷ���ĵ�����*/
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
/*��ʼ������*/
bool InitList(LinkList L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
	{
		return false;
	}
	L->next = NULL;
	return true;
}
/*ͷ�巨*/
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
/*β�巨*/
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
/*��λ����*/
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
	printf("\n��%dλ�õ���Ϊ��%d",i, p->data);
	return p;
}
/*��ֵ����*/
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
		printf("\n�ڱ�ĵ�%dλ�ҵ�ֵΪ%d�Ľ��", j, e);
	}
	else
	{
		printf("\nδ�ҵ�ֵΪ%d�Ľ��", e);
	}
	return p;
}
/*��������*/
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
		printf("\n����Ԫ�سɹ�!   ");
	}
	else {
		printf("����Ԫ��ʧ��");
	}
}
/*ɾ��Ԫ��*/
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
		printf("\nɾ����%dλ�ϵ�Ԫ��%d�ɹ�!   ", i, x);
	}
	else {
		printf("ɾ��ʧ��");
	}
}
/*******************************/

/*�������е���ֵ*/
void Print(LinkList L) {
	LinkList p;
	p = L->next;
	printf("�������е�ֵΪ:");
	while (p) {
		printf("\n%d", p->data);
		p = p->next;
	}
}
/*��ʼ������*/
LinkList InitList1() {
	LinkList head;
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	return head;

}
/*ͷ�巨��������*/
void Create(LinkList head,int n) {
	LinkList s;
	printf("����\n");
	for (int i = 0; i < n; i++) {
		s = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &s->data);
		s->next = head->next;
		head->next = s;
	}
	printf("����");
}



/*��λ����*/
void printn(LinkList L, int n) {
	int i = 1;
	if (n <= 0) {
		printf("û�ҵ�");
		return;
	}
	if (L->next == NULL) {
		printf("û�ҵ�");
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
	printf("û�ҵ�");
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
