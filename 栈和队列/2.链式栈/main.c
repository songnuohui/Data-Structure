#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
������ʽջ���Ͷ��嵥����һ��
*/
typedef struct Stacknode {
	int data;
	int length;
	struct Stacknode* next;
}LinkStack;
/*
��ʼ����ʽջ
*/
LinkStack* InitStack() {
	LinkStack* S;
	S = NULL;
	return S;
}
/*
�ж�ջ��
*/
bool StackEmpty(LinkStack* S) {
	if (S == NULL)
		return true;
	return false;
}
/*
��ջ
*/
LinkStack* PushStack(LinkStack* S, int x) {
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = S;
	S = p;
	S->length++;
	return S;
}
/*
��ջ
*/
LinkStack* PopStack(LinkStack* S, int* x) {
	LinkStack* p;
	if (StackEmpty(S)) {
		return NULL;
	}
	*x = S->data;
	p = S;
	S = S->next;
	S->length--;
	free(p);
	return S;
}
/*
��ȡջ��Ԫ��
*/
bool GetStack(LinkStack* S, int* x) {
	if (S == NULL)
		return false;
	*x = S->data;
	return true;
}
int main() {
	LinkStack* S;
	S = InitStack();
	int n, x;
	printf("������ջԪ�ظ�����");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		S=PushStack(S, x);
	}
	/**************��ȡջ��Ԫ��*******************/
	GetStack(S, &x);
	printf("ջ��Ԫ�أ�%d", x);

	printf("�������ջԪ�ظ�����");
	scanf("%d", &n);
	printf("��ջԪ��Ϊ��");
	for (int i = 0; i < n; i++) {
		S=PopStack(S, &x);
		if(S!=NULL)
			printf("%2d", x);
	}
	return 0;
}