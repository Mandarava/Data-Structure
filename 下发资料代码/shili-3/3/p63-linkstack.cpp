/*利用链栈实现链表反向输出*/
#define MAXSIZE 1024
#include <stdio.h>
#include <alloc.h>
typedef struct node
{	int data;
	struct node *next;
}stacknode,*linkstack;

linkstack create()
{	stacknode *s,*top;
	int x;
	printf("\nPlease input the data of stacknode:");
	scanf("%d",&x);
	if(x==9999)
		top=NULL;
	while(x!=9999)
	{	s=(stacknode *)malloc(sizeof(stacknode));
		s->data=x;
		s->next=top;
		top=s;
		scanf("%d",&x);
	}
	return top;
}

void output(linkstack top)
{	linkstack p;
	p=top;
	while(p)
	{	printf("%d\t",&p->data);
		p=p->next;
	}
}

typedef struct node1
{	int data;
	struct node1 *next;
}lnode,*linklist;

linklist create_linklist()
{	linklist L=NULL;
	int x;
	linklist s,r=NULL;
	printf("\nPlease input the data of linklist:");
	scanf("%d",&x);
	while(x!=9999)
	{	s=(lnode *)malloc(sizeof(lnode));
		s->data=x;
		if(L==NULL)
			L=s;
		else
			r->next=s;
		r=s;
		scanf("%d",&x);
	}
/*	s=(lnode *)malloc(sizeof(lnode));
	s->next=L;
	L=s;
*/	if(r)
		r->next=NULL;
	return L;
}

void output_linklist(linklist L)
{	linklist p=L;
	while(p)
	{	printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}

void back(linklist L)
{	linklist p;
	stacknode *s,*q;
	linkstack top=NULL;
//	top=create();
	p=L;
	while(p)
	{	s=(stacknode *)malloc(sizeof(stacknode));
		s->data=p->data;
		s->next=top;
		top=s;
		p=p->next;
	}
	p=L;
	q=top;
	while(p)
	{	p->data=q->data;
		q=q->next;
		p=p->next;
	}
	return ;
}

void main()
{	linklist L;
	linkstack s;
	L=create_linklist();
	printf("原始链表：\t");
	output_linklist(L);
	back(L);
	printf("\n反向输出链表：\t");
	output_linklist(L);
	printf("\n");
}
