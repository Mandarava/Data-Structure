#include "sortmenu.cpp"
#include "�������ı���.cpp"
#include "hanoi.cpp"
#include<stdlib.h> 
void main()
{
	int i;
	while (1)
	{	
		system("cls");
		printf("\n\t���ݽṹ�γ����\n");
		printf("\t1:�������ı���\n");
		printf("\t2:��������\n");
		printf("\t3:��ŵ������\n");
		printf("\t0:�˳�\n");
		printf("\t��ѡ��0--3:\n");
		while (1)
		{
			scanf("%d",&i);
			if (i>=0 && i<=3)
				break;
		}
		switch (i)
		{
		case 1:{list2();break;}
		case 2:{list1();break;}
		case 3:{list3();break;}
		case 0:{return 0;}
		}
	}
}
