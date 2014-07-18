#include<stdio.h>
#include<alloc.h>

typedef struct node
{
	int data;
	struct node *next;
}LNode,*LinkList;

LinkList create_LinkList()
{
	LinkList L=NULL;
	LNode *s,*r=NULL;
	int x;
	printf("Please input Linklist:");
	scanf("%d",&x);
	while(x!=9999)
	{       s=(LNode *)malloc(sizeof(LNode));
		s->data=x;	s->next=NULL;
		if (L==NULL)	L=s;
		else r->next=s;
		r=s;
		scanf("%d",&x);
	}
	return L;
}
void Output_LinkList(LinkList L)
{
	LinkList p=L;
	while (p!=NULL)
	{	printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}

LNode *get_LinkList(LinkList L,int i)
{
	LNode *p=L;
	int j=1;
	while (p->next!=NULL && j<i)
	{	p=p->next;	j++;
	}
	if (j==i) return p;
	else return NULL;
}

int del_LinkList(LinkList L,int i)
{
	LinkList p,s;
	p=get_LinkList(L,i-1);
	if (p==NULL) 
	{	printf("i not exist");		return -1;
	}
	else
	{	s=p->next;
		p->next=s->next;
		free(s);	return 1;
	}
}	

void main()
{	LinkList A;
	int len,i,x,d;
	LNode *s;
	A=create_LinkList();
	Output_LinkList(A);		printf("\n");
	scanf("%d",&i);
	d=del_LinkList(A,i);
	if (d==1) Output_LinkList(A);	printf("\n");
	
}

