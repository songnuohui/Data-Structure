#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
˳��ṹѭ������
*/
#define MaxSize 50
typedef struct {
	int data[MaxSize];		//��Ŷ���Ԫ��
	int font, rear;			//��ͷָ��Ͷ�βָ��
}SqQueue;
/*
��ʼ��
*/
void InitQueue(SqQueue* Q) {
	Q->font = Q->rear = 0;
}
/*
�Ƿ�Ϊ��
*/
bool EmptyQueue(SqQueue* Q) {
	if (Q->font == Q->rear)
		return true;
	return false;
}
/*
�Ƿ�����
*/
bool FullQueue(SqQueue* Q) {
	if ((Q->rear + 1) % MaxSize == Q->font)
		return true;
	return false;
}
/*
���
*/
bool InQueue(SqQueue* Q, int x) {
	if (FullQueue(Q)) {
		printf("������");
		return false;
	}
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize;		//��βָ���һȡģ
	return true;
}
/*
����
*/
bool DeQueue(SqQueue* Q, int* x) {
	if (EmptyQueue(Q)) {
		printf("�ӿգ�");
		return false;
	}
	*x = Q->data[Q->font];
	Q->font = (Q->font + 1) % MaxSize;
	return true;
}
/*
�õ���ͷԪ��
*/
void GetHead(SqQueue* Q, int* x) {
	if (EmptyQueue(Q)) {
		printf("�ӿգ�");
	}
	*x = Q->data[Q->font];
}
/*
��ʾ��Ԫ��
*/
void ShowQueue(SqQueue* Q) {
	int p = Q->font;
	if (p == Q->rear) {
		printf("�ӿգ���Ԫ�أ�");
	}
	printf("�Ӷ�ͷ����β�ĸ���Ԫ��Ϊ��");
	while (p != Q->rear) {
		printf("%d", Q->data[p]);
		p++;
	}
}
int main() {
	SqQueue* Q;
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	int n, x;
	/***************���*****************/
	printf("�������Ԫ�ظ�����");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		InQueue(Q, x);
	}
	/***************��ʾ��ͷԪ��*****************/
	GetHead(Q, &x);
	printf("��ͷԪ��Ϊ��%2d", x);
	/***************����*****************/
	printf("\n�������ջԪ�ظ�����");
	scanf("%d", &n);
	printf("��ջԪ��Ϊ��");
	for (int i = 0; i < n; i++) {
		DeQueue(Q, &x);
		printf("%2d", x);
	}
	return 0;
}