#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct LNode
{	ElemType data;
	struct LNode *next;
}LinkList;
void InitList(LinkList * &L)
{	L=(LinkList *)malloc(sizeof(LinkList));
	L->next=L;
}
void DestroyList(LinkList *&L)
{	LinkList *p=L,*q=p->next;
	while(q!=L)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
bool ListEmpty(LinkList *L)
{
	return(L->next==L);
}
int ListLength(LinkList *L)
{	int i=0; 
	LinkList *p=L;
	while(p->next!=L)
	{	i++;
		p=p->next;
	}
	return(i);
}
void DispList(LinkList *L)
{	LinkList *p=L->next;
	while(p!=L)
	{	printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0;
	LinkList *p;
	if(L->next!=L)
	{
		if(i==1)
		{	e=L->next->data;
			return true;
		}
		else {
			p=L->next;
			while(j<i-1&&p!=L)
			{
				j++;
				p=p->next;
			}
			if(p==L)
			return false;
			else
			{	e=p->data;
			return true;
			}
		}
	}
	else
		return false;
}
int LocateElem(LinkList *L,ElemType e)
{	
	LinkList *p=L->next;
	int n=1;
	while(p!=L&&p->data!=e)
	{	p=p->next;
		n++;
	}
	if(p==L)
	return(0);
	else
	return(n);
}
bool ListInsert(LinkList *&L,int i, ElemType e)
{
	int j=0;
	LinkList *p=L,*s;
	if(p->next==L||i==1)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
	}
	else
	{
		p=L->next;
		while(j<i-2&&p!=L)
		{
			j++;
			p=p->next;
		}
		if(p==L)
		return false;
		else
		{
			s=(LinkList *)malloc(sizeof(LinkList));
			s->data=e;
			s->next=p->next;
			p->next=s;
			return true;
		}
	}
}
bool ListDelete(LinkList *&L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L,*q;
	if(p->next!=L)
	{
		if(i==1)
		{
			q=L->next;
			e=q->data;
			L->next=q->next;
			free(q);
			return true;
		}
		else
		{
			p=L->next;
			while (j<i-2&&p!=L)
			{
				j++;
				p=p->next;
			}
			if(p==L)
			return false;
			else
			{
				q=p->next;
				e=q->data;
				p->next=q->next;
				free(q);
				return true;
			}
		}
	}
	else
		return false;
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
	printf("循环单链表的基本运算如下：\n");
	printf(" （1）初始化循环单链表h\n");
	InitList(h);
	printf("  (2)一次采用尾插法插入abcde元素\n");
	ListInsert(h,1,'a');
	ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');
	printf("  (3)输出循环单链表h:");
	DispList(h);
	printf("  (4)循环单链表h的长度=%d\n",ListLength(h));
	printf("  (5)循环单链表h为%s\n",(ListEmpty(h)?"空":"非空"));
	GetElem(h,3,e);
	printf("  (6)循环单链表h的第3个元素=%c\n",e);
	printf("  (7)元素a的位置=%d\n",LocateElem(h,'a'));
	printf("  (8)在第4个元素位置上插入f元素\n");
	ListInsert(h,4,'f');
	printf("  (9)输出循环单链表h：");
	DispList(h);
	printf("  (10)删除h的第3个元素\n");
	ListDelete(h,3,e);
	printf("  (11)输出循环单链表h：");
	DispList(h);
	printf("  (12)释放循环单链表h\n");
	DestroyList(h);
}
	
			
	

