#include <malloc.h>
#include <stdio.h>
#define MAXSIZE 100

typedef struct
	{
	 int data[MAXSIZE];
	 int last;
	}	SeqList;

SeqList *Creat_SeqList()
	{
	 SeqList *L;
	 L=(SeqList *)malloc(sizeof(SeqList));
	 L->last=-1;	return L;
	}

void Delete_SeqList(SeqList *L)
	{
	 int i,j,k;
	 for (i=0;i<=L->last;i++)
		if (L->data[i]==L->data[i+1])
			{
			 for (j=i;j<=L->last;j++)
				L->data[j]=L->data[j+1];
			 L->last--;
			 i--;
			}
	L->last++;
	}

void main()
	{
	 int i,j,k;
	 SeqList *L;
	 L=Creat_SeqList();
	 printf("Input the integer:");
	 for (i=0;i<=7;i++)
		{
		 scanf ("%d",&L->data[i]);
		 L->last++;
		}
	 L->last--;
	 Delete_SeqList(L);
	 for (k=0;k<=L->last;k++)
		printf ("%d ",L->data[k]);
	 printf ("\n\n");
}




