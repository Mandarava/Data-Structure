#include "insertsort.cpp"
#include "selectsort.cpp"
#include "bubblesort1.cpp" 
#include<stdio.h>
#include<stdlib.h> 
void list1()
{	
	int i,flag=1;
	while (flag)
	{
		system("cls");
	 L1:printf("\t各种排序\n");
		printf("\t1:直接插入排序\n");
		printf("\t2:直接选择排序\n");
		printf("\t3:冒泡排序改进版\n");
		printf("\t0:退出\n");
		printf("\t请选择0--3:\n");
		while (true)
		{
			scanf("%d",&i);
			if (i>=0 && i<=3)
				break;
			else
				printf("输入错误，");
				printf("请选择0--3:\n");
		}
		switch (i)
		{
		case 1:{main1();break;}
		case 2:{main2();break;}
		case 3:{main3();break;}
		case 0:{flag=0;break;}
		}
	}
}
