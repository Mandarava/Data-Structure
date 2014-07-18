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
	LNode *s,*r;
	int x;
	s=(LNode *)malloc(sizeof(LNode));
	s->next=NULL;
	L=s;    r=L;
	printf("Please input Linklist:");
	scanf("%d",&x);
	while(x!=9999)
	{       s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		s->next=NULL;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	return L;
}
void Output_LinkList(LinkList L)
{
	LinkList p=L->next;
	while (p!=NULL)
	{	printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}

LinkList merge(LinkList A,LinkList B)
{
	LinkList C,p,q,s,r;
	p=A->next; q=B->next;
	C=A;C->next=NULL;r=C;
	while(p && q)
	{	if (p->data<q->data)
		{	s=p;p=p->next;}
		else
		{	s=q;q=q->next;}
		r->next=s;
		r=s;
	}
	while (p)
	{	r->next=p;
		r=p;
		p=p->next;
	}
	while (q)
	{
		r->next=q;
		r=q;
		q=q->next;
	}
	return C;
}

void main()
{	LinkList A,B,C;

	A=create_LinkList();
	B=create_LinkList();
	C=merge(A,B);
	Output_LinkList(C);
}

