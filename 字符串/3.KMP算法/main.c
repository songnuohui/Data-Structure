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
		return i - T->length;
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
	int next[MaxLen];
	get_next(T, next);
	int n;
	n=Index_KMP(S, T, next);
	if (n != 0) {
		printf("\nƥ���λ��Ϊ %d", n);
	}
	else
	{
		printf("δ�ҵ�ƥ����ִ�!");
	}
	return 0;
}