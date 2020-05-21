#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*定义双链表*/
typedef struct DNode {//定义双链表结点类型
	int data;
	struct DNode* prior, * next;//前驱和后继指针
}DNode,*DLinklist;
/*初始化双链表*/
bool InitDLinkList(DLinklist L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior=NULL;
	L->next = NULL;
	return true;
}
/*双链表的插入(后插):在p结点后插入s结点*/
bool InsertLinkList(DNode* p, DNode* s) {
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if (p->next != NULL)
		p->next->prior = s; 
	s->prior = p;
	p->next = s;
	return true;
}
/*双链表的删除：删除后继结点*/
bool DelLinkLinst(DNode* p) {
	if (p == NULL) return false;
	DNode* q = p->next;//找到p的后继结点q
	if (q == NULL) return false;//p没有后继结点
	if (q ->next!= NULL) {
		q->next->prior = p;
	}
	free(q);
	return true;
}
/*销毁双链表*/
void DestoryList(DLinklist L) {
	//循环各个数据结点
	while (L->next != NULL) {
		DelLinkLinst(L);
	}
	free(L);
	L = NULL;
}
/*遍历双链表*/

int main() {
	printf("hello word");
	return 0;
}
