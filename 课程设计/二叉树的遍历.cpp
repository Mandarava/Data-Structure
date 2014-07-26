#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 
#define MaxSize 100
//#define NULL 0
 typedef char ElemType;
 typedef struct node
 {
 	ElemType data;
 	struct node * lchild;
 	struct node * rchild;
 }BTNode;

 //���������� 
 void CreateBTNode(BTNode * &b,char * str)
 {
 	BTNode * St[MaxSize], *p;
 	int top=-1,k,j=0;
 	char ch;
 	b= NULL;
 	ch=str[j];
 	while(ch!='\0')
 	{	switch(ch)
 		{
		case '(':top++;St[top]=p;k=1;break;
		case ')':top--;break;
		case ',':k=2;break;
		default :p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;
				p->lchild=p->rchild=NULL;
				if(b==NULL)
					b=p;
				else
				{	switch(k)
					{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
					}
				}
 		}
 		j++;
 		ch=str[j];
 	}
 }

 
//���������
void DispBTNode(BTNode * b)
{	if(b!=NULL)
	{	printf("%c",b->data);
		if(b->lchild!=NULL || b->rchild!=NULL)
		{
			printf("(");
			DispBTNode(b->lchild);
			if(b->rchild!=NULL) printf(",");
			DispBTNode(b->rchild);
			printf(")");
		}
	}
}


void PreOrder(BTNode *b) 	/*��������ĵݹ��㷨*/
  {
  	if (b!=NULL)  
    {   printf("%c ",b->data); /*���ʸ����*/
 		PreOrder(b->lchild);
 		PreOrder(b->rchild);
        }
  }
void InOrder(BTNode *b) 	/*��������ĵݹ��㷨*/
 {
 	if (b!=NULL)  
 	{ 	InOrder(b->lchild);
		printf("%c ",b->data); /*���ʸ����*/
		InOrder(b->rchild);
	}
  }

void PostOrder(BTNode *b) /*��������ݹ��㷨*/
 {
 	if (b!=NULL)  
 	{	PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ",b->data); /*���ʸ����*/
	}
 }

void LevelOrder(BTNode *b)
{
	BTNode *Qu[MaxSize];				//����ѭ������
	int front,rear;						//������׺Ͷ�βָ��
	front=rear=0;						//�ö���Ϊ�ն���
    if (b!=NULL) 
		printf("%c ",b->data);
    rear++;								//�ڵ�ָ��������
	Qu[rear]=b;
    while (rear!=front)					//���в�Ϊ��
    {
		front=(front+1)%MaxSize;
		b=Qu[front];					//��ͷ������
		if (b->lchild!=NULL)			//�������,�������
		{
			printf("%c ",b->lchild->data);
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->lchild;
		}
		if (b->rchild!=NULL)			//����Һ���,�������
		{
			printf("%c ",b->rchild->data);
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->rchild;
		}
	} 
	printf("\n");
}


void list2()
{	system("cls");
	char str[100];
	BTNode *b;
	printf("�����ű�ʾ������\n");
	scanf("%s",&str);
	CreateBTNode(b,str);
//	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))");
	printf("�������Ļ���Ԫ������:\n");
	printf("���������b��");
	DispBTNode(b);
	printf("\n"); 
	printf("������b�Ĳ�α�������:");LevelOrder(b);
	printf("������b�������������:");PreOrder(b);
	printf("\n");
	printf("������b�������������:");InOrder(b);
	printf("\n");
	printf("������b�ĺ����������:");PostOrder(b);
	printf("\n");
	system("pause");
} 
