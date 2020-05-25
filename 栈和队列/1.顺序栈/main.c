#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
����һ��˳��ջ
*/
#define  MaxSize 50			//����ջ��Ԫ��������
typedef struct {
	int data[MaxSize];		//���ջ��Ԫ��
	int top;				//ջ��ָ��
	int size;
}SqStack;
/*
��ʼ��˳��ջ
*/
void InitStack(SqStack *S) {
	S->top = -1;
	S->size = 0;
}
/*
�ж�ջ��
*/
bool StackEmpty(SqStack *S) {
	if (S->top == -1)
	{
		return true;
	}
	return false;
}
/*
�ж�ջ��
*/
bool FullStack(SqStack *S) {
	if (S->top == MaxSize - 1)
		return true;
	return false;
}
/*
��ջ
*/
bool Push(SqStack *S, int x) {
	if (S->top == MaxSize-1) {
		return false;
	}
	S->top = S->top + 1;		//ָ���ȼ�1
	S->data[S->top] = x;		//��ջ��ֵ
	S->size++;
	return true;
}
/*
��ջ
*/
bool Pop(SqStack *S, int *x) {
	if (S->top == -1) {
		return false;
	}
	*x = S->data[S->top];
	S->top = S->top - 1;
	S->size--;
	return true;
}
/*
��ȡջ��Ԫ��
*/
bool GetTop(SqStack* S, int* x) {
	if (S->top == -1)
		return false;
	*x = S->data[S->top];
	return true;
}

int main() {
	SqStack S;
	InitStack(&S);

/**************��ջ*******************/
	printf("������ջԪ�ظ�����");
	int n; int x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		Push(&S, x);
	}

/**************��ջ*******************/
	printf("\n�����ջԪ�ظ�����");
	scanf("%d", &n);
	if (n > S.size) {
		printf("��������");
		return 0;
	}
	printf("��ջԪ����:\n");
	for (int i = 0; i < n; i++) {
		Pop(&S, &x);
		printf("%d\n", x);
	}
/**************��ȡջ��Ԫ��*******************/
	GetTop(&S, &x);
	printf("��ջ��ɺ��ջ��Ԫ��Ϊ��%d", x);
	return 0;
}
