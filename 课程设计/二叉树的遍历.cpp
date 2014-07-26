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

 //创建二叉树 
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

 
//输出二叉树
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


void PreOrder(BTNode *b) 	/*先序遍历的递归算法*/
  {
  	if (b!=NULL)  
    {   printf("%c ",b->data); /*访问根结点*/
 		PreOrder(b->lchild);
 		PreOrder(b->rchild);
        }
  }
void InOrder(BTNode *b) 	/*中序遍历的递归算法*/
 {
 	if (b!=NULL)  
 	{ 	InOrder(b->lchild);
		printf("%c ",b->data); /*访问根结点*/
		InOrder(b->rchild);
	}
  }

void PostOrder(BTNode *b) /*后序遍历递归算法*/
 {
 	if (b!=NULL)  
 	{	PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ",b->data); /*访问根结点*/
	}
 }

void LevelOrder(BTNode *b)
{
	BTNode *Qu[MaxSize];				//定义循环队列
	int front,rear;						//定义队首和队尾指针
	front=rear=0;						//置队列为空队列
    if (b!=NULL) 
		printf("%c ",b->data);
    rear++;								//节点指针进入队列
	Qu[rear]=b;
    while (rear!=front)					//队列不为空
    {
		front=(front+1)%MaxSize;
		b=Qu[front];					//队头出队列
		if (b->lchild!=NULL)			//输出左孩子,并入队列
		{
			printf("%c ",b->lchild->data);
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->lchild;
		}
		if (b->rchild!=NULL)			//输出右孩子,并入队列
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
	printf("用括号表示法输入\n");
	scanf("%s",&str);
	CreateBTNode(b,str);
//	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))");
	printf("二叉树的基本元算如下:\n");
	printf("输出二叉树b：");
	DispBTNode(b);
	printf("\n"); 
	printf("二叉树b的层次遍历序列:");LevelOrder(b);
	printf("二叉树b的先序遍历序列:");PreOrder(b);
	printf("\n");
	printf("二叉树b的中序遍历序列:");InOrder(b);
	printf("\n");
	printf("二叉树b的后序遍历序列:");PostOrder(b);
	printf("\n");
	system("pause");
} 
