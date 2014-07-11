#include<stdio.h>
#include<malloc.h>
#define Maxsize 50
typedef char ElemType;
typedef struct
{
	ElemType data[Maxsize];
	int length;
} SqList;
void InitList(SqList * &L)					//��ʼ�����Ա� 
{  	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}
void DestroyList(SqList *L)					//�������Ա� 
{
	free(L);
}
bool ListEmpty(SqList *L)					//�ж����Ա��Ƿ�Ϊ�ձ� 
{
	return(L->length==0);
}
int ListLength(SqList *L)					//�����Ա�ĳ��� 
{
	return(L->length);
}
void DispList(SqList *L)					//������Ա� 
{
	int i;
	if(ListEmpty(L)) return;
	for (i=0;i<	L->length;i++)
		printf("%c",L->data[i]);
	printf("\n");
}
bool GetElem(SqList *L,int i,ElemType &e)
{
	if (i<1 || i>L->length)
		return 0;
	e=L->data[i-1];
	return 1;
}
int LocateElem(SqList *L,ElemType e)
{
	int i=0;
	while(i<L->length&&L->data[i]!=e)
		i++;
	if (i>=L->length)
		return 0;
	else
		return i+1;
}
bool ListInsert(SqList * &L,int i,ElemType e)
{
	int j;
	if(i<1 || i>L->length+1)
		return 0;
	i--;
	for(j=L->length;j>i;j--)
		L->data[j]=L->data[j-1];
	L->data[i]=e;
	L->length++;
	return 1;
}
bool ListDelete(SqList * &L,int i,ElemType &e)
{
	int j;
	if(i<1||i>L->length)
	return 0;
	i--;
	e=L->data[i];
	for(j=i;j<L->length-1;j++)
		L->data[j]=L->data[j+1];
		L->length--;
		return 1;
}
extern void InitList(SqList *&L);
extern void DestroyList(SqList *L);
extern bool ListEmpty(SqList *L);
extern int  ListLength(SqList *L);
extern void DispList(SqList *L);
extern bool GetElem(SqList *L,int i,ElemType &e);
extern int  LocateElem(SqList *L,ElemType e);
extern bool ListInsert(SqList * &L,int i,ElemType e);
extern bool ListDelete(SqList * &L,int i,ElemType &e);
void main()
{
	SqList *L;
	ElemType e;
	printf("˳���Ļ����������£�\n");
	printf("  (1)��ʼ��˳���L \n");
	InitList(L);
	printf("  (2)���β���β�巨����a,b,c,d,eԪ�� \n"); 
	ListInsert(L,1,'a');
	ListInsert(L,2,'b');
	ListInsert(L,3,'c');
	ListInsert(L,4,'d');
	ListInsert(L,5,'e');
	printf("  (3)���˳���L��"); 
	DispList(L);
	printf("  (4)˳���L�ĳ���=%d \n",ListLength(L));
	printf("  (5)˳���LΪ%s \n",(ListEmpty(L)?"��":"�ǿ�"));
	GetElem(L,3,e);
	printf("  (6)˳���L�ĵ�3��Ԫ��=%c\n",e);
	printf("  (7)Ԫ��a��λ��=%d \n",LocateElem(L,'a'));
	printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(L,4,'f');
	printf("  (9)���˳���L��");
	DispList(L);
	printf("  (10)ɾ��L�ĵ�3��Ԫ��\n");
	ListDelete(L,3,e);
	printf("  (11)���˳���L��");
	DispList(L);
	printf("  (12)�ͷ�˳���L\n");
	DestroyList(L);
}
	 
