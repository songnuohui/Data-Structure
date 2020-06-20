#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>

/*
���Ĳ��룬ɾ�������ң��Ƚϣ�ȡ�Ӵ������ӵȲ���
*/

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
	gets(S->ch);						//��ȡ������ַ���
	S->length = StrLength(S);			//�����󴮳��Ⱥ���
}

/*
���ִ����ӵ�i��λ�ÿ�ʼ���ҳ�����Ϊlen���ִ�����������뵽��Sub�У��ɹ�����1��ʧ�ܷ���0
*/
int SubString(String* S, String* Sub, int i, int len) {
	int j;
	if (i<1 || i>S->length || len<1 || len>(S->length - i + 1)) {
		Sub->length = 0;
		printf("��������");
		return 0;
	}
	else
	{
		for (j = 0; j < len; j++)
			Sub->ch[j] = S->ch[i + j - 1];	//Sub��һ���ַ�����S�еĵ�iλ�õ��ַ�������++
		Sub->ch[j] = '\0';
		Sub->length = len;
		return 1;
	}
}

/*
ɾ���ִ�����λ��i��ʼ��ɾ������Ϊl���ִ�
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
		S->ch[S->length] = '\0';			//�´�β�������ַ���������־
		return true;
	}
}

/*
�����ִ���������S�еĵ�i��λ�ÿ�ʼ�����ִ�S1��
*/
bool StrInsert(String* S, int i, String *S1) {
	int k;
	if (i<0||i > S->length + 1) {
		printf("����λ�ô���");
		return false;
	}
	else if (S->length + S1->length > MaxLen) {
		printf("���ȳ����洢�ռ䳤�ȣ�");
		return false;
	}
	else {
		for (k = S->length - 1; k >= i; k--)			//����˳���Ĳ������������iλ��ʼ���ַ�������ƶ�S1�ĳ���
			S->ch[S1->length + k] = S->ch[k];
		for (k = 0; k < S1->length; k++)				//���ִ�S1���뵽S�ĵ�iλ��
			S->ch[i + k - 1] = S1->ch[k];
		S->length = S->length + S1->length;				//�޸Ĵ�S�ĳ���
		S->ch[S->length] = '\0';						//�´�β�������ַ���������־
		return true;
	}
}

/*
���Ķ�λ����:����S�д����봮T��ͬ���ִ����򷵻ش�T��S�е�һ�γ��ֵ�λ�ã����򷵻�-1
����ƥ���㷨
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
	if (j >= T->length)		//��S�к��д�Tʱ
		k = i - T->length + 1;
	else
		k = -1;
	return k;
}

/*
�ж��������Ƿ���ȣ������ȣ�����0��������ȣ�������������Ӧ��һ������ͬλ�õ�ASCII��Ĳ�ֵ
*/
int StrCompare(String* S1, String* S2) {
	/*�������ж��Ƿ���Ⱥ���*/
	int i = 0, flag = 0;
	while (S1->ch[i]!='\0'&&S2->ch[i]!='\0')
	{
		if (S1->ch[i]!=S2->ch[i])
		{
			flag = 1;	
			break;					//�Ƚϵĵ�ǰֵ�����������ѭ��
		}
		else
		{
			i++;
		}
	}
	if (flag == 0 && S1->length == S2->length)
		return 0;
	else
		return S1->ch[i] - S2->ch[i];			//���ض�Ӧ��һ������ͬλ���ַ�ASCII���ֵ
}

/*
�����������Ӳ��������ڶ�����T���ӵ���һ����S�ĺ��棬�γ�һ���µĴ�����S��
�ɹ�����1��ʧ�ܷ���0��
*/
int StrCat(String* S, String* T) {
	/*�������Ӻ���*/
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
		/*���Ӻ�Ĵ����ȴ���MaxLen������S�ĳ���С��MaxLen�����Ӻ�T�����ַ����б�����*/
		for (i = S->length; i < MaxLen; i++)
			S->ch[i] = T->ch[i - S->length];
		S->length = MaxLen;
		flag = 1;
	}
	else
		flag = 0;		/*��ʱ��S�ĳ�����MaxLen�ĳ���һ�������������T*/
	return (flag);
}

int main() {
	printf("hello word");
	int x;
	String* S = &x;
	printf("����һ���ַ�����");
	CreatStr(S);
	printf("�ô���ֵΪ��");
	puts(S->ch);
	return 0;
}