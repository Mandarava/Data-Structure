#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;					
typedef char InfoType;
typedef struct node               		
{	
	KeyType key;                  	
    InfoType data;               		
    struct node *lchild,*rchild;		
} BSTNode;
int path[MaxSize];					
void DispBST(BSTNode *b);				
int InsertBST(BSTNode *&p,KeyType k)
{
   	if (p==NULL)					
	{
		p=(BSTNode *)malloc(sizeof(BSTNode));
		p->key=k;p->lchild=p->rchild=NULL;
		return 1;
	}
	else if (k==p->key) 
		return 0;
	else if (k<p->key) 
		return InsertBST(p->lchild,k);	
	else  
		return InsertBST(p->rchild,k);  
}
BSTNode *CreatBST(KeyType A[],int n)				
//由数组A中的关键字建立一棵二叉排序树
{
  	BSTNode *bt=NULL;         		
   	int i=0;
   	while (i<n) 
		if (InsertBST(bt,A[i])==1)		
		{
			printf("    第%d步,插入%d: ",i+1,A[i]);
			DispBST(bt);printf("\n");
			i++;
		}
    return bt;               			
}

void SearchBST1(BSTNode *bt,KeyType k,KeyType path[],int i)	
//以非递归方式输出从根节点到查找到的节点的路径
{ 
	int j;
	if (bt==NULL)
		return;
	else if (k==bt->key)
	{
		path[i+1]=bt->key;	
		for (j=0;j<=i+1;j++)
			printf("%3d",path[j]);
		printf("\n");
	}
	else
	{
		path[i+1]=bt->key;
		if (k<bt->key)
			SearchBST1(bt->lchild,k,path,i+1);  
		else
			SearchBST1(bt->rchild,k,path,i+1);  
	}
}
int SearchBST2(BSTNode *bt,KeyType k)	
//以递归方式输出从根节点到查找到的节点的路径
{ 
	if (bt==NULL)
		return 0;
	else if (k==bt->key)
	{
		printf("%3d",bt->key);
		return 1;
	}
	else if (k<bt->key)
		SearchBST2(bt->lchild,k);  
	else
		SearchBST2(bt->rchild,k);  
	printf("%3d",bt->key);
}

void DispBST(BSTNode *bt)	
//以括号表示法输出二叉排序树bt
{
	if (bt!=NULL)
	{
		printf("%d",bt->key);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{
			printf("(");
			DispBST(bt->lchild);
			if (bt->rchild!=NULL) printf(",");
			DispBST(bt->rchild);
			printf(")");
		}
	}
}


void main()
{
	BSTNode *bt;
	KeyType k=6;
	int a[]={4,9,0,1,8,6,3,5,2,7},n=10;
	printf("创建一棵BST树:");
	printf("\n");
	bt=CreatBST(a,n);
	printf("BST:");DispBST(bt);printf("\n");
	printf("  查找%d关键字(递归,顺序):",k);SearchBST1(bt,k,path,-1);
	printf("查找%d关键字(非递归,逆序):",k);SearchBST2(bt,k);
}
