#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#include<stdlib.h> 
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
	char name;
}SqStack;
void InitStack(SqStack *&s)        //��ʼ��ջ 
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
void DestroyStack(SqStack *&s)     //����ջ 
{
	free(s);
}
bool StackEmpty(SqStack *s)        //�ж�ջ�Ƿ�Ϊ�� 
{
	return(s->top==-1);
}
int Push(SqStack *&s,ElemType e)  //��ջ 
{
	if(s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return 1;
}
int Pop(SqStack *&s,ElemType &e) //��ջ 
{
	if(s->top==-1)
	return 0;
	e=s->data[s->top];
	s->top--;
	return 1;
}
int GetTop(SqStack *s,ElemType &e)   //ȡջ��Ԫ�� 
{
	if(s->top==-1)
	return 0;
	e=s->data[s->top];
	return 1;
}
 
void move(SqStack *a,int n,SqStack *c)
{ 	ElemType e1;
	printf("��%d���̴�%c�Ƶ�%c\n",a->data[a->top],a->name,c->name);
	Pop(a,e1);
	Push(c,e1);	
}
void hanoi(int n,SqStack *a,SqStack *b,SqStack *c)
{ 
	if(n==1)
	move(a,1,c);
	else
	{
	hanoi(n-1,a,c,b); 	//��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��������
	move(a,n,c); 		//�����Ϊn��Բ�̴�x�Ƶ�z
	hanoi(n-1,b,a,c); 	//��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z��x��������
	}
	
}

void list3()
{	system("cls");
	SqStack *a,*b,*c;
	InitStack(a);
	InitStack(b);
	InitStack(c);
	a->name='X';
	b->name='Y';
	c->name='Z';
	int n;
	printf("3������ΪX��Y��Z��Բ�������X������Y�Ƶ�Z�������������ģn��");
	scanf("%d",&n);
	for(int i=n;i>0;i--)
		Push(a,i);
	hanoi(n,a,b,c);
	free(a);
	free(b);
	free(c);
	system("pause");
}
