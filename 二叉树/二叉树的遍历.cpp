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
 //���ҽ�� 
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
 
 //�Һ��ӽ��
 BTNode * LchildNode(BTNode *p)
 {
 	return p->lchild;
 }
 BTNode * RchildNode(BTNode *p)
 {
 	return p->rchild;
 }
 //��߶�
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

//�������b�Ľ�����
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
//Ҷ�ӽ�����
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
int PreOrder(BTNode *b) 	/*��������ĵݹ��㷨*/
  {
  	if (b!=NULL)  
    {   printf("%c ",b->data); /*���ʸ����*/
 		PreOrder(b->lchild);
 		PreOrder(b->rchild);
        }
  }
int InOrder(BTNode *b) 	/*��������ĵݹ��㷨*/
 {
 	if (b!=NULL)  
 	{ 	InOrder(b->lchild);
		printf("%c ",b->data); /*���ʸ����*/
		InOrder(b->rchild);
	}
  }

int PostOrder(BTNode *b) /*��������ݹ��㷨*/
 {
 	if (b!=NULL)  
 	{	PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ",b->data); /*���ʸ����*/
	}
 }

void main()
{
	BTNode *b,*p,* lp,*rp;
	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))");
	printf("�������Ļ���Ԫ������:\n");
	printf("  (1)���������b��");
	DispBTNode(b);
	printf("\n");
	printf("  (2)H�������Һ��ӽ��ֵ��");
	p=FindNode(b,'H');
	if(p!=NULL)
	{
		lp=LchildNode(p);
		if(lp!=NULL)
			printf("����Ϊ%c",lp->data);
		else
			printf("������");
		rp=RchildNode(p);
		if(rp!=NULL)
			printf("�Һ���Ϊ%c",rp->data);
		else
			printf("���Һ���"); 
	}
	printf("\n"); 
	printf("  (3)������b�����Ϊ:%d\n",BTNodeHeight(b));
	printf("  (4)������b�Ľڵ������%d\n",NodesNum(b));
	printf("  (5)������b��Ҷ�ӽڵ������Ҷ�ӽڵ�ֵ:%d  ",LeafNode(b));
	DispLeaf(b);
	printf("\n");
	printf("  (6)������b�������������:");PreOrder(b);
	printf("\n");
	printf("  (7)������b�������������:");InOrder(b);
	printf("\n");
	printf("  (8)������b�ĺ����������:");PostOrder(b);
	printf("\n");
} 
