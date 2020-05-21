#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*����˫����*/
typedef struct DNode {//����˫����������
	int data;
	struct DNode* prior, * next;//ǰ���ͺ��ָ��
}DNode,*DLinklist;
/*��ʼ��˫����*/
bool InitDLinkList(DLinklist L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior=NULL;
	L->next = NULL;
	return true;
}
/*˫����Ĳ���(���):��p�������s���*/
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
/*˫�����ɾ����ɾ����̽��*/
bool DelLinkLinst(DNode* p) {
	if (p == NULL) return false;
	DNode* q = p->next;//�ҵ�p�ĺ�̽��q
	if (q == NULL) return false;//pû�к�̽��
	if (q ->next!= NULL) {
		q->next->prior = p;
	}
	free(q);
	return true;
}
/*����˫����*/
void DestoryList(DLinklist L) {
	//ѭ���������ݽ��
	while (L->next != NULL) {
		DelLinkLinst(L);
	}
	free(L);
	L = NULL;
}
/*����˫����*/

int main() {
	printf("hello word");
	return 0;
}
