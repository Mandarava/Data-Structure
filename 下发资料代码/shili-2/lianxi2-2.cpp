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

void Insert(LinkList L,int x)
{
	int i;
	LinkList p,q,s;
	s=(LNode *)malloc(sizeof(LNode));
	s->data=x;
	s->next=NULL;
	p=L->next;
	if (x<p->data)  {	s->next=p;
				L->next=s;
			}
	else{
		while ((p!=NULL) && p->data<x)
		{	q=p;
			p=p->next;
		}
		if (p==NULL)  	q->next=s;
		else {	q->next=s;
			s->next=p;
		     }
	    }
}

void main()
{	LinkList A;
	int x;

	A=create_LinkList();
	printf("Please input the number that you want to insert:");
	scanf("%d",&x);
	Insert(A,x);
	Output_LinkList(A);
}

