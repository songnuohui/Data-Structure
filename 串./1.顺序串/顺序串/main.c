#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>

/*
串的插入，删除，查找，比较，取子串，连接等操作
*/

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
	gets(S->ch);						//获取输入的字符串
	S->length = StrLength(S);			//调用求串长度函数
}

/*
求字串：从第i个位置开始，找出长度为len的字串，并将其存入到串Sub中，成功返回1，失败返回0
*/
int SubString(String* S, String* Sub, int i, int len) {
	int j;
	if (i<1 || i>S->length || len<1 || len>(S->length - i + 1)) {
		Sub->length = 0;
		printf("参数错误！");
		return 0;
	}
	else
	{
		for (j = 0; j < len; j++)
			Sub->ch[j] = S->ch[i + j - 1];	//Sub第一个字符等于S中的第i位置的字符，依次++
		Sub->ch[j] = '\0';
		Sub->length = len;
		return 1;
	}
}

/*
删除字串：从位置i开始，删除长度为l的字串
*/
bool StrDelete(String* S, int i, int l) {
	int k;
	if (i<1 || i>S->length || l + i + 1 > S->length) {
		return false;
	}
	else {
		for (k = i + l - 1; k < S->length; k++, i++)
			S->ch[i] = S->ch[k];
		S->length = S->length - l;
		S->ch[S->length] = '\0';			//新串尾部加上字符串结束标志
		return true;
	}
}

/*
插入字串操作：在S中的第i个位置开始插入字串S1；
*/
bool StrInsert(String* S, int i, String *S1) {
	int k;
	if (i<0||i > S->length + 1) {
		printf("插入位置错误！");
		return false;
	}
	else if (S->length + S1->length > MaxLen) {
		printf("长度超出存储空间长度！");
		return false;
	}
	else {
		for (k = S->length - 1; k >= i; k--)			//类似顺序表的插入操作，将第i位开始的字符都向后移动S1的长度
			S->ch[S1->length + k] = S->ch[k];
		for (k = 0; k < S1->length; k++)				//将字串S1插入到S的第i位出
			S->ch[i + k - 1] = S1->ch[k];
		S->length = S->length + S1->length;				//修改串S的长度
		S->ch[S->length] = '\0';						//新串尾部加上字符串结束标志
		return true;
	}
}

/*
串的定位操作:若串S中存在与串T相同的字串，则返回串T在S中第一次出现的位置，否则返回-1
暴力匹配算法
*/
int StrIndex(String* S, String* T) {
	int i = 0; int j = 0; int k;
	while (i < S->length && j < T->length - 1) {
		if (S->ch[i] == T->ch[j]) 
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= T->length)		//在S中含有串T时
		k = i - T->length + 1;
	else
		k = -1;
	return k;
}

/*
判断两个串是否相等：如果相等，返回0；若不相等，返回两个串对应第一个不相同位置的ASCII码的差值
*/
int StrCompare(String* S1, String* S2) {
	/*两个串判断是否相等函数*/
	int i = 0, flag = 0;
	while (S1->ch[i]!='\0'&&S2->ch[i]!='\0')
	{
		if (S1->ch[i]!=S2->ch[i])
		{
			flag = 1;	
			break;					//比较的当前值不相等则跳出循环
		}
		else
		{
			i++;
		}
	}
	if (flag == 0 && S1->length == S2->length)
		return 0;
	else
		return S1->ch[i] - S2->ch[i];			//返回对应第一个不相同位置字符ASCII码差值
}

/*
两个串的连接操作：将第二个串T连接到第一个串S的后面，形成一个新的串存于S中
成功返回1，失败返回0；
*/
int StrCat(String* S, String* T) {
	/*串的连接函数*/
	int i, flag;
	if (S->length + T->length <= MaxLen)
	{
		for (i = S->length; i < S->length + T->length; i++)
			S->ch[i] = T->ch[i - S->length];
		S->ch[i] = '\0';
		S->length = S->length + T->length;
		flag = 1;
	}
	else if (S->length < MaxLen)
	{
		/*连接后的串长度大于MaxLen，但是S的长度小于MaxLen，连接后串T部分字符序列被舍弃*/
		for (i = S->length; i < MaxLen; i++)
			S->ch[i] = T->ch[i - S->length];
		S->length = MaxLen;
		flag = 1;
	}
	else
		flag = 0;		/*此时串S的长度与MaxLen的长度一样，不允许插入T*/
	return (flag);
}

int main() {
	printf("hello word");
	int x;
	String* S = &x;
	printf("输入一个字符串：");
	CreatStr(S);
	printf("该串的值为：");
	puts(S->ch);
	return 0;
}