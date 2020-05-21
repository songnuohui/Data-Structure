#include <stdio.h>
#include <stdlib.h>//malloc��free������ͷ�ļ�
#include <stdbool.h>//bool������ͷ�ļ�

#define MaxSize 50
/**************************************************/
/*����һ��˳���*/
typedef struct {
	int data[MaxSize];//˳���Ԫ��
	int length;		  //˳���ǰ����
}SqList;
/*��ʼ��һ��˳���*/
void InitList(SqList* L) {
	for (int i = 0; i < MaxSize; i++) {
		L->data[i] = 0;
	}
	L->length = 0;
}
/*����һ��˳���,��ʼ��ǰn������*/
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
/*����˳���*/
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
