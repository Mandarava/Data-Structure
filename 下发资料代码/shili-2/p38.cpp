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
int length_LinkList(LinkList L)
{
	LNode *p=L;
	int j;
	if (p==NULL) return 0;
	j=1;
	while (p->next)
	{	p=p->next;
		j++;
	}
	return j;
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
int insert_LinkList(LinkList L,int i,int y)
{
	LNode *p,*s;
	p=get_LinkList(L,i-1);
	if (p==NULL)
	{	printf("error i");
		return 0;
	}
	else
	{	s=(LNode *)malloc(sizeof(LNode));
		s->data=y;	s->next=p->next;
		p->next=s;	return 1;
	}
}


void main()
{	LinkList A;
	int len,i,x,d;
	LNode *s;

	A=create_LinkList();
	Output_LinkList(A);
	len=length_LinkList(A);		printf("len is %d\n",len);
	scanf("%d",&i);
	s=get_LinkList(A,i);
	if (s!=NULL)	printf("%d\n",s->data);
	else printf("not exist!\n");
	scanf("%d,%d",&i,&x);
	d=insert_LinkList(A,i,x);
	if (d==1) Output_LinkList(A);

}

