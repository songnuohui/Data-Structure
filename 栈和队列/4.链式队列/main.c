#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*
定义链式队列
*/
typedef struct qNode{					//定义链式队列结点
	int data;						//定义结点的数据域
	struct qNode* next;			//定义结点的指针域
}LinkNode;
typedef struct {					//链式队列
	LinkNode* font, * rear;			//定义队列的头指针和尾指针
}LinkQueue;							//链式队列的头指针类型

/*
初始化队列
*/
void InitQueue(LinkQueue* Q) {
	Q->font = Q->rear = (LinkNode*)malloc(sizeof(LinkNode));    //建立头结点，队列头尾指针指向新结点
	Q->font->next = NULL;
}

/*
判断队列是否为空
*/
bool EmptyQueue(LinkQueue* Q) {
	if (Q->font == Q->rear)
		return true;
	return false;
}


/*
入队
*/
bool InQueue(LinkQueue* Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));//生成新的结点
	s->data = x;				//将X的值存入新结点的指针域
	s->next = NULL;
	Q->rear->next = s;			//将新结点插入到链队列头结点后
	Q->rear = s;				//队尾指针指向队尾元素
	return true;
}

/*
出队
*/
bool DeQueue(LinkQueue* Q, int* x) {
	if (EmptyQueue(Q))
		return false;
	LinkNode* s=Q->font->next;
	*x = s->data;				//p指向队头元素
	Q->font->next = s->next;	//队头指针的指针域存放新队头元素的地址
	if (s->next == NULL)		//队列中只含有一个元素的时候出队
		Q->rear = Q->font;		//出队后头指针指向尾指针，此时队列为空
	free(s);
	return true;
}

/*
得到队头元素
*/
void GetHead(LinkQueue* Q, int* x) {
	if (EmptyQueue(Q)) {
		printf("队空！");
	}
	*x = Q->font->next->data;
}
/*
遍历队列元素
*/
void ShowQueue(LinkQueue* Q) {
	if (EmptyQueue(Q))
		printf("队空，无元素！");
	LinkNode* s = Q->font;
	while (s!=Q->rear)					//当队头指针不等于队尾指针
	{
		printf("%2d", s->next->data);
		s = s->next;
	}
}

int main() {
	LinkQueue* Q;
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	InitQueue(Q);
	int n, x;
	/***************入队*****************/
	printf("输入入队元素个数：");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		InQueue(Q, x);
	}
	/***************遍历队列元素*****************/
	printf("\n遍历队列元素为：");
	ShowQueue(Q);
	/***************显示队头元素*****************/
	GetHead(Q, &x);
	printf("\n队头元素为：%2d", x);
	/***************出队*****************/
	printf("\n请输入出队元素个数：");
	scanf("%d", &n);
	printf("出队元素为：");
	for (int i = 0; i < n; i++) {
		DeQueue(Q, &x);
		printf("%2d", x);
	}
	return 0;
}