#include<stdio.h>
#include<alloc.h>

typedef struct node/**找到单链表中最小元素,若是偶数则删除它后继元素,若是奇数则与后继元素交换位置**/
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

LinkList op(LinkList L)
{
	LinkList p,q,r;
	q=L;
	p=q;
	while (q!=NULL)
	{	if (p->data>q->data)	p=q;
		q=q->next;
	}/*while*/
	printf("\n%d\n",p->data);
	if (((p->data)% 2)==0)
	{	if (p->next!=NULL)
		{	r=p->next;
			p->next=r->next;
			free(r);
		}/*if*/
	}
	else
	{	if (p->next!=NULL)
		{	q=L;
		    if (L==p)
		    {   r=p->next;
		        q=r;
		        p->next=r->next;
		        q->next=p;
		        L=q;
		    }
		    else
		    {	while (q->next!=p)	q=q->next;
			    r=p->next;
			    q->next=r;
			    p->next=r->next;
			    r->next=p;
		    }
		}/*if*/
	}/*if*/return L;
}/*op*/

void main()
{	LinkList A;

	A=create_LinkList();
	Output_LinkList(A);
	A=op(A);
	Output_LinkList(A);
}


