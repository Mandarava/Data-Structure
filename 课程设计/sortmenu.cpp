#include "insertsort.cpp"
#include "selectsort.cpp"
#include "bubblesort1.cpp" 
#include<stdio.h>
#include<stdlib.h> 
void list1()
{	
	int i,flag=1,status;
	while (flag)
	{
		system("cls");
	 	printf("\t各种排序\n");
		printf("\t1:直接插入排序\n");
		printf("\t2:直接选择排序\n");
		printf("\t3:冒泡排序改进版\n");
		printf("\t0:退出\n");
		printf("\t请选择0--3:\n");

		while((status=scanf("%d",&i))!=1||(i>3||i<0))
		{
			if(status!=1)
				scanf("%*s");
			printf("请输入0-3的整数\n");
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
