#include<stdio.h>
#include<alloc.h>
#define MAXSIZE 100
typedef struct
{
	int data[MAXSIZE];
	int last;
}SeqList;

SeqList *create_SeqList()
{
	SeqList *L;
	int i=0,x;
	L=(SeqList *)malloc(sizeof(SeqList));
	L->last=0;
	printf("Please input Seqlist:");
	scanf("%d",&x);
	while(x!=9999)
	{       L->data[i++]=x;
		scanf("%d",&x);
	}
	L->last=i;
	return L;
}
void Output_SeqList(SeqList *L)
{
	int i;
	for(i=0;i<L->last;i++)
		printf("%d\t",L->data[i]);
	printf("\n");
}
void merge(SeqList *A,SeqList *B,SeqList *&C)
{	int i,j,k;
	i=0;j=0;k=0;
	C=(SeqList *)malloc(sizeof(SeqList));
	C->last=0;
	while(i<A->last && j<B->last)
		if (A->data[i]<B->data[j])
			C->data[k++]=A->data[i++];
		else	C->data[k++]=B->data[j++];
	while(i<A->last)
		C->data[k++]=A->data[i++];
	while(j<B->last)
		C->data[k++]=B->data[j++];
	C->last=k;
//	return C;
}


void main()
{	SeqList *A,*B,*C;
	int rValue;
	A=create_SeqList();Output_SeqList(A);
	B=create_SeqList();Output_SeqList(B);
	merge(A,B,C);
	Output_SeqList(C);
}

