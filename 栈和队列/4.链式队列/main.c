#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
������ʽ����
*/
typedef struct qNode{					//������ʽ���н��
	int data;						//�������������
	struct qNode* next;			//�������ָ����
}LinkNode;
typedef struct {					//��ʽ����
	LinkNode* font, * rear;			//������е�ͷָ���βָ��
}LinkQueue;							//��ʽ���е�ͷָ������

/*
��ʼ������
*/
void InitQueue(LinkQueue* Q) {
	Q->font = Q->rear = (LinkNode*)malloc(sizeof(LinkNode));    //����ͷ��㣬����ͷβָ��ָ���½��
	Q->font->next = NULL;
}

/*
�ж϶����Ƿ�Ϊ��
*/
bool EmptyQueue(LinkQueue* Q) {
	if (Q->font == Q->rear)
		return true;
	return false;
}


/*
���
*/
bool InQueue(LinkQueue* Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));//�����µĽ��
	s->data = x;				//��X��ֵ�����½���ָ����
	s->next = NULL;
	Q->rear->next = s;			//���½����뵽������ͷ����
	Q->rear = s;				//��βָ��ָ���βԪ��
	return true;
}

/*
����
*/
bool DeQueue(LinkQueue* Q, int* x) {
	if (EmptyQueue(Q))
		return false;
	LinkNode* s=Q->font->next;
	*x = s->data;				//pָ���ͷԪ��
	Q->font->next = s->next;	//��ͷָ���ָ�������¶�ͷԪ�صĵ�ַ
	if (s->next == NULL)		//������ֻ����һ��Ԫ�ص�ʱ�����
		Q->rear = Q->font;		//���Ӻ�ͷָ��ָ��βָ�룬��ʱ����Ϊ��
	free(s);
	return true;
}

/*
�õ���ͷԪ��
*/
void GetHead(LinkQueue* Q, int* x) {
	if (EmptyQueue(Q)) {
		printf("�ӿգ�");
	}
	*x = Q->font->next->data;
}
/*
��������Ԫ��
*/
void ShowQueue(LinkQueue* Q) {
	if (EmptyQueue(Q))
		printf("�ӿգ���Ԫ�أ�");
	LinkNode* s = Q->font;
	while (s!=Q->rear)					//����ͷָ�벻���ڶ�βָ��
	{
		printf("%2d", s->next->data);
		s = s->next;
	}
}

int main() {
	LinkQueue* Q;
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	InitQueue(Q);
	int n, x;
	/***************���*****************/
	printf("�������Ԫ�ظ�����");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		InQueue(Q, x);
	}
	/***************��������Ԫ��*****************/
	printf("\n��������Ԫ��Ϊ��");
	ShowQueue(Q);
	/***************��ʾ��ͷԪ��*****************/
	GetHead(Q, &x);
	printf("\n��ͷԪ��Ϊ��%2d", x);
	/***************����*****************/
	printf("\n���������Ԫ�ظ�����");
	scanf("%d", &n);
	printf("����Ԫ��Ϊ��");
	for (int i = 0; i < n; i++) {
		DeQueue(Q, &x);
		printf("%2d", x);
	}
	return 0;
}