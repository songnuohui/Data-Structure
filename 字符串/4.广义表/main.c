
/*---------------------------------------------------------------------
        广义表的存储结构及基本运算(摘抄自网上，对此略懂)
---------------------------------------------------------------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>

typedef char ElemType;//元素类型是字符型

//广义表的存储结构
struct GNode
{
    int tag;    //标志域
    union {        //值域或子表的表头指针域
        ElemType data;
        struct GNode* sublist;
    };
    struct GNode* next;    //指向后继结点的指针域
};

/*----------------------函数声明----------------------*/
int LengthGList(struct GNode* GL);    //求广义表的长度
int DepthGList(struct GNode* GL);    //求广义表的深度
void CreateGList(struct GNode** GL);//建立广义表的存储结构
void PrintGList(struct GNode* GL);    //打印输出广义表
int SearchGList(struct GNode* GL, ElemType e);//查找等于给定字符的单元素结点，查找成功则返回1，否则返回0

/*----------------------主函数----------------------*/
void main()
{
    struct GNode* GL;//带表头附加结点
    printf("输入一个广义表，以分号结束\n");
    CreateGList(&GL);
    printf("输出广义表：");
    PrintGList(GL);
    printf("\n");
    printf("广义表的长度：");
    printf("%d\n", LengthGList(GL->sublist));
    printf("广义表的深度：");
    printf("%d\n", DepthGList(GL->sublist));
    printf("搜索值d 的结果：");
    printf("%d\n", SearchGList(GL, 'd'));
}

/*----------------------函数----------------------*/
//求广义表的长度
int LengthGList(struct GNode* GL)
{
    if (GL != NULL)
        return(1 + LengthGList(GL->next));
    else
        return(0);
}

//求广义表的深度
int DepthGList(struct GNode* GL)
{
    int max = 0;//给max赋初值
    //遍历表中每一个结点，求出所有子表的最大深度
    while (GL != NULL)
    {
        if (GL->tag == 1) {
            int dep = DepthGList(GL->sublist);//递归调用求出一个子表的深度
            if (dep > max)
                max = dep;//让max始终为同一层所求过的子表中深度的最大值
        }
        GL = GL->next;//使GL指向同一层的下一个结点
    }
    return(max + 1);//返回表的深度
}

//建立广义表的存储结构
void CreateGList(struct GNode** GL)
{
    char ch;
    scanf("%c", &ch);//读入一个字符，此处只可能读入空格#、左括号或英文字母
    if (ch == '#')//若输入为空格，则置表头指针为空
        *GL = NULL;
    else if (ch == '(')//若输入为左括号则建立由*GL所指向的子表结点并递归构造子表
    {
        *GL = malloc(sizeof(struct GNode));
        (*GL)->tag = 1;
        CreateGList(&((*GL)->sublist));
    }
    else {    //若输入为字符则建立由*GL所指向的单元素结点
        *GL = malloc(sizeof(struct GNode));
        (*GL)->tag = 0;
        (*GL)->data = ch;
    }
    scanf("%c", &ch);//此处读入的字符必为逗号、右括号或分号
    if (*GL == NULL);    //若*GL为空，则什么都不做
    else if (ch == ',')//若输入逗号则递归构造后继表
        CreateGList(&((*GL)->next));
    else if ((ch == ')') || (ch == ';'))//若输入为右括号或分号则置*GL的后继指针域为空
        (*GL)->next = NULL;
}

//打印输出广义表
void PrintGList(struct GNode* GL)
{
    //对于表结点的处理情况
    if (GL->tag == 1) {    //存在子表，则输出左括号，作为开始符号
        printf("(");
        if (GL->sublist == NULL)//若子表为空则输出‘#’字符
            printf("#");
        else//若子表非空，则递归输出子表
            PrintGList(GL->sublist);
        printf(")");//当一个子表输出结束后，应输出一个右括号终止符
    }
    else//对于单元素结点，则输出该结点的值
        printf("%c", GL->data);
    if (GL->next != NULL)//输出结点的后继表
    {
        printf(",");//先输出逗号分隔符
        PrintGList(GL->next);//再递归输出后继表
    }
}

//查找等于给定字符的单元素结点，查找成功则返回1，否则返回0
int SearchGList(struct GNode* GL, ElemType e)
{
    while (GL != NULL) {
        if (GL->tag == 1)//存在子表，则递归搜索本层该子表
        {
            if (SearchGList(GL->sublist, e))
                return(1);
        }
        else//存在单元素结点，则查询是否存在值e ，若存在则返回1
        {
            if (GL->data == e)
                return(1);
        }
        GL = GL->next;//使GL指向同一层的下一个结点
    }
    return(0);//剩下来的情况，GL值为NULL，代表搜索不到值e ，输出0
}