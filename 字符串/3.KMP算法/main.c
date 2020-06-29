#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
����һ��˳��
*/
#define MaxLen 255 
typedef struct {
	char ch[MaxLen];			//�洢�ַ������ַ�����
	int length;					//�ַ����ĳ���
}String;

/*
���ַ����ĳ���
*/
int StrLength(String* S) {
	int i = 0;
	while (S->ch[i] != '\0')			//'\0'��ʾ�ַ����Ľ�����
		i++;
	S->length = i;
	return (S->length);
}

/*
����һ���´�
*/
void CreatStr(String* S) {
	gets_s(S->ch, MaxLen);						//��ȡ������ַ���
	S->length = StrLength(S);//�����󴮳��Ⱥ���
}


/**********************�Ż���KMP�㷨**************************/

/*�Ż�next����*/
void get_nextval(String* T, int nextval[]) {
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i<T->length)
	{
		if (j == 0 || T->ch[i] == T->ch[j])
		{
			++i;
			++j;
			if (T->ch[i] != T->ch[j])
			{
				nextval[i] = j;
			}
			else
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j];
		}
	}
}

int new_KMP(String* S, String* T, int nextval[]) {
	int i = 1, j = 1;
	while (i<S->length&&j<T->length)
	{
		if (j == 0 || S->ch[i] == T->ch[j])
		{
			++i; ++j;
		}
		else
		{
			j = nextval[j];
		}
	}
	if (j >= T->length)
	{
		return i - T->length+1;
	}
	else
	{
		return 0;
	}
}


/**********************δ�Ż���KMP�㷨**************************/
/*����next����*/
void get_next(String *T, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T->length) {
		if (j == 0 || T->ch[i] == T->ch[j]) 
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

/*���KMP�㷨ƥ�䣨δ�Ż���*/
int Index_KMP(String* S, String* T, int next[]) {
	int i = 1, j = 1;
	while (i<=S->length&&j<T->length)
	{
		if (j == 0 || S->ch[i] == T->ch[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j>=T->length)
	{
		return i - T->length+1;
	}
	else
	{
		return 0;
	}
}

int main() {
	printf("hello word");
	String x;
	String* S = &x;
	printf("����һ���ַ���S��");
	CreatStr(S);
	String m;
	String* T = &m;
	printf("����һ�����ַ���T��");
	CreatStr(T);

/**********************δ�Ż���KMP�㷨**************************/
	int next[MaxLen];
	get_next(T, next);
	int n;
	n=Index_KMP(S, T, next);
	printf("\n\nδ�Ż���KMP�㷨:");
	if (n != 0) {
		printf("ƥ���λ��Ϊ %d", n);
	}
	else
	{
		printf("δ�ҵ�ƥ����ִ�!");
	}

/**********************�Ż���KMP�㷨**************************/
	int nextval[MaxLen];
	get_nextval(T, nextval);
	int a;
	a = new_KMP(S, T, nextval);
	printf("\n\n�Ż���KMP�㷨:");
	if (a != 0) {
		printf("ƥ���λ��Ϊ %d\n\n", a);
	}
	else
	{
		printf("δ�ҵ�ƥ����ִ�!\n\n");
	}
	return 0;
}