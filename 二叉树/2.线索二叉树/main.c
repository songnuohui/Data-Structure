#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>

/*�����������洢�ṹ����*/
typedef struct ThreadNode {
	char data;
	struct ThreadNode* lchild, * rchild;		//���Һ���ָ��
	int ltag, rtag;							//����������־
}ThreadTree;

/*���򹹽�����������������*/
ThreadTree* CreateTree() {
	ThreadTree* T;
	char ch;
	scanf("%c", &ch);
	getchar();
	if (ch == '0')
		T = NULL;
	else {
		T = (ThreadTree*)malloc(sizeof(struct ThreadNode));
		T->data = ch;
		printf("������%c�����ӽ�㣺", T->data);
		T->lchild = CreateTree();
		if (T->lchild) {
			T->ltag = 0;
		}
		else
		{
			T->ltag = 1;
		}
		printf("������%c���Һ��ӽ�㣺", T->data);
		T->rchild = CreateTree();
		if (T->rchild) {
			T->rtag = 0;
		}
		else
		{
			T->rtag = 1;
		}
	}
	return T;
}
/*�������*/
void InOreder(ThreadTree* T) {
	if (T != NULL) {
		printf("%c", T->data);
		InOreder(T->lchild);
		InOreder(T->rchild);
	}
}
/*�������������������*/
ThreadTree* pre = NULL;
void InThread(ThreadTree* T) {
	if (T) {
		InThread(T->lchild);
		if (!T->lchild) {//������Ϊ�գ�����ǰ������
			T->ltag = 1;
			T->lchild = pre;
		}
		if (pre && !pre->rchild) {
			pre->rtag = 1;
			pre->rchild = T;	//����ǰ�����ĺ������
		}
		pre = T;
		InThread(T->rchild);
	}
}
/*�����������������*/
void InOrderThread(ThreadTree* T) {
	while (T) {
		//�����ӣ�ֱ���ҵ�����������ŵ�һ��
		while (T->ltag == 0) {
			T = T->lchild;
		}
		printf("%c->", T->data);	//��ӡ�������
		//������ұ�־λΪ1ʱ��ֱ���ҵ����̽��
		while (T->rtag == 1 && T->rchild != NULL) {
			T = T->rchild;
			printf("%c->", T->data);
		}
		//���򣬰�����������Ĺ��ɣ������������������µĽ�㣬Ҳ���Ǽ���ѭ������
		T = T->rchild;
	}
}
/*********************************************************/
/*�������������£�p��ǰ���ڵ�*/
ThreadTree* FirstNode(ThreadTree* p) {
	while (p->ltag == 0) {
		p = p->lchild;				//�������½�㣬��һ����Ҷ�ӽ��
	}
	return p;
}
/*�������������£�T�ĺ�̽ڵ�*/
ThreadTree* NextNode(ThreadTree* p) {
	if (p->rtag == 0) {				//�����������
		p = FirstNode(p->rchild);	//Ѱ�ҵ������������½�㼴ΪT�ĺ�̽��
	}
	else							//���û�������������Һ��Ӿ���T�ĺ�̽��
	{
		p = p->rchild;
	}
	return p;
}
//�������
void InOrderTree(ThreadTree* T) {
	for (ThreadTree* p = FirstNode(T); p != NULL; p = NextNode(p))
		printf("%c->", p->data);
}




int main() {
	ThreadTree* T;
	printf("˵��������'0'��ʾ��̽��Ϊ�գ�");
	printf("\n������ڵ㣺");
	T = CreateTree();
	printf("\n��������Ľ��: ");
	InOreder(T);
	/*����������������*/
	InThread(T);
	printf("\n�������������������������Ľ��: ");
	InOrderThread(T);
	printf("\n����������������������������");
	InOrderTree(T);
	return 0;
}