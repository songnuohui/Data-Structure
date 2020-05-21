#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
/*创建静态链表有两种*/
#define MaxSize 20
/*第一种*/
struct Node
{
	int data;
	int next;
};
/*第二种*/
typedef struct {
	int data;
	int next;
} SLinkList [MaxSize] ;
/*测试两种创建方法*/
void testSLinkList() {
	struct Node x;
	printf("sizeX=%d\n", sizeof(x));
	struct Node a[MaxSize];
	printf("sizeA=%d\n", sizeof(a));
	SLinkList b;
	printf("sizeB=%d\n", sizeof(b));
}
/**************************************************************/
/*初始化链表*/
bool InitList(SLinkList L) {
	for (int i = 0; i < MaxSize - 1; i++) {
		L[i].next = i + 1;
	}
	L[MaxSize - 2].next = 0;//判断备用链表是否为空
	L[MaxSize - 1].next = 0;//它存放首元素的下标，现在链表为空，设置为0
	return true;
}
/**************************************************************/
/*求链表的长度*/
int ListLength(SLinkList L) {
	int i = 0;
	int j = L[MaxSize-1].next;
	while (j)
	{
		j = L[j].next;
		i++;
	}
	return i;
}

/**************************************************************/
/*在链表第i个位置插入元素*/

//返回备用链表首结点的下标,若备用链表为空，则返回0
/*自己实现动态分配函数*/

//返回备用链表首结点的下标,若备用链表为空，则返回0
int Molloc_L(SLinkList L)
{
	int i = L[0].next;//i指向第一个结点
	if (L[0].next) {
		L[0].next = L[i].next;
	}
	return i;

}
bool InsertList(SLinkList L, int i, int e) {
	if (i<1 || i>ListLength(L) + 1)
		return false;
	int j = Molloc_L(L);
	int k = MaxSize - 1;
	if (j)//备用链表非空
	{
		L[j].data = e;
		for (int s = 1; s <= i - 1; s++)
			k = L[k].next;      //从头结点遍历到第i-1个元素,即找到元素插入的那个位置
		L[j].next = L[k].next;
		L[k].next = j;
		return true;
	}
	else
	{
		printf("备用链表为空！\n");
		return false;
	}
}
/**************************************************************/
/*删除第i个元素*/
/*手动实现free函数*/
void Free_L(SLinkList L, int j) {//将位置为j的空闲结点释放  即：插入到备用链表第一个结点前
	L[j].next = L[0].next;
	L[0].next = j;
}
bool DelList(SLinkList L, int i) {
	if (i<1 || i>ListLength(L) + 1) {
		return false;
	}
	int k = MaxSize - 1;
	int j;
	for (int s = 1; s <= i - 1; s++) {//找到第i-1个位置
		k = L[k].next;
	}
	j = L[k].next;
	L[k].next = L[j].next;
	Free_L(L, j);
	printf("删除成功！");
	return true;
}
/****************************************************************/
/*按位查找*/
bool SelectList(SLinkList L,int i) {
	if (i<1 || i>ListLength(L) + 1)
		return false;
	int k = MaxSize - 1;
	for (int s = 1; s <= i - 1; s++)
		k = L[k].next;				    //找到第i-1个位置
	int j = L[k].next;					//获取第i个位置的游标值
	printf("查找第%d个结点的值是%d",i, L[j].data);
}
/****************************************************************/
/*遍历静态链表*/
void SelectAllList(SLinkList L) {
	int j = 0;
	int i = L[MaxSize - 1].next;
	while (i) {
		++j;
		printf("第%d个结点是：%d\n", j, L[i].data);
		i = L[i].next;
	}
}

/**************************************************************/

int main() {
	SLinkList L;//建立链表
	InitList(L);//初始化链表
	int d = ListLength(L);
	printf("初始化后的长度为：%d\n",d );
	for (int i = 1; i <= 3; i++) {
		InsertList(L, 1, i);
	}
	SelectAllList(L);
	printf("链表长度为：%d\n", ListLength(L));
	InsertList(L, 2, 100);
	printf("遍历结果：");
	SelectAllList(L);
	printf("链表长度为：%d\n", ListLength(L));
	DelList(L, 2);
	printf("遍历结果：");
	SelectAllList(L);
	SelectList(L, 3);
	//testSLinkList();
	return 0;
}
