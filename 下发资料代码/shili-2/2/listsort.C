#include <stdio.h>
#include <malloc.h>
#define null 0
typedef struct linknode
{
	int data;
	struct linknode *next;
}node;

node *create(int a[],int n)
{	node *h,*q;
	for (h=null;n;n--)
	{
		q=(node*)malloc(sizeof(node));
		q->data=a[n-1];
		q->next=h;
		h=q;
	}
	return(h);
}

void sort(node **h)
{
	node *p,*q,*r,*s,*h1;
	h1=p=(node*)malloc(sizeof(node));
	p->next=*h;
	while (p->next!=null)
	{
		q=p->next;
		r=p;
		while (q->next!=null)
		{
			if (q->next->data<r->next->data) r=q;
			q=q->next;
		}
		if (r!=p)
		{
			s=r->next;
			r->next=s->next;
			s->next=p->next;
			p->next=s;
		}
		p=p->next;
	}
	*h=h1->next;
	free(h1);
}

int test_data[]={5,9,3,1,2,7,8,6,4};
main()
{
	node *h,*p;
	h=create(test_data,sizeof(test_data)/sizeof(int));
	printf("qian:\n");
	for (p=h;p;p=p->next) printf("%2d",p->data);
	printf("\n");
	sort(&h);
	printf("hou:\n");
	for (p=h;p;p=p->next) printf("%2d",p->data);
	printf("\n");
}


