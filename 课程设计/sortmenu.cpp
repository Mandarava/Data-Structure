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
	 L1:printf("\t��������\n");
		printf("\t1:ֱ�Ӳ�������\n");
		printf("\t2:ֱ��ѡ������\n");
		printf("\t3:ð������Ľ���\n");
		printf("\t0:�˳�\n");
		printf("\t��ѡ��0--3:\n");
		while (true)
		{
			scanf("%d",&i);
			if (i>=0 && i<=3)
				break;
			else
				printf("�������");
				printf("��ѡ��0--3:\n");
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
