#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct ThreadNode {
    char data;
    struct ThreadNode* lchild, * rchild;
    int ltag, rtag;                    // tag = 0 表示有孩子
}ThreadNode, * ThreadTree;
//建树
ThreadTree CreateThreadTree() {
    char ch;
    cin >> ch;
    ThreadTree T = NULL;
    if (ch == '#') return NULL;
    else {
        T = (ThreadTree)malloc(sizeof(ThreadNode));
        T->data = ch;
        T->lchild = T->rchild = NULL;
        T->ltag = T->rtag = 0;
        T->lchild = CreateThreadTree();
        T->rchild = CreateThreadTree();
    }
    return T;
}
//线索化
void InThread(ThreadTree& p, ThreadTree& pre) {
    if (p != NULL) {
        InThread(p->lchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void CreateInThreadTree(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}
//查找中序序列下，p的前驱节点
ThreadNode* FirstNode(ThreadNode* p) {
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}
//查找中序序列下，p的后继节点
ThreadNode* NextNode(ThreadNode* p) {
    if (p->rtag == 0)
        return FirstNode(p->rchild);
    else return p = p->rchild;
}
//中序遍历
void InOrder(ThreadNode* T) {
    for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
        printf("%c->", p->data);
}
//先序的后继结点
ThreadNode* PreNext(ThreadNode* T) {
    ThreadNode* p;
    if (T->ltag == 0)
        p = T->lchild;
    else {
        p = T;
        while (T->rtag == 1)
            T = T->rchild;
        p = T->rchild;
    }
    return p;
}
//后序的前驱结点
ThreadTree PostPre(ThreadTree p) {
    ThreadTree q;
    if (p->ltag == 0)
        q = p->lchild;
    else {
        q = p;
        while (p->rtag == 1)
            p = p->rchild;
        q = p->rchild;
    }
    return q;
}
int main()
{
    printf("输入各节点：\n");
    ThreadTree T = CreateThreadTree();
    CreateInThreadTree(T);
    printf("中序线索二叉树的中序遍历：\n");
    InOrder(T);
    printf("\n");

    char ch;
    cin >> ch;

    ThreadTree p = (ThreadTree)malloc(sizeof(ThreadNode));
    p->data = ch;

    PostPre(p);
    printf("后继结点为:%c", p->data);
}