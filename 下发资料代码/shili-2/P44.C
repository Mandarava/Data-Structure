#define NULL 0
#include <stdio.h>
#include <malloc.h>
typedef struct node
{
   int data;
   struct node *next;
}Lnode,*Linklist;

Linklist Creat_linklist2()
{
   Linklist L=NULL;
   Lnode *s,*r=NULL;
   int x;
   printf("please input x :");
   scanf("%d",&x);
   printf("\n");
   while(x!=-1)
   {
      s=(Lnode *)malloc(sizeof(Lnode));
      s->data=x;
      if(L==NULL)
        L=s;
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
   p=H;
   H=NULL;
   while(p!=NULL)
   {
       q=p;
       p=p->next;
       q->next=H;
       H=q;
   }
   p=H;
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
    p=H;
    while(p!=NULL)
    {
	 printf("%d ",p->data);
	 p=p->next;
    }
    printf("\n");
    reverse(H);
    printf("\n");
}
