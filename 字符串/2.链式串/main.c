#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
���Ľ�������ӡ�����ȣ����룬ɾ����ȡ�Ӵ������������ӵȲ���
*/

/*
����һ����ʽ����������
*/
typedef struct snode {
	char ch;				//������
	struct snode* next;		//ָ����
}LiString;

/*
��ʼ���������ʼ��������Ҫ�ǿ���ͷ��㣬ͬʱ��������һ��ָ��ָ��ΪNULL
*/
LiString* InitString() {
	LiString* S;
	S = (LiString*)malloc(sizeof(LiString));
	if (S->next != NULL)
		S->next = NULL;
	return S;
}

/*
�жϿմ�
*/
bool isEmpty(LiString* S) {
	if (S->next == NULL)
		return false;
	return true;
}

/*
����һ���ַ��������ַ�������ӵ���S�У�β�巨
*/
void CreatStr(LiString* S, char t[]) {
	LiString* p, * q, * r;
	r = S;					//rʼ�ձ�ʾ����β��㣨���һ���ǿսڵ㣬���������һ��NULL�ڵ㣩��
	p = S->next;
	int i = 0;
	for (i; t[i] != '\0'; i++) {
		if (p != NULL)
		{
			p->ch = t[i];
			r = p;
			p = p->next;
		}
		else
		{
			/*��ʼ��ʱֻ��ͷ�������˴洢�ռ�����������)�������Ҫ����������ݣ������ڵ�û����ռ䣩��Ҫ��������*/
			q = (LiString*)malloc(sizeof(LiString));
			q->ch = t[i];
			r->next = q;
			r = q;
		}
	}
	r->next = NULL;
}

/*
��ӡ��
*/
void printStr(LiString* S) {
	LiString* p;
	p = S->next;
	printf("��ӡ�������ַ���:");
	while (p != NULL)
	{
		printf("%c", p->ch);
		p = p->next;
	}
}

/*
���ĳ���
*/
int StrLen(LiString* S) {
	int n = 0;
	LiString* p;
	p = S->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

/*
�����ִ���������S�еĵ�i��λ�ÿ�ʼ�����ִ�S1��
*/
bool StrInsert(LiString* S, int i, LiString* T) {
	LiString* p, * q, * r;
	if (i <= 0 || i > StrLen(S) + 1)
		return false;
	/*�ҵ���i-1��λ��*/
	int j;
	for (j = 0, p = S; j < i - 1; j++)
		p = p->next;
	q = T->next;
	while (q != NULL) {
		r = (LiString*)malloc(sizeof(LiString));
		r->ch = q->ch;
		r->next = q->next;
		p->next = r;
		q = q->next;
		p = r;
	}
	return true;
}

/*
ɾ���ִ�����λ��i��ʼ��ɾ������Ϊlen���ִ�
*/
bool StrDelete(LiString* S, int i, int len) {
	LiString* p;
	LiString* q;
	if (i <= 0 || i > StrLen(S) || i + len > StrLen(S) + 1)
	{
		printf("ɾ������\n");
		return false;
	}
	/*�ҵ���i-1��λ��*/
	int j;
	for (j = 0, p = S; j < i - 1; j++) {
		p = p->next;
	}
	/*��iλ�ÿ�ʼɾ������λlen���ִ�*/
	for (j = 0; j < len; j++)
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}
	return true;
}

/*
��ȡ�ִ��������ӵ�i��λ�ÿ�ʼ���ҳ�����Ϊlen���ִ�����������뵽��T�У��ɹ�����1��ʧ�ܷ���0
*/
int SubString(LiString* S, LiString* T, int i, int len) {
	LiString* p, * q, * r, * u;
	if (i <= 0 || i > StrLen(S) || i + len - 1 > StrLen(S))
		return 0;
	/*ָ��ָ��s�ĵ�i-1��λ��*/
	int j, k;
	for (j = 0, p = S; j < i; j++)
		p = p->next;

	for (k = 0, r = T, q = T->next; k < len; k++)
	{
		if (q != NULL)
		{
			q->ch = p->ch;
			r = q;
			q = q->next;
		}
		else
		{
			u = (LiString*)malloc(sizeof(LiString));
			u->ch = p->ch;
			r->next = u;
			r = u;
		}
		p = p->next;
	}
	return 1;
}

/*
��������������T����ֵ��ֵ��S��
*/
void StrCopy(LiString* S, LiString* T) {
	LiString* p, * q, * r, * u;
	p = T->next;
	q = S->next;
	r = S;
	while (p != NULL)
	{
		//��Sԭ�ȷ����˿ռ�
		if (q != NULL)
		{
			q->ch = p->ch;
			r = q;
			q = q->next;
		}
		//����Sԭ�ȵĿռ䲻����
		else
		{
			u = (LiString*)malloc(sizeof(LiString));
			u->ch = p->ch;
			r->next = u;
			r = u;
		}
		p = p->next;
	}
	r->next = NULL;
}

/*
�����������Ӳ��������ڶ�����S2���ӵ���һ����S1�ĺ��棬�γ�һ���µĴ�����S��
*/
void StrContact(LiString* S, LiString* S1, LiString* S2) {
	LiString* p, * q, * r, * u;
	r = S;
	p = S1->next;
	q = S->next;
	while (p != NULL)
	{
		if (q != NULL)
		{
			q->ch = p->ch;
			r = q;
			q = q->next;
		}
		else
		{
			u = (LiString*)malloc(sizeof(LiString));
			u->ch = p->ch;
			r->next = u;
			r = u;
		}
		p = p->next;
	}
	p = S2->next;
	while (p != NULL)
	{
		if (q != NULL)
		{
			q->ch = p->ch;
			q = q->next;
			r = q;
		}
		else
		{
			u = (LiString*)malloc(sizeof(LiString));
			u->ch = p->ch;
			r->next = u;
			r = u;
		}
		p = p->next;
	}
	r->next = NULL;
}




int main() {
	LiString* S, * S1, * S2;
	int i, len;
	S = InitString();
	S1 = InitString();
	S2 = InitString();
	char str[50];
	printf("�������ַ���:\n");
	gets_s(str, 50);
	CreatStr(S, str);
	CreatStr(S1, str);
	printf("�ַ�������Ϊ��%d\n",StrLen(S));
	printStr(S);
	printf("\n****************ɾ���Ӵ�*****************\n");
	printf("���뿪ʼλ�ú�ɾ������:\n");
	scanf("%d", &i); scanf("%d", &len);
	StrDelete(S, i, len);
	printStr(S);
	printf("\n****************������*****************\n");
	StrContact(S2, S, S1);//S��S1���ӳ�S2��ӡ����
	printf("���Ӻ�S2Ϊ��"); printStr(S2);
	printf("\n****************������*****************\n");
	StrCopy(S, S2);//��S2������S��
	printf("������SΪ��");
	printStr(S);
	return 0;
}
