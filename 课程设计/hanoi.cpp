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
void InitStack(SqStack *&s)        //初始化栈 
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
void DestroyStack(SqStack *&s)     //销毁栈 
{
	free(s);
}
bool StackEmpty(SqStack *s)        //判断栈是否为空 
{
	return(s->top==-1);
}
int Push(SqStack *&s,ElemType e)  //进栈 
{
	if(s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return 1;
}
int Pop(SqStack *&s,ElemType &e) //出栈 
{
	if(s->top==-1)
	return 0;
	e=s->data[s->top];
	s->top--;
	return 1;
}
int GetTop(SqStack *s,ElemType &e)   //取栈顶元素 
{
	if(s->top==-1)
	return 0;
	e=s->data[s->top];
	return 1;
}
 
void move(SqStack *a,int n,SqStack *c)
{ 	ElemType e1;
	printf("将%d号盘从%c移到%c\n",a->data[a->top],a->name,c->name);
	Pop(a,e1);
	Push(c,e1);	
}
void hanoi(int n,SqStack *a,SqStack *b,SqStack *c)
{ 
	if(n==1)
	move(a,1,c);
	else
	{
	hanoi(n-1,a,c,b); 	//将x上编号为1至n-1的圆盘移到y，z作辅助塔
	move(a,n,c); 		//将编号为n的圆盘从x移到z
	hanoi(n-1,b,a,c); 	//将y上编号为1至n-1的圆盘移到z，x作辅助塔
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
	printf("3个塔座为X、Y、Z，圆盘最初在X，借助Y移到Z。请输入问题规模n：");
	scanf("%d",&n);
	for(int i=n;i>0;i--)
		Push(a,i);
	hanoi(n,a,b,c);
	free(a);
	free(b);
	free(c);
	system("pause");
}
