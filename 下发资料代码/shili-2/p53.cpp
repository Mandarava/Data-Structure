#include<stdio.h>
#include<alloc.h>
#define MAXSIZE 100
typedef struct
{
	int data[MAXSIZE];
	int length;
}SeqList;

SeqList *create_SeqList()
{
	SeqList *L;
	int i;
	L=(SeqList *)malloc(sizeof(SeqList));
	L->length=0;
	for(i=0;i<=4;i++)
		scanf("%d",&L->data[i]);
	L->length=5;
	return L;
}
void Output_SeqList(SeqList *L)
{
	int i;
	for(i=0;i<L->length;i++)
		printf("%d\t",L->data[i]);
	printf("\n");
}
void Insert1(SeqList *&L,int x)
   {    int i=0,j;
         while (i<L->length && L->data[i]<x) 
	     i++;
         for (j=L->length-1;j>=i;j--)
       	     L->data[j+1]=L->data[j];
         L->data[i]=x;
         L->length++;
   }

void main()
{	SeqList *L;
	int rValue,a,b;
	L=create_SeqList();Output_SeqList(L);
    scanf("%d",&a);
	Insert1(L,a);
	Output_SeqList(L);
}

