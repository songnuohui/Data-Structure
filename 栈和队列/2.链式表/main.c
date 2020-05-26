#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
定义链式栈，和定义单链表一样
*/
typedef struct Stacknode {
	int data;
	int length;
	struct Stacknode* next;
}LinkStack;
/*
初始化链式栈
*/
LinkStack* InitStack() {
	LinkStack* S;
	S = NULL;
	return S;
}
/*
判断栈空
*/
bool StackEmpty(LinkStack* S) {
	if (S == NULL)
		return true;
	return false;
}
/*
进栈
*/
LinkStack* PushStack(LinkStack* S, int x) {
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = S;
	S = p;
	S->length++;
	return S;
}
/*
出栈
*/
LinkStack* PopStack(LinkStack* S, int* x) {
	LinkStack* p;
	if (StackEmpty(S)) {
		return NULL;
	}
	*x = S->data;
	p = S;
	S = S->next;
	S->length--;
	free(p);
	return S;
}
/*
读取栈顶元素
*/
bool GetStack(LinkStack* S, int* x) {
	if (S == NULL)
		return false;
	*x = S->data;
	return true;
}
int main() {
	LinkStack* S;
	S = InitStack();
	int n, x;
	printf("输入入栈元素个数：");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		S=PushStack(S, x);
	}
	/**************读取栈顶元素*******************/
	GetStack(S, &x);
	printf("栈顶元素：%d", x);

	printf("请输入出栈元素个数：");
	scanf("%d", &n);
	printf("出栈元素为：");
	for (int i = 0; i < n; i++) {
		S=PopStack(S, &x);
		if(S!=NULL)
			printf("%2d", x);
	}
	return 0;
}