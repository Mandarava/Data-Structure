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
	 	printf("\t��������\n");
		printf("\t1:ֱ�Ӳ�������\n");
		printf("\t2:ֱ��ѡ������\n");
		printf("\t3:ð������Ľ���\n");
		printf("\t0:�˳�\n");
		printf("\t��ѡ��0--3:\n");

		while((status=scanf("%d",&i))!=1||(i>3||i<0))
		{
			if(status!=1)
				scanf("%*s");
			printf("������0-3������\n");
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
