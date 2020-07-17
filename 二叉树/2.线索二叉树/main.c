#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>

/*线索二叉树存储结构描述*/
typedef struct ThreadNode {
	char data;
	struct ThreadNode* lchild, * rchild;		//左右孩子指针
	int ltag, rtag;							//左右线索标志
}ThreadTree;

/*先序构建二叉树线索二叉树*/
ThreadTree* CreateTree() {
	ThreadTree* T;
	char ch;
	scanf("%c", &ch);
	getchar();
	if (ch == '0')
		T = NULL;
	else {
		T = (ThreadTree*)malloc(sizeof(struct ThreadNode));
		T->data = ch;
		printf("请输入%c的左孩子结点：", T->data);
		T->lchild = CreateTree();
		if (T->lchild) {
			T->ltag = 0;
		}
		else
		{
			T->ltag = 1;
		}
		printf("请输入%c的右孩子结点：", T->data);
		T->rchild = CreateTree();
		if (T->rchild) {
			T->rtag = 0;
		}
		else
		{
			T->rtag = 1;
		}
	}
	return T;
}
/*中序遍历*/
void InOreder(ThreadTree* T) {
	if (T != NULL) {
		printf("%c", T->data);
		InOreder(T->lchild);
		InOreder(T->rchild);
	}
}
/*中序遍历线索化二叉树*/
ThreadTree* pre = NULL;
void InThread(ThreadTree* T) {
	if (T) {
		InThread(T->lchild);
		if (!T->lchild) {//左子树为空，建立前驱线索
			T->ltag = 1;
			T->lchild = pre;
		}
		if (pre && !pre->rchild) {
			pre->rtag = 1;
			pre->rchild = T;	//建立前驱结点的后继线索
		}
		pre = T;
		InThread(T->rchild);
	}
}
/*中序遍历线索二叉树*/
void InOrderThread(ThreadTree* T) {
	while (T) {
		//找左孩子，直到找到中序遍历中排第一的
		while (T->ltag == 0) {
			T = T->lchild;
		}
		printf("%c->", T->data);	//打印结点数据
		//当结点右标志位为1时，直接找到其后继结点
		while (T->rtag == 1 && T->rchild != NULL) {
			T = T->rchild;
			printf("%c->", T->data);
		}
		//否则，按照中序遍历的规律，找其右子树中最左下的结点，也就是继续循环遍历
		T = T->rchild;
	}
}
/*********************************************************/
/*查找中序序列下，p的前驱节点*/
ThreadTree* FirstNode(ThreadTree* p) {
	while (p->ltag == 0) {
		p = p->lchild;				//找最左下结点，不一定是叶子结点
	}
	return p;
}
/*查找中序序列下，T的后继节点*/
ThreadTree* NextNode(ThreadTree* p) {
	if (p->rtag == 0) {				//如果有右子树
		p = FirstNode(p->rchild);	//寻找到右子树最左下结点即为T的后继结点
	}
	else							//如果没有右子树，其右孩子就是T的后继结点
	{
		p = p->rchild;
	}
	return p;
}
//中序遍历
void InOrderTree(ThreadTree* T) {
	for (ThreadTree* p = FirstNode(T); p != NULL; p = NextNode(p))
		printf("%c->", p->data);
}




int main() {
	ThreadTree* T;
	printf("说明：输入'0'表示后继结点为空！");
	printf("\n输入根节点：");
	T = CreateTree();
	printf("\n先序遍历的结果: ");
	InOreder(T);
	/*中序线索化二叉树*/
	InThread(T);
	printf("\n输出中序线索二叉树中序遍历的结果: ");
	InOrderThread(T);
	printf("\n输出中序线索二叉树的中序遍历：");
	InOrderTree(T);
	return 0;
}