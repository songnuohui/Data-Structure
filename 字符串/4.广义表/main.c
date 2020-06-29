
/*---------------------------------------------------------------------
        �����Ĵ洢�ṹ����������(ժ�������ϣ��Դ��Զ�)
---------------------------------------------------------------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>

typedef char ElemType;//Ԫ���������ַ���

//�����Ĵ洢�ṹ
struct GNode
{
    int tag;    //��־��
    union {        //ֵ����ӱ�ı�ͷָ����
        ElemType data;
        struct GNode* sublist;
    };
    struct GNode* next;    //ָ���̽���ָ����
};

/*----------------------��������----------------------*/
int LengthGList(struct GNode* GL);    //������ĳ���
int DepthGList(struct GNode* GL);    //����������
void CreateGList(struct GNode** GL);//���������Ĵ洢�ṹ
void PrintGList(struct GNode* GL);    //��ӡ��������
int SearchGList(struct GNode* GL, ElemType e);//���ҵ��ڸ����ַ��ĵ�Ԫ�ؽ�㣬���ҳɹ��򷵻�1�����򷵻�0

/*----------------------������----------------------*/
void main()
{
    struct GNode* GL;//����ͷ���ӽ��
    printf("����һ��������ԷֺŽ���\n");
    CreateGList(&GL);
    printf("��������");
    PrintGList(GL);
    printf("\n");
    printf("�����ĳ��ȣ�");
    printf("%d\n", LengthGList(GL->sublist));
    printf("��������ȣ�");
    printf("%d\n", DepthGList(GL->sublist));
    printf("����ֵd �Ľ����");
    printf("%d\n", SearchGList(GL, 'd'));
}

/*----------------------����----------------------*/
//������ĳ���
int LengthGList(struct GNode* GL)
{
    if (GL != NULL)
        return(1 + LengthGList(GL->next));
    else
        return(0);
}

//����������
int DepthGList(struct GNode* GL)
{
    int max = 0;//��max����ֵ
    //��������ÿһ����㣬��������ӱ��������
    while (GL != NULL)
    {
        if (GL->tag == 1) {
            int dep = DepthGList(GL->sublist);//�ݹ�������һ���ӱ�����
            if (dep > max)
                max = dep;//��maxʼ��Ϊͬһ����������ӱ�����ȵ����ֵ
        }
        GL = GL->next;//ʹGLָ��ͬһ�����һ�����
    }
    return(max + 1);//���ر�����
}

//���������Ĵ洢�ṹ
void CreateGList(struct GNode** GL)
{
    char ch;
    scanf("%c", &ch);//����һ���ַ����˴�ֻ���ܶ���ո�#�������Ż�Ӣ����ĸ
    if (ch == '#')//������Ϊ�ո����ñ�ͷָ��Ϊ��
        *GL = NULL;
    else if (ch == '(')//������Ϊ������������*GL��ָ����ӱ��㲢�ݹ鹹���ӱ�
    {
        *GL = malloc(sizeof(struct GNode));
        (*GL)->tag = 1;
        CreateGList(&((*GL)->sublist));
    }
    else {    //������Ϊ�ַ�������*GL��ָ��ĵ�Ԫ�ؽ��
        *GL = malloc(sizeof(struct GNode));
        (*GL)->tag = 0;
        (*GL)->data = ch;
    }
    scanf("%c", &ch);//�˴�������ַ���Ϊ���š������Ż�ֺ�
    if (*GL == NULL);    //��*GLΪ�գ���ʲô������
    else if (ch == ',')//�����붺����ݹ鹹���̱�
        CreateGList(&((*GL)->next));
    else if ((ch == ')') || (ch == ';'))//������Ϊ�����Ż�ֺ�����*GL�ĺ��ָ����Ϊ��
        (*GL)->next = NULL;
}

//��ӡ��������
void PrintGList(struct GNode* GL)
{
    //���ڱ���Ĵ������
    if (GL->tag == 1) {    //�����ӱ�����������ţ���Ϊ��ʼ����
        printf("(");
        if (GL->sublist == NULL)//���ӱ�Ϊ���������#���ַ�
            printf("#");
        else//���ӱ�ǿգ���ݹ�����ӱ�
            PrintGList(GL->sublist);
        printf(")");//��һ���ӱ����������Ӧ���һ����������ֹ��
    }
    else//���ڵ�Ԫ�ؽ�㣬������ý���ֵ
        printf("%c", GL->data);
    if (GL->next != NULL)//������ĺ�̱�
    {
        printf(",");//��������ŷָ���
        PrintGList(GL->next);//�ٵݹ������̱�
    }
}

//���ҵ��ڸ����ַ��ĵ�Ԫ�ؽ�㣬���ҳɹ��򷵻�1�����򷵻�0
int SearchGList(struct GNode* GL, ElemType e)
{
    while (GL != NULL) {
        if (GL->tag == 1)//�����ӱ���ݹ�����������ӱ�
        {
            if (SearchGList(GL->sublist, e))
                return(1);
        }
        else//���ڵ�Ԫ�ؽ�㣬���ѯ�Ƿ����ֵe ���������򷵻�1
        {
            if (GL->data == e)
                return(1);
        }
        GL = GL->next;//ʹGLָ��ͬһ�����һ�����
    }
    return(0);//ʣ�����������GLֵΪNULL��������������ֵe �����0
}