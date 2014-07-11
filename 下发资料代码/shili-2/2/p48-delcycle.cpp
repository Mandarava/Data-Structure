#include<stdio.h>
#include<alloc.h>

typedef struct node
{
	int data;
	struct node *next;
}LNode,*LinkList;

LinkList create_CycleLinkList()
{
	LinkList L=NULL;
	LNode *s,*r;
	int x;
	printf("Please input Linklist:");
	scanf("%d",&x);
	while(x!=9999)
	{       s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		s->next=NULL;
		if (L==NULL)	L=s;
		else 		r->next=s;
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

void Del_Cycle(LinkList L,int x)
{
	LinkList p,q,s;
	p=L;
	while ((p->next!=L) && (p->next->data!=x))
	{	q=p;
		p=p->next;
	}
	if (p->next==L)
		printf("This node is not exist!\n");
	else {	q->next=p->next;
		free(p);
	     }
}

void main()
{	LinkList A;
	int x;

	A=create_CycleLinkList();
	Output_LinkList(A);
	printf("Please input the data which you want to del before it:");
	scanf("%d",&x);
	Del_Cycle(A,x);
	Output_LinkList(A);
}

