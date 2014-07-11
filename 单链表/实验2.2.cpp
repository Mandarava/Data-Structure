#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkList;
void InitList(LinkList *&L)
{
	L=(LinkList *)malloc(sizeof(LinkList));
	L->next=NULL;
}
void DestroyList(LinkList *&L)
{
	LinkList *p=L,*q=p->next;
	while (q!=NULL)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
bool ListEmpty(LinkList *L)
{
	return(L->next==NULL);
}
int ListLength(LinkList *L)
{
	LinkList *p=L;int i=0;
	while (p->next!=NULL)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while (p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L;
	while (j<i&&p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)
		return false;
	else
	{
		e=p->data;
		return true;
	}
}
int LocateElem(LinkList *L ,ElemType e)
{
	int i=1;
	LinkList *p=L->next;
	while(p!=NULL&&p->data!=e)
	{
		p=p->next;
		i++;
	}
	if(p==NULL)
		return(0);
	else
		return (i);
}
bool ListInsert(LinkList * &L,int i,ElemType e)
{
	int j=0;
	LinkList *p=L,*s;
	while(p!=NULL&&j<i-1)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else {
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
	}
}
bool ListDelete(LinkList *&L,int i, ElemType &e)
{
	int j=0;
	LinkList *p=L,*q;
	while(j<i-1&&p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else 
	{
		q=p->next;
		if(q==NULL)
			return false;
		e=q->data;
		p->next=q->next;
		free(q);
		return true;
	}
}
extern void InitList(LinkList *&L);
extern void DestroyList(LinkList *&L);
extern bool ListEmpty(LinkList *L);
extern int ListLength(LinkList *L);
extern void DispList(LinkList *L);
extern bool GetElem(LinkList *L,int i,ElemType &e);
extern int LocateElem(LinkList *L,ElemType e);
extern bool ListInsert(LinkList *&L,int i,ElemType e);
extern bool ListDelete(LinkList *&L,int i,ElemType &e);

void main()
{
	LinkList *h;
	ElemType e;
	printf("������Ļ�����������:\n");
	printf("  (1)��ʼ��������h\n");
	InitList(h);
	printf("  (2)һ�β���β�巨����a,b,c,d,eԪ��\n");
	ListInsert(h,1,'a'); 
	ListInsert(h,2,'b'); 
	ListInsert(h,3,'c'); 
	ListInsert(h,4,'d'); 
	ListInsert(h,5,'e'); 
	printf("  (3)���������h:");
	DispList(h);
	printf("  (4)������h�ĳ���= %d \n",ListLength(h));
	printf("  (5)������hΪ%s\n",(ListEmpty(h)?"��":"�ǿ�"));
	GetElem(h,3,e);
	printf("  (6)������h�ĵ�3��Ԫ��=%c\n",e);
	printf("  (7)Ԫ��a��λ��=%d\n",LocateElem(h,'a'));
	printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(h,4,'f');
	printf("  (9)���������h��");
	DispList(h);
	printf("  (10)ɾ��h�ĵ�3��Ԫ��\n");
	ListDelete(h,3,e);
	printf("  (11)���������h��");
	DispList(h);
	printf("  (12)�ͷŵ�����h\n");
	DestroyList(h);
}
