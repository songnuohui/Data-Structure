#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
#define MaxSize 100					//队列存储长度
/*二叉树的进本操作：
				初始化，构建二叉树，销毁二叉树，利用广义表显示二叉树
				先序遍历，中序遍历，后序遍历，层次遍历
				计算二叉树的深度，叶子节点数，结点总数
*/
//链式结构
typedef struct node {
	char data;		//数据域
	struct node* lchild, * rchild;	//左右孩子指针
}BiTree;

/*初始化二叉树*/
BiTree* InitTree() {
	BiTree* T;
	T = (BiTree*)malloc(sizeof(BiTree));
	T = NULL;
	return T;
}
/*构建二叉树*/
BiTree* CreateTree() {
	BiTree* T;
	char ch;
	scanf("%c", &ch);
	getchar();
	if (ch == '0')
		T = NULL;
	else {
		T = (BiTree*)malloc(sizeof(BiTree));
		T->data = ch;
		printf("请输入%c的左孩子结点：",T->data);
		T->lchild = CreateTree();
		printf("请输入%c的右孩子结点：", T->data);
		T->rchild = CreateTree();
	}
	return T;
}
/*销毁二叉树*/
void DestoryTree(BiTree* T) {
	if (T == NULL)
		return;
	DestoryTree(T->lchild);
	DestoryTree(T->rchild);
	free(T);
}
/*利用广义表表示法显示二叉树*/
void ShowTree(BiTree* T) {
	if (T != NULL) {				//当二叉树非空时
		printf("%c", T->data);
		if (T->lchild != NULL)		//当左子树非空时
		{
			printf("(");
			ShowTree(T->lchild);	//递归调用该函数输出其左子树各个结点
			if (T->rchild != NULL) {
				printf(",");
				ShowTree(T->rchild);//递归调用该函数输出其右子树各个结点
			}
			printf(")");
		}
		else if (T->rchild != NULL)	//当右子树非空时
		{
			printf("(");
			ShowTree(T->lchild);
			if (T->rchild != NULL) {
				printf(",");
				ShowTree(T->rchild);
			}
			printf(")");
		}
	}
}
/*先序遍历*/
void PreOrder(BiTree* T) {
	if (T != NULL)
	{
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
/*中序遍历*/
void InOrder(BiTree* T) {
	if (T != NULL)
	{
		PreOrder(T->lchild);
		printf("%c", T->data);
		PreOrder(T->rchild);
	}
}
/*后序遍历*/
void PostOrder(BiTree* T) {
	if (T != NULL)
	{
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		printf("%c", T->data);
	}
}
/*层次遍历*/
void LevelOrder(BiTree* T) {
	int f, r;						//定义头尾指针
	BiTree* p, * q[MaxSize];		//定义一个循环队列
	p = T;
	if (p != NULL) {				//如果二叉树非空，则根节点入队
		f = 1; q[f] = p; r = 2;
	}
	while (f!=r)					//如果队列不为空
	{
		p = q[f];
		printf("%c", p->data);		//访问队首结点
		if (p->lchild != NULL) {
			q[r] = p->lchild;		//如果根节点左孩子非空则入队
			r = (r + 1) % MaxSize;
		}
		if (p->rchild != NULL) {
			q[r] = p->rchild;		//如果根节点有孩子非空则入队
			r = (r + 1) % MaxSize;
		}
		f = (f + 1) % MaxSize;
	}
}
/*二叉树的深度*/
int TreeDepth(BiTree* T) {
	int left = 0;
	int right = 0;
	if (T == NULL)
		return 0;
	else
	{
		left = TreeDepth(T->lchild);
		right = TreeDepth(T->rchild);
		return left > right ? left+1 : right+1;
	}
}
/*叶子结点总数*/
int count=0;
int LeafNode(BiTree* T) {
	if (T == NULL)
		return 0;
	if (T) {
		if (T->lchild == NULL && T->rchild == NULL)
			count++;
		LeafNode(T->lchild);
		LeafNode(T->rchild);
	}
	return count;
}
/*总结点数*/
int sum = 0;
int NodeCount(BiTree* T) {
	if (T) {
		sum++;
		NodeCount(T->lchild);
		NodeCount(T->rchild);
	}
	return sum;
}

int main() {
	BiTree *T;
	T=InitTree();
	printf("说明：输入'0'表示后继结点为空！");
	printf("\n输入根节点：");
	T = CreateTree();
	ShowTree(T);
	/*先序遍历*/
	printf("\n先序遍历的结果: ");
	PreOrder(T);
	/*中序遍历*/
	printf("\n中序遍历的结果: ");
	InOrder(T);
	/*后序遍历*/
	printf("\n后序遍历的结果: ");
	PostOrder(T);
	/*层次遍历*/
	printf("\n层次遍历的结果: ");
	LevelOrder(T);
	/*二叉树深度*/
	printf("\n二叉树的深度为: %d",TreeDepth(T));
	/*叶子结点总数*/
	printf("\n叶子结点总数为: %d", LeafNode(T));
	/*结点总数*/
	printf("\n二叉树结点总数为: %d", NodeCount(T));
	return 0;
}
