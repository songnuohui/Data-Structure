#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
定义一个顺序栈
*/
#define  MaxSize 50			//定义栈中元素最大个数
typedef struct {
	int data[MaxSize];		//存放栈中元素
	int top;				//栈顶指针
	int size;
}SqStack;
/*
初始化顺序栈
*/
void InitStack(SqStack *S) {
	S->top = -1;
	S->size = 0;
}
/*
判断栈空
*/
bool StackEmpty(SqStack *S) {
	if (S->top == -1)
	{
		return true;
	}
	return false;
}
/*
判断栈满
*/
bool FullStack(SqStack *S) {
	if (S->top == MaxSize - 1)
		return true;
	return false;
}
/*
进栈
*/
bool Push(SqStack *S, int x) {
	if (S->top == MaxSize-1) {
		return false;
	}
	S->top = S->top + 1;		//指针先加1
	S->data[S->top] = x;		//入栈赋值
	S->size++;
	return true;
}
/*
出栈
*/
bool Pop(SqStack *S, int *x) {
	if (S->top == -1) {
		return false;
	}
	*x = S->data[S->top];
	S->top = S->top - 1;
	S->size--;
	return true;
}
/*
读取栈顶元素
*/
bool GetTop(SqStack* S, int* x) {
	if (S->top == -1)
		return false;
	*x = S->data[S->top];
	return true;
}

int main() {
	SqStack S;
	InitStack(&S);

/**************入栈*******************/
	printf("输入入栈元素个数：");
	int n; int x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		Push(&S, x);
	}

/**************出栈*******************/
	printf("\n输入出栈元素个数：");
	scanf("%d", &n);
	if (n > S.size) {
		printf("超出长度");
		return 0;
	}
	printf("出栈元素有:\n");
	for (int i = 0; i < n; i++) {
		Pop(&S, &x);
		printf("%d\n", x);
	}
/**************读取栈顶元素*******************/
	GetTop(&S, &x);
	printf("出栈完成后的栈顶元素为：%d", x);
	return 0;
}
