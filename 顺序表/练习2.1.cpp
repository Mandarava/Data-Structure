#include<stdio.h>
void deleteXY()
{
	int count = 0;
	int i;
	int x,y;
	int data[10]={0};
	printf("������10��x��y֮�������\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&data[i]);
	}
	printf("������Ԫ�ص��Ͻ�y���½�x\n");
	scanf("%d",&x); 
	scanf("%d",&y);
	printf("����ɾ��Ԫ���д��ڵ���%dС�ڵ���%d������...",y,x);
	for (int i = 0; i < 10; i++)
	{
		if (data[i] >= y&& data[i] <= x)
		{
			data[i] = 999;	
		}
	}
	printf("���\n");
	printf("�µ�Ԫ��Ϊ��\n");
	for (int i = 0; i < 10; i++)
	{
		if (data[i] != 999)	
		{
			printf("%d",data[i]); 
		}
		else
		{
			count = count + 1;
		}
	}
	if (count == 10)
	{
		printf("�ձ�") ;	
	}
	printf("\n");	
	
}
int main()
{
	deleteXY();
}
