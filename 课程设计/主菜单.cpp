#include "sortmenu.cpp"
#include "二叉树的遍历.cpp"
#include "hanoi.cpp"
#include<stdlib.h> 
void main()
{
	int i;
	while (1)
	{	
		system("cls");
		printf("\n\t数据结构课程设计\n");
		printf("\t1:二叉树的遍历\n");
		printf("\t2:各种排序\n");
		printf("\t3:汉诺塔问题\n");
		printf("\t0:退出\n");
		printf("\t请选择0--3:\n");
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
