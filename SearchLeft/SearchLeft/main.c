#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
#define MaxSize 100		
typedef struct node {
	char data;		//数据域
	struct node* lchild, * rchild;	//左右孩子指针
}BiTree;

/*初始化二叉树*/
BiTree* InitTree() {
	BiTree* T;
	T = (BiTree*)malloc(sizeof(BiTree));
	T = NULL;
	return T;
}
/*构建二叉树*/
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
		printf("请输入%c的左孩子结点：", T->data);
		T->lchild = CreateTree();
		printf("请输入%c的右孩子结点：", T->data);
		T->rchild = CreateTree();
	}
	return T;
}
void ShowTree(BiTree* T) {
	if (T != NULL) {				//当二叉树非空时
		printf("%c", T->data);
		if (T->lchild != NULL)		//当左子树非空时
		{
			printf("(");
			ShowTree(T->lchild);	//递归调用该函数输出其左子树各个结点
			if (T->rchild != NULL) {
				printf(",");
				ShowTree(T->rchild);//递归调用该函数输出其右子树各个结点
			}
			printf(")");
		}
		else if (T->rchild != NULL)	//当右子树非空时
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
	printf("说明：输入'0'表示后继结点为空！");
	printf("\n输入根节点：");
	T = CreateTree();
	printf("\n利用广义表表示法显示二叉树：");
	ShowTree(T);
	printf("hello");
	/*先序遍历*/
	printf("\n先序遍历的结果: ");
	PreOrder(T);
	char c;
	c = SearchLeft(T);
	printf("\n最底层最左的元素: ");
	printf("%c", c);
	c = search(T);
	printf("\n最底层最左的元素: ");
	printf("%c", c);
}