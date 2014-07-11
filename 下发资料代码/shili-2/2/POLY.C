#include <stdio.h>	/*创建多项式*/
#define null 0
typedef struct pnode
{
	int coef;
	int exp;
	struct pnode *next;
}node;

node *poly()
{
	node *head,*r,*s;
	int m,n;
	head=(node*)malloc(sizeof(node));
	r=head;
	printf("\n");
	printf("n,m:");
	scanf("%d,%d",&n,&m);
	while (n!=0)
	{
		s=(node*)malloc(sizeof(node));
		s->coef=n;
		s->exp=m;
		r->next=s;
		r=s;
		printf("n,m:");
		scanf("%d,%d",&n,&m);
	}
	r->next=null;
	head=head->next;
	return(head);
}

main()
{
	node *head,*p;
	head=poly();
	p=head;
	printf("\n");
	while (p!=null)
	{
		printf("%5d%5d\n",p->coef,p->exp);
		p=p->next;
	}
}