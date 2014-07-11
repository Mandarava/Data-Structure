#include<stdio.h>
#include<alloc.h>
#define NULL 0
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

Lnode *Locate_Linklist(Linklist L,int x)
{
 Lnode *p=L;
 while(p!=NULL&&p->data!=x)
   p=p->next;
 return p;
}

main()
{
 int x;
 Linklist p,L;
 L=Creat_linklist2();
 p=L;
 while(p!=NULL)
  {
   printf("%d ",p->data);
   p=p->next;
  }
 printf("\n");
 printf("Please input x: ");
 scanf("%d",&x);
 p=Locate_Linklist(L,x);
 if(p==NULL)
   printf(" not exist this elem !\n");
 else
   printf("p->data=%d\n",p->data);
}

