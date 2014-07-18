#define NULL 0
#include <alloc.h>
#include <stdio.h>

typedef struct node
{
   int data;
   struct node *next;
}Lnode,*Linklist;

Linklist Creat_linklist2()
{
   Linklist L;
   Lnode *s,*r=NULL;
   int x;
   L=(Linklist)malloc(sizeof(Linklist));
   L->next=NULL;
   printf("please input x :");
   scanf("%d",&x);
   printf("\n");
   while(x!=-1)
   {
      s=(Lnode *)malloc(sizeof(Lnode));
      s->data=x;
      if(L->next==NULL)
	     L->next=s;
      else
	     r->next=s;
      r=s;
      printf("please input x:");
      scanf("%d",&x);
      printf("\n");
   }
   if(r!=NULL)
      r->next=NULL;
   return L;
}

void reverse(Linklist H)
{
   Lnode *p,*q;
   p=H->next;
   H->next=NULL;
   while(p!=NULL)
   {
       q=p;
       p=p->next;
       q->next=H->next;
       H->next=q;
   }
   p=H->next;
   while(p!=NULL)
   {
       printf("%d ",p->data);
       p=p->next;
   }
}

main()
{
    Linklist p,H;
    H=Creat_linklist2();
    p=H->next;
    while(p!=NULL)
    {
	 printf("%d ",p->data);
	 p=p->next;
    }
    printf("\n");
    reverse(H);
    printf("\n");
}
