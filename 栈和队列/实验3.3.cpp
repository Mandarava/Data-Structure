#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front,rear;
}SqQueue;
void InitQueue(SqQueue *&q)
{
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
bool QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)
{
	if((q->rear+1)%MaxSize==q->front)
		return 0;
		q->rear=(q->rear+1)%MaxSize;
		q->data[q->rear]=e;
		return 1;
}
bool deQueue(SqQueue *&q,ElemType &e)
{
	if(q->front==q->rear)
	return 0;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return 1;
}
int QueueLength(SqQueue *q)
{
	return (q->rear-q->front+MaxSize)%MaxSize;
}
void main()
{ 	
	ElemType e;
	SqQueue *q;
	printf("���ζ��л����������£�\n");
	printf(" (1)��ʼ������q\n");
	InitQueue(q); 
	printf(" (2)����Ϊ%s\n",(QueueEmpty(q)?"��":"�ǿ�"));
	printf(" (3)���ν�����Ԫ��a,b,c\n");
	if(!enQueue(q,'a'))
	printf("\t��ʾ�����������ܽ���\n");
	if(!enQueue(q,'b'))
	printf("\t��ʾ�����������ܽ���\n");
	if(!enQueue(q,'c'))
	printf("\t��ʾ�����������ܽ���\n");
	//printf(" (3)����Ϊ%s\n",(QueueEmpty(q)?"��":"�ǿ�"));
	if(deQueue(q,e)==0)
		printf("�ӿգ����ܳ���\n");
	else
		printf("  (4)����һ��Ԫ��%c\n",e);
		printf("  (5)����qԪ�ظ���=%d\n",QueueLength(q));
	printf("  (6)���ν�����Ԫ��d,e,f\n");
		if(!enQueue(q,'d'))
	printf("\t��ʾ�����������ܽ���\n");
	if(!enQueue(q,'e'))
	printf("\t��ʾ�����������ܽ���\n");
	if(!enQueue(q,'f'))
	printf("\t��ʾ�����������ܽ���\n");
	printf("  (7)����qԪ�ظ���=%d\n",QueueLength(q));
	printf("  (8)���������У�");
	while(!QueueEmpty(q))
	{
		deQueue(q,e);
		printf("%c",e);
	}
	printf("\n");
	printf("  (9)�ͷŶ���\n");
	DestroyQueue(q);
}
