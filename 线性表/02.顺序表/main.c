#include <stdio.h>
#include <stdlib.h>//malloc、free函数的头文件
#include <stdbool.h>//bool函数的头文件

#define MaxSize 50
/**************************************************/
/*定义一个顺序表*/
typedef struct {
	int data[MaxSize];//顺序表元素
	int length;		  //顺序表当前长度
}SqList;
/*初始化一个顺序表*/
void InitList(SqList* L) {
	for (int i = 0; i < MaxSize; i++) {
		L->data[i] = 0;
	}
	L->length = 0;
}
/*创建一个顺序表,初始化前n个数据*/
bool CreatList(SqList L,int n) {
	if (n<0 || n>MaxSize + 1) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &L.data[i]);
		L.length++;
	}
	return true;
}
/*遍历顺序表*/
void SelectAllList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d", L.data[i]);
	}
}

/**************************************************/
int main() {
	SqList L;
	InitList(&L);
	CreatList(L, 3);
	SelectAllList(L);
	return 0;
}
