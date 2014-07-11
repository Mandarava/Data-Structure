#include<stdio.h>
void deleteXY()
{
	int count = 0;
	int i;
	int x,y;
	int data[10]={0};
	printf("请输入10个x和y之间的整数\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&data[i]);
	}
	printf("请输入元素的上界y和下界x\n");
	scanf("%d",&x); 
	scanf("%d",&y);
	printf("正在删除元素中大于等于%d小于等于%d的数据...",y,x);
	for (int i = 0; i < 10; i++)
	{
		if (data[i] >= y&& data[i] <= x)
		{
			data[i] = 999;	
		}
	}
	printf("完毕\n");
	printf("新的元素为：\n");
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
		printf("空表") ;	
	}
	printf("\n");	
	
}
int main()
{
	deleteXY();
}
