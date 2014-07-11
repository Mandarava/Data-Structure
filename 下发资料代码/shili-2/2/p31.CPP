#include<stdio.h>
#include<alloc.h>
#define MAXSIZE 100
typedef struct
{
	int data[MAXSIZE];
	int length;
}SqList;

SqList *create_SeqList()
{
	SqList *L;
	int i;
	L=(SqList *)malloc(sizeof(SqList));
	L->length=-1;
	for(i=0;i<=4;i++)
		scanf("%d",&L->data[i]);
	L->length=5;
	return L;
}
void Output_SeqList(SqList *L)
{
	int i;
	for(i=0;i<=L->length-1;i++)
		printf("%d\t",L->data[i]);
	printf("\n");
}
int Insert_SeqList(SqList *L,int i,int x)
{
	int j;
	if (L->length==MAXSIZE-1)
	{  	printf("SeqList is full!\n");
		return(-1);
	}
	if (i<1||i>L->length+1)
	{
		printf("Insert location wrong!\n");
		return(0);
	}
	for (j=L->length;j>=i-1;j--)
		L->data[j+1]=L->data[j];
	L->data[i-1]=x;
	L->length++;
	return(1);
}
int Delete_SeqList(SqList *L,int i)
{	int j;
	if (i<1||i>L->length+1)
	{	printf("The i element is not exist!\n");
		return(0);
	}
	for(j=i;j<=L->length;j++)
		L->data[j-1]=L->data[j];
	L->length--;
	return(1);
}
int Location_SeqList(SqList *L,int x)
{	int i=0;
	while(i<=L->length && L->data[i]!=x)
		i++;
	if (i>L->length)
		return(-1);
	else return i;
}

void main()
{	SqList *L;
	int rValue;
	L=create_SeqList();
	Output_SeqList(L);
	rValue=Insert_SeqList(L,3,90);
	if (rValue==1)
		Output_SeqList(L);
	rValue=Delete_SeqList(L,5);
	if (rValue==1)
		Output_SeqList(L);
	rValue=Location_SeqList(L,56);
	if (rValue!=-1)
		printf("The 56 Element is locate num %d.\n",rValue+1);
	else 
		printf("not found\n");
}

