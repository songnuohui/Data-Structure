#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*������̬����������*/
#define MaxSize 20
/*��һ��*/
struct Node
{
	int data;
	int next;
};
/*�ڶ���*/
typedef struct {
	int data;
	int next;
} SLinkList [MaxSize] ;
/*�������ִ�������*/
void testSLinkList() {
	struct Node x;
	printf("sizeX=%d\n", sizeof(x));
	struct Node a[MaxSize];
	printf("sizeA=%d\n", sizeof(a));
	SLinkList b;
	printf("sizeB=%d\n", sizeof(b));
}
/**************************************************************/
/*��ʼ������*/
bool InitList(SLinkList L) {
	for (int i = 0; i < MaxSize - 1; i++) {
		L[i].next = i + 1;
	}
	L[MaxSize - 2].next = 0;//�жϱ��������Ƿ�Ϊ��
	L[MaxSize - 1].next = 0;//�������Ԫ�ص��±꣬��������Ϊ�գ�����Ϊ0
	return true;
}
/**************************************************************/
/*������ĳ���*/
int ListLength(SLinkList L) {
	int i = 0;
	int j = L[MaxSize-1].next;
	while (j)
	{
		j = L[j].next;
		i++;
	}
	return i;
}

/**************************************************************/
/*�������i��λ�ò���Ԫ��*/

//���ر��������׽����±�,����������Ϊ�գ��򷵻�0
/*�Լ�ʵ�ֶ�̬���亯��*/

//���ر��������׽����±�,����������Ϊ�գ��򷵻�0
int Molloc_L(SLinkList L)
{
	int i = L[0].next;//iָ���һ�����
	if (L[0].next) {
		L[0].next = L[i].next;
	}
	return i;

}
bool InsertList(SLinkList L, int i, int e) {
	if (i<1 || i>ListLength(L) + 1)
		return false;
	int j = Molloc_L(L);
	int k = MaxSize - 1;
	if (j)//��������ǿ�
	{
		L[j].data = e;
		for (int s = 1; s <= i - 1; s++)
			k = L[k].next;      //��ͷ����������i-1��Ԫ��,���ҵ�Ԫ�ز�����Ǹ�λ��
		L[j].next = L[k].next;
		L[k].next = j;
		return true;
	}
	else
	{
		printf("��������Ϊ�գ�\n");
		return false;
	}
}
/**************************************************************/
/*ɾ����i��Ԫ��*/
/*�ֶ�ʵ��free����*/
void Free_L(SLinkList L, int j) {//��λ��Ϊj�Ŀ��н���ͷ�  �������뵽���������һ�����ǰ
	L[j].next = L[0].next;
	L[0].next = j;
}
bool DelList(SLinkList L, int i) {
	if (i<1 || i>ListLength(L) + 1) {
		return false;
	}
	int k = MaxSize - 1;
	int j;
	for (int s = 1; s <= i - 1; s++) {//�ҵ���i-1��λ��
		k = L[k].next;
	}
	j = L[k].next;
	L[k].next = L[j].next;
	Free_L(L, j);
	printf("ɾ���ɹ���");
	return true;
}
/****************************************************************/
/*��λ����*/
bool SelectList(SLinkList L,int i) {
	if (i<1 || i>ListLength(L) + 1)
		return false;
	int k = MaxSize - 1;
	for (int s = 1; s <= i - 1; s++)
		k = L[k].next;				    //�ҵ���i-1��λ��
	int j = L[k].next;					//��ȡ��i��λ�õ��α�ֵ
	printf("���ҵ�%d������ֵ��%d",i, L[j].data);
}
/****************************************************************/
/*������̬����*/
void SelectAllList(SLinkList L) {
	int j = 0;
	int i = L[MaxSize - 1].next;
	while (i) {
		++j;
		printf("��%d������ǣ�%d\n", j, L[i].data);
		i = L[i].next;
	}
}

/**************************************************************/

int main() {
	SLinkList L;//��������
	InitList(L);//��ʼ������
	int d = ListLength(L);
	printf("��ʼ����ĳ���Ϊ��%d\n",d );
	for (int i = 1; i <= 3; i++) {
		InsertList(L, 1, i);
	}
	SelectAllList(L);
	printf("������Ϊ��%d\n", ListLength(L));
	InsertList(L, 2, 100);
	printf("���������");
	SelectAllList(L);
	printf("������Ϊ��%d\n", ListLength(L));
	DelList(L, 2);
	printf("���������");
	SelectAllList(L);
	SelectList(L, 3);
	//testSLinkList();
	return 0;
}
