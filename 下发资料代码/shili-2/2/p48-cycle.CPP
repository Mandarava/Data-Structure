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
	r->next=L;
	return L;
}
void Output_LinkList(LinkList L)
{
	LinkList p=L;
	while (p->next!=L)
	{	printf("%d\t",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}

void main()
{	LinkList A;

	A=create_LinkList();
	Output_LinkList(A);
}

