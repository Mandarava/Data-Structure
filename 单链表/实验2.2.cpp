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
	printf("单链表的基本运算如下:\n");
	printf("  (1)初始化单链表h\n");
	InitList(h);
	printf("  (2)一次采用尾插法插入a,b,c,d,e元素\n");
	ListInsert(h,1,'a'); 
	ListInsert(h,2,'b'); 
	ListInsert(h,3,'c'); 
	ListInsert(h,4,'d'); 
	ListInsert(h,5,'e'); 
	printf("  (3)输出单链表h:");
	DispList(h);
	printf("  (4)单链表h的长度= %d \n",ListLength(h));
	printf("  (5)单链表h为%s\n",(ListEmpty(h)?"空":"非空"));
	GetElem(h,3,e);
	printf("  (6)单链表h的第3个元素=%c\n",e);
	printf("  (7)元素a的位置=%d\n",LocateElem(h,'a'));
	printf("  (8)在第4个元素位置上插入f元素\n");
	ListInsert(h,4,'f');
	printf("  (9)输出单链表h：");
	DispList(h);
	printf("  (10)删除h的第3个元素\n");
	ListDelete(h,3,e);
	printf("  (11)输出单链表h：");
	DispList(h);
	printf("  (12)释放单链表h\n");
	DestroyList(h);
}
