#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef struct
{
	int data[MAXSIZE];
	int length;
}SeqList;

SeqList *create_SeqList()
{
	SeqList *L;
	int x,i=1;
	L=(SeqList *)malloc(sizeof(SeqList));
	L->length=0;
	printf("Please input SeqList:");
	scanf("%d",&x);
	while (x!=9999)
	{	L->data[i++]=x;
		scanf("%d",&x);
	}
	L->length=i-1;
	return L;
}

void Output_SeqList(SeqList *L)
{
	int i;
	for(i=1;i<=L->length;i++)
		printf("%d\t",L->data[i]);
	printf("\n");
}

void Delete_SeqList(SeqList *L)
{	int i,j,k;
	for (i=1;i<L->length;i++)
	{       j=i;
		while  (L->data[j]==L->data[j+1] && j<=L->length)
		{	for(k=j;k<L->length;k++)
				L->data[k]=L->data[k+1];
			L->length--;
			j=i;
		}
	}
	if (L->data[1]==L->data[2])
		L->length=1;
}

void main()
{	SeqList *L;
	int rValue;
	L=create_SeqList();
	Delete_SeqList(L);
	Output_SeqList(L);
}

