#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
定义一个顺序串
*/
#define MaxLen 255 
typedef struct {
	char ch[MaxLen];			//存储字符串的字符数组
	int length;					//字符串的长度
}String;

/*
求字符串的长度
*/
int StrLength(String* S) {
	int i = 0;
	while (S->ch[i] != '\0')			//'\0'表示字符串的结束符
		i++;
	S->length = i;
	return (S->length);
}

/*
建立一个新串
*/
void CreatStr(String* S) {
	gets_s(S->ch, MaxLen);						//获取输入的字符串
	S->length = StrLength(S);//调用求串长度函数
}

/*创建next数组*/
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

/*完成KMP算法匹配（未优化）*/
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
	printf("输入一个字符串S：");
	CreatStr(S);
	String m;
	String* T = &m;
	printf("输入一个子字符串T：");
	CreatStr(T);
	int next[MaxLen];
	get_next(T, next);
	int n;
	n=Index_KMP(S, T, next);
	if (n != 0) {
		printf("\n匹配的位置为 %d", n);
	}
	else
	{
		printf("未找到匹配的字串!");
	}
	return 0;
}