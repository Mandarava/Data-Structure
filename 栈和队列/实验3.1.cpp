#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
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
bool Push(SqStack *&s,ElemType e)  //��ջ 
{
	if(s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return 1;
}
bool Pop(SqStack *&s,ElemType &e) //��ջ 
{
	if(s->top==-1)
	return 0;
	e=s->data[s->top];
	s->top--;
	return 1;
}
bool GetTop(SqStack *s,ElemType &e)   //ȡջ��Ԫ�� 
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
	printf("ջs�Ļ�����������:\n");
	printf("  (1)��ʼ��ջs\n");
	InitStack(s);
	printf("  (2)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("  (3)���ν�ջԪ��a,b,c,d,e\n");
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	printf("  (4)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("  (5)ջ�ĳ���=%d\n",StackLength(s));  
	printf("  (6)�����ջ����ջ��Ԫ��:");
	DispStack(s);  
	printf("  (7)��ջ���У�");
	while (!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c",e);
	}
	printf("\n");
	printf("  (8)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("  (9)�ͷ�ջ\n");
	DestroyStack(s);
}
