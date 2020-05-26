#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
顺序结构循环队列
*/
#define MaxSize 50
typedef struct {
	int data[MaxSize];		//存放队列元素
	int font, rear;			//队头指针和队尾指针
}SqQueue;
/*
初始化
*/
void InitQueue(SqQueue* Q) {
	Q->font = Q->rear = 0;
}
/*
是否为空
*/
bool EmptyQueue(SqQueue* Q) {
	if (Q->font == Q->rear)
		return true;
	return false;
}
/*
是否满了
*/
bool FullQueue(SqQueue* Q) {
	if ((Q->rear + 1) % MaxSize == Q->font)
		return true;
	return false;
}
/*
入队
*/
bool InQueue(SqQueue* Q, int x) {
	if (FullQueue(Q)) {
		printf("队满！");
		return false;
	}
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize;		//队尾指针加一取模
	return true;
}
/*
出队
*/
bool DeQueue(SqQueue* Q, int* x) {
	if (EmptyQueue(Q)) {
		printf("队空！");
		return false;
	}
	*x = Q->data[Q->font];
	Q->font = (Q->font + 1) % MaxSize;
	return true;
}
/*
得到队头元素
*/
void GetHead(SqQueue* Q, int* x) {
	if (EmptyQueue(Q)) {
		printf("队空！");
	}
	*x = Q->data[Q->font];
}
/*
显示队元素
*/
void ShowQueue(SqQueue* Q) {
	int p = Q->font;
	if (p == Q->rear) {
		printf("队空，无元素！");
	}
	printf("从队头到队尾的各个元素为：");
	while (p != Q->rear) {
		printf("%d", Q->data[p]);
		p++;
	}
}
int main() {
	SqQueue* Q;
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	int n, x;
	/***************入队*****************/
	printf("输入入队元素个数：");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		InQueue(Q, x);
	}
	/***************显示队头元素*****************/
	GetHead(Q, &x);
	printf("队头元素为：%2d", x);
	/***************出队*****************/
	printf("\n请输入出栈元素个数：");
	scanf("%d", &n);
	printf("出栈元素为：");
	for (int i = 0; i < n; i++) {
		DeQueue(Q, &x);
		printf("%2d", x);
	}
	return 0;
}