#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
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
bool Push(SqStack *&s,ElemType e)  //进栈 
{
	if(s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return 1;
}
bool Pop(SqStack *&s,ElemType &e) //出栈 
{
	if(s->top==-1)
	return 0;
	e=s->data[s->top];
	s->top--;
	return 1;
}
bool GetTop(SqStack *s,ElemType &e)   //取栈顶元素 
{
	if(s->top==-1)
	return 0;
	e=s->data[s->top];
	return 1;
}
int StackLength(SqStack *s)  
{
  return(s->top+1);
}
void DispStack(SqStack *s)
{  
	int i;  
	for(i=s->top;i>=0;i--) 
	printf("%c",s->data[i]); 
	printf("\n"); 
}

void main()
{
	ElemType e;
	SqStack *s;
	printf("栈s的基本运算如下:\n");
	printf("  (1)初始化栈s\n");
	InitStack(s);
	printf("  (2)栈为%s\n",(StackEmpty(s)?"空":"非空"));
	printf("  (3)依次进栈元素a,b,c,d,e\n");
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	printf("  (4)栈为%s\n",(StackEmpty(s)?"空":"非空"));
	printf("  (5)栈的长度=%d\n",StackLength(s));  
	printf("  (6)输出从栈顶到栈底元素:");
	DispStack(s);  
	printf("  (7)出栈序列：");
	while (!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c",e);
	}
	printf("\n");
	printf("  (8)栈为%s\n",(StackEmpty(s)?"空":"非空"));
	printf("  (9)释放栈\n");
	DestroyStack(s);
}
