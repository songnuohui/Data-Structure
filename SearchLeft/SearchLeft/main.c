#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
#define MaxSize 100		
typedef struct node {
	char data;		//������
	struct node* lchild, * rchild;	//���Һ���ָ��
}BiTree;

/*��ʼ��������*/
BiTree* InitTree() {
	BiTree* T;
	T = (BiTree*)malloc(sizeof(BiTree));
	T = NULL;
	return T;
}
/*����������*/
BiTree* CreateTree() {
	BiTree* T;
	char ch;
	scanf("%c", &ch);
	getchar();
	if (ch == '0')
		T = NULL;
	else {
		T = (BiTree*)malloc(sizeof(BiTree));
		T->data = ch;
		printf("������%c�����ӽ�㣺", T->data);
		T->lchild = CreateTree();
		printf("������%c���Һ��ӽ�㣺", T->data);
		T->rchild = CreateTree();
	}
	return T;
}
void ShowTree(BiTree* T) {
	if (T != NULL) {				//���������ǿ�ʱ
		printf("%c", T->data);
		if (T->lchild != NULL)		//���������ǿ�ʱ
		{
			printf("(");
			ShowTree(T->lchild);	//�ݹ���øú���������������������
			if (T->rchild != NULL) {
				printf(",");
				ShowTree(T->rchild);//�ݹ���øú���������������������
			}
			printf(")");
		}
		else if (T->rchild != NULL)	//���������ǿ�ʱ
		{
			printf("(");
			ShowTree(T->lchild);
			if (T->rchild != NULL) {
				printf(",");
				ShowTree(T->rchild);
			}
			printf(")");
		}
	}
}
void PreOrder(BiTree* T) {
	if (T == NULL)return;
	printf("%c", T->data);
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}
char SearchLeft(BiTree* T) {
	BiTree* Q[MaxSize], * p;
	int front, rear;
	front = -1; rear = -1;
	rear = (rear + 1) % MaxSize;
	Q[rear] = T;
	while (front < rear) {
		front = (front + 1) % MaxSize;
		p = Q[front];
		if (p->rchild != NULL) {
			rear = (rear + 1) % MaxSize;
			Q[rear] = p->rchild;
		}
		if (p->lchild != NULL) {
			rear = (rear + 1) % MaxSize;
			Q[rear] = p->lchild;
		}
	}
	return Q[rear]->data;
}
char search(BiTree* T) {
	BiTree* Q[MaxSize];
	int level[MaxSize];
	int front, rear;
	BiTree* p; int k, m, i, last;
	front = -1; rear = -1;
	rear++;
	Q[rear] = T;
	level[rear] = 1;
	while (front < rear) {
		front++;
		p = Q[front];
		k = level[front];
		if (p->lchild != NULL) {
			rear++;
			Q[rear] = p->lchild;
			level[rear] = k + 1;
		}
		if (p->rchild != NULL) {
			rear++;
			Q[rear] = p->rchild;
			level[rear] = k + 1;
		}
	}
	m = level[rear] - 1;
	i = 0, last = -1;
	while (i <= rear && level[i] <= m) {
		last++;
		i++;
	}
	return Q[last + 1]->data;
}
int main() {
	BiTree* T;
	T = InitTree();
	printf("˵��������'0'��ʾ��̽��Ϊ�գ�");
	printf("\n������ڵ㣺");
	T = CreateTree();
	printf("\n���ù�����ʾ����ʾ��������");
	ShowTree(T);
	printf("hello");
	/*�������*/
	printf("\n��������Ľ��: ");
	PreOrder(T);
	char c;
	c = SearchLeft(T);
	printf("\n��ײ������Ԫ��: ");
	printf("%c", c);
	c = search(T);
	printf("\n��ײ������Ԫ��: ");
	printf("%c", c);
}