#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
串的建立，打印，长度，插入，删除，取子串，拷贝，连接等操作
*/

/*
定义一个链式串，像单链表
*/
typedef struct snode {
	char ch;				//数据域
	struct snode* next;		//指针域
}LiString;

/*
初始化链表：其初始化操作主要是开辟头结点，同时让它的下一个指针指向为NULL
*/
LiString* InitString() {
	LiString* S;
	S = (LiString*)malloc(sizeof(LiString));
	if (S->next != NULL)
		S->next = NULL;
	return S;
}

/*
判断空串
*/
bool isEmpty(LiString* S) {
	if (S->next == NULL)
		return false;
	return true;
}

/*
建立一个字符串，将字符数组添加到串S中，尾插法
*/
void CreatStr(LiString* S, char t[]) {
	LiString* p, * q, * r;
	r = S;					//r始终表示的是尾结点（最后一个非空节点，而不是最后一个NULL节点）。
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
			/*初始化时只给头结点分配了存储空间或者其他情况)，如果需要继续添加数据（其他节点没分配空间）需要继续分配*/
			q = (LiString*)malloc(sizeof(LiString));
			q->ch = t[i];
			r->next = q;
			r = q;
		}
	}
	r->next = NULL;
}

/*
打印串
*/
void printStr(LiString* S) {
	LiString* p;
	p = S->next;
	printf("打印出来的字符串:");
	while (p != NULL)
	{
		printf("%c", p->ch);
		p = p->next;
	}
}

/*
串的长度
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
插入字串操作：在S中的第i个位置开始插入字串S1；
*/
bool StrInsert(LiString* S, int i, LiString* T) {
	LiString* p, * q, * r;
	if (i <= 0 || i > StrLen(S) + 1)
		return false;
	/*找到第i-1个位置*/
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
删除字串：从位置i开始，删除长度为len的字串
*/
bool StrDelete(LiString* S, int i, int len) {
	LiString* p;
	LiString* q;
	if (i <= 0 || i > StrLen(S) || i + len > StrLen(S) + 1)
	{
		printf("删除错误！\n");
		return false;
	}
	/*找到第i-1个位置*/
	int j;
	for (j = 0, p = S; j < i - 1; j++) {
		p = p->next;
	}
	/*从i位置开始删除长度位len的字串*/
	for (j = 0; j < len; j++)
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}
	return true;
}

/*
截取字串操作：从第i个位置开始，找出长度为len的字串，并将其存入到串T中，成功返回1，失败返回0
*/
int SubString(LiString* S, LiString* T, int i, int len) {
	LiString* p, * q, * r, * u;
	if (i <= 0 || i > StrLen(S) || i + len - 1 > StrLen(S))
		return 0;
	/*指针指向s的第i-1个位置*/
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
串拷贝操作，将T串的值赋值给S串
*/
void StrCopy(LiString* S, LiString* T) {
	LiString* p, * q, * r, * u;
	p = T->next;
	q = S->next;
	r = S;
	while (p != NULL)
	{
		//串S原先分配了空间
		if (q != NULL)
		{
			q->ch = p->ch;
			r = q;
			q = q->next;
		}
		//若串S原先的空间不够用
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
两个串的连接操作：将第二个串S2连接到第一个串S1的后面，形成一个新的串存于S中
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
	printf("请输入字符串:\n");
	gets_s(str, 50);
	CreatStr(S, str);
	CreatStr(S1, str);
	printf("字符串长度为：%d\n",StrLen(S));
	printStr(S);
	printf("\n****************删除子串*****************\n");
	printf("输入开始位置和删除长度:\n");
	scanf("%d", &i); scanf("%d", &len);
	StrDelete(S, i, len);
	printStr(S);
	printf("\n****************串连接*****************\n");
	StrContact(S2, S, S1);//S和S1连接成S2打印出来
	printf("连接后串S2为："); printStr(S2);
	printf("\n****************串拷贝*****************\n");
	StrCopy(S, S2);//将S2拷贝到S中
	printf("拷贝后串S为：");
	printStr(S);
	return 0;
}
