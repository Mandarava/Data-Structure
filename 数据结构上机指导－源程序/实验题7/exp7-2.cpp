//文件名:exp7-2.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;				//数据元素
	struct node *lchild;		//指向左孩子
	struct node *rchild;		//指向右孩子
} BTNode;
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


void PreOrder(BTNode *b)  		//先序遍历的递归算法
{
	if (b!=NULL)  
	{	
		printf("%c ",b->data);	//访问根节点
		PreOrder(b->lchild);	//递归访问左子树
		PreOrder(b->rchild);	//递归访问右子树
	}
}
void PreOrder1(BTNode *b)
{
	BTNode *St[MaxSize],*p;
    int top=-1;
    if (b!=NULL) 
    {
        top++;						//根节点入栈
        St[top]=b;
        while (top>-1)				//栈不为空时循环
        {
            p=St[top];				//退栈并访问该节点
            top--;
            printf("%c ",p->data);
            if (p->rchild!=NULL)	//右孩子入栈
			{
               top++;
               St[top]=p->rchild;
			}
            if (p->lchild!=NULL)	//左孩子入栈
			{
               top++;
               St[top]=p->lchild;
			}
		}
		printf("\n");
	}
}
void InOrder(BTNode *b)   		//中序遍历的递归算法
{
	if (b!=NULL)  
	{	
		InOrder(b->lchild);		//递归访问左子树
		printf("%c ",b->data);	//访问根节点
		InOrder(b->rchild);		//递归访问右子树
	}
}
void InOrder1(BTNode *b)
{
	BTNode *St[MaxSize],*p;
	int top=-1;
	if (b!=NULL)
	{
		p=b;
		while (top>-1 || p!=NULL)
		{
			while (p!=NULL)
			{
				top++;
				St[top]=p;
				p=p->lchild;
			}
			if (top>-1)
			{
				p=St[top];
				top--;
				printf("%c ",p->data);
				p=p->rchild;
			}
		}
		printf("\n");
	}
}
void PostOrder(BTNode *b) 		//后序遍历的递归算法
{
	if (b!=NULL)  
	{	
		PostOrder(b->lchild);	//递归访问左子树
		PostOrder(b->rchild);	//递归访问右子树
		printf("%c ",b->data);	//访问根节点
	}
}
void PostOrder1(BTNode *b)
{
	BTNode *St[MaxSize];
	BTNode *p;
	int flag,top=-1;						//栈指针置初值
	if (b!=NULL)
	{
		do
		{
			while (b!=NULL)					//将t的所有左节点入栈
			{
				top++;
				St[top]=b;
				b=b->lchild;
			}
			p=NULL;							//p指向当前节点的前一个已访问的节点
			flag=1;	
			while (top!=-1 && flag)
			{
				b=St[top];					//取出当前的栈顶元素
				if (b->rchild==p)			//右子树不存在或已被访问,访问之
				{
					printf("%c ",b->data);	//访问*b节点
					top--;
					p=b;					//p指向则被访问的节点
				}
				else
				{
					b=b->rchild;			//t指向右子树
					flag=0;	
				}
			}
		} while (top!=-1);
		printf("\n");
	} 
}
void TravLevel(BTNode *b)
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
void main()
{
	BTNode *b;
	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"); 
	printf("二叉树b:");DispBTNode(b);printf("\n");
	printf("层次遍历序列:");
	TravLevel(b);
	printf("先序遍历序列:\n");
	printf("    递归算法:");PreOrder(b);printf("\n");
	printf("  非递归算法:");PreOrder1(b);
	printf("中序遍历序列:\n");
	printf("    递归算法:");InOrder(b);printf("\n");
	printf("  非递归算法:");InOrder1(b);
	printf("后序遍历序列:\n");
	printf("    递归算法:");PostOrder(b);printf("\n");
	printf("  非递归算法:");PostOrder1(b);

}
 
