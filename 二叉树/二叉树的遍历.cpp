#include<stdio.h>
#include<malloc.h>
//#include<btree.h>
 #define MaxSize 100
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
 //查找结点 
 BTNode * FindNode(BTNode * b,ElemType x)
 {	BTNode *p;
 	if(b==NULL)
 		return NULL;
		else if(b->data==x)
			return b;
		else
		{	p=FindNode(b-> lchild,x);
			if(p!=NULL)
				return p;
			else
				return FindNode(b->rchild,x);
		}
 }
 
 //找孩子结点
 BTNode * LchildNode(BTNode *p)
 {
 	return p->lchild;
 }
 BTNode * RchildNode(BTNode *p)
 {
 	return p->rchild;
 }
 //求高度
 int BTNodeHeight(BTNode *b)
 {	int lchildh,rchildh;
 	 if(b==NULL)	return(0);
 	 else
 	 {
 	 	lchildh=BTNodeHeight(b->lchild);
 	 	rchildh=BTNodeHeight(b->rchild);
 	 	return(lchildh>rchildh)?(lchildh+1):(rchildh+1);
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

//求二叉树b的结点个数
int NodesNum(BTNode * b)
{	int m,n;
	if(b==NULL)
		return 0;
	else if(b->lchild==NULL && b->rchild==NULL) 
 		return 1;
	else
	{
		m=NodesNum(b->lchild);
		n=NodesNum(b->rchild);
		return(m+n+1);
	}
}
//叶子结点个数
int LeafNode(BTNode * b)
{
	int m,n;
	if(b==NULL)
		return 0;
	else if(b->lchild==NULL&&b->rchild==NULL)
		return 1;
	else
	{	m=LeafNode(b->lchild);
		n=LeafNode(b->rchild);
		return(m+n);
	}
}
void DispLeaf(BTNode *b)
{
	if(b!=NULL)
	{
		if(b->lchild==NULL&&b->rchild==NULL)
			printf("%c",b->data);
		DispLeaf(b->lchild);
		DispLeaf(b->rchild);
	}
}
int PreOrder(BTNode *b) 	/*先序遍历的递归算法*/
  {
  	if (b!=NULL)  
    {   printf("%c ",b->data); /*访问根结点*/
 		PreOrder(b->lchild);
 		PreOrder(b->rchild);
        }
  }
int InOrder(BTNode *b) 	/*中序遍历的递归算法*/
 {
 	if (b!=NULL)  
 	{ 	InOrder(b->lchild);
		printf("%c ",b->data); /*访问根结点*/
		InOrder(b->rchild);
	}
  }

int PostOrder(BTNode *b) /*后序遍历递归算法*/
 {
 	if (b!=NULL)  
 	{	PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ",b->data); /*访问根结点*/
	}
 }

void main()
{
	BTNode *b,*p,* lp,*rp;
	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))");
	printf("二叉树的基本元算如下:\n");
	printf("  (1)输出二叉树b：");
	DispBTNode(b);
	printf("\n");
	printf("  (2)H结点的左右孩子结点值：");
	p=FindNode(b,'H');
	if(p!=NULL)
	{
		lp=LchildNode(p);
		if(lp!=NULL)
			printf("左孩子为%c",lp->data);
		else
			printf("无左孩子");
		rp=RchildNode(p);
		if(rp!=NULL)
			printf("右孩子为%c",rp->data);
		else
			printf("无右孩子"); 
	}
	printf("\n"); 
	printf("  (3)二叉树b的深度为:%d\n",BTNodeHeight(b));
	printf("  (4)二叉树b的节点个数：%d\n",NodesNum(b));
	printf("  (5)二叉树b的叶子节点个数及叶子节点值:%d  ",LeafNode(b));
	DispLeaf(b);
	printf("\n");
	printf("  (6)二叉树b的先序遍历序列:");PreOrder(b);
	printf("\n");
	printf("  (7)二叉树b的中序遍历序列:");InOrder(b);
	printf("\n");
	printf("  (8)二叉树b的后序遍历序列:");PostOrder(b);
	printf("\n");
} 
