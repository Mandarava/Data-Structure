#include <stdio.h>
#include<malloc.h>
typedef struct node
{	int num;
	struct node *next;
}linklist;

linklist *create (linklist *head,int n,int m)	/*使个人围成一圈，并给每个人标识号数*/
{	linklist *s,*p,*q,*r;
	int i,t,d;
	s=(linklist*)malloc(sizeof(linklist));
	s->num=1;
	head=s;
	p=s;
	for (i=2;i<=n;i++)
	{	s=(linklist*)malloc(sizeof(linklist));
		s->num=i;
		p->next=s;
		p=s;
	}
	p->next=head;       
	printf("原始顺序：\n");
	p=head;
	while (p->next!=head)
	{	printf("%4d",p->num);
		p=p->next;
	}
	printf("%4d\n",p->num);printf("报数过程:\n");
	p=head;	t=1;  d=0;
	q=p;			/*q为p的前驱指针*/
	while (d<n-1)
	{	p=q->next;	/*p指向当前报数的人*/
		t=t+1;		/*报一次数*/
		if (t%m==0)
		{	printf("%4d",p->num);
			r=p;
			q->next=p->next;
			p=q;
			free(r);
			d++;
		}
		else
			q=p;
	}
	printf("%4d\n",p->num);
	head=p;
	return (head);
}	/*create*/

main()
{	int n,m;
	linklist *head,*p,*s;
	printf("input the total number:\n");
	scanf("%d",&n);
	printf("input the  number to call:\n");
	scanf("%d",&m);
	s=(linklist*)malloc(sizeof(linklist));
	head=s;
	create(head,n,m);
}	/*main*/

