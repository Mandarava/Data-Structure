#include <stdio.h>/*多项式的和*/
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

node *padd(heada,headb)
node *heada,*headb;
{
	node *headc,*p,*q,*s,*r;
	int x;
	p=heada;q=headb;
	headc=(node*)malloc(sizeof(node));
	r=headc;
	while (p!=null && q!=null)
	{
 		if (p->exp==q->exp)
  		 {
   			x=p->coef+q->coef;
  			 if (x!=0)
     			{
     				s=(node*)malloc(sizeof(node));
     				s->coef=x;
     				s->exp=p->exp;
    				r->next=s;
     				r=s;
     			}
    			p=p->next;q=q->next;
    		}
 		else
			if (p->exp>q->exp)
     			{
     				s=(node*)malloc(sizeof(node));
     				s->coef=q->coef;
     				s->exp=q->exp;
     				r->next=s;
     				r=s;
     				q=q->next;
     			}
    		else
      		{
      			s=(node*)malloc(sizeof(node));
      			s->coef=p->coef;
      			s->exp=p->exp;
      			r->next=s;
      			r=s;
      			p=p->next;
      		}
 	}
	while (p!=null)
	{
		s=(node*)malloc(sizeof(node));
		s->coef=p->coef;
		s->exp=p->exp;
		r->next=s;
		r=s;
		p=p->next;
	}
	while (q!=null)
	{
		s=(node*)malloc(sizeof(node));
		s->coef=q->coef;
		s->exp=q->exp;
		r->next=s;
		r=s;
		q=q->next;
	}
	r->next=null;
	s=headc;
	headc=headc->next;
	free(s);
	return(headc);
}

main()
{
	node *heada,*headb,*headc,*p;
	heada=poly();
	p=heada;
	printf("\n");
	while (p!=null)
	{
		printf("%5d%5d\n",p->coef,p->exp);
		p=p->next;
	}
	headb=poly();
	p=headb;
	printf("\n");
	while (p!=null)
	{
		printf("%5d%5d\n",p->coef,p->exp);
		p=p->next;
	}
	headc=padd(heada,headb);
	p=headc;
	printf("\n");
	while (p!=null)
	{
		printf("%5d%5d\n",p->coef,p->exp);
		p=p->next;
	}
}