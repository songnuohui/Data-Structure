#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
#define MaxSize 100					//���д洢����
/*�������Ľ���������
				��ʼ�������������������ٶ����������ù������ʾ������
				�����������������������������α���
				�������������ȣ�Ҷ�ӽڵ������������
*/
//��ʽ�ṹ
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
		printf("������%c�����ӽ�㣺",T->data);
		T->lchild = CreateTree();
		printf("������%c���Һ��ӽ�㣺", T->data);
		T->rchild = CreateTree();
	}
	return T;
}
/*���ٶ�����*/
void DestoryTree(BiTree* T) {
	if (T == NULL)
		return;
	DestoryTree(T->lchild);
	DestoryTree(T->rchild);
	free(T);
}
/*���ù�����ʾ����ʾ������*/
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
/*�������*/
void PreOrder(BiTree* T) {
	if (T != NULL)
	{
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
/*�������*/
void InOrder(BiTree* T) {
	if (T != NULL)
	{
		PreOrder(T->lchild);
		printf("%c", T->data);
		PreOrder(T->rchild);
	}
}
/*�������*/
void PostOrder(BiTree* T) {
	if (T != NULL)
	{
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		printf("%c", T->data);
	}
}
/*��α���*/
void LevelOrder(BiTree* T) {
	int f, r;						//����ͷβָ��
	BiTree* p, * q[MaxSize];		//����һ��ѭ������
	p = T;
	if (p != NULL) {				//����������ǿգ�����ڵ����
		f = 1; q[f] = p; r = 2;
	}
	while (f!=r)					//������в�Ϊ��
	{
		p = q[f];
		printf("%c", p->data);		//���ʶ��׽��
		if (p->lchild != NULL) {
			q[r] = p->lchild;		//������ڵ����ӷǿ������
			r = (r + 1) % MaxSize;
		}
		if (p->rchild != NULL) {
			q[r] = p->rchild;		//������ڵ��к��ӷǿ������
			r = (r + 1) % MaxSize;
		}
		f = (f + 1) % MaxSize;
	}
}
/*�����������*/
int TreeDepth(BiTree* T) {
	int left = 0;
	int right = 0;
	if (T == NULL)
		return 0;
	else
	{
		left = TreeDepth(T->lchild);
		right = TreeDepth(T->rchild);
		return left > right ? left+1 : right+1;
	}
}
/*Ҷ�ӽ������*/
int count=0;
int LeafNode(BiTree* T) {
	if (T == NULL)
		return 0;
	if (T) {
		if (T->lchild == NULL && T->rchild == NULL)
			count++;
		LeafNode(T->lchild);
		LeafNode(T->rchild);
	}
	return count;
}
/*�ܽ����*/
int sum = 0;
int NodeCount(BiTree* T) {
	if (T) {
		sum++;
		NodeCount(T->lchild);
		NodeCount(T->rchild);
	}
	return sum;
}

int main() {
	BiTree *T;
	T=InitTree();
	printf("˵��������'0'��ʾ��̽��Ϊ�գ�");
	printf("\n������ڵ㣺");
	T = CreateTree();
	ShowTree(T);
	/*�������*/
	printf("\n��������Ľ��: ");
	PreOrder(T);
	/*�������*/
	printf("\n��������Ľ��: ");
	InOrder(T);
	/*�������*/
	printf("\n��������Ľ��: ");
	PostOrder(T);
	/*��α���*/
	printf("\n��α����Ľ��: ");
	LevelOrder(T);
	/*���������*/
	printf("\n�����������Ϊ: %d",TreeDepth(T));
	/*Ҷ�ӽ������*/
	printf("\nҶ�ӽ������Ϊ: %d", LeafNode(T));
	/*�������*/
	printf("\n�������������Ϊ: %d", NodeCount(T));
	return 0;
}
