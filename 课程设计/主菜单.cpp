#include "sortmenu.cpp"
#include "二叉树的遍历.cpp"
#include "hanoi.cpp"
#include<stdlib.h> 
void main()
{
	int i,status;
	while (1)
	{	
		system("cls");
		printf("\n\t数据结构课程设计\n");
		printf("\t1:二叉树的遍历\n");
		printf("\t2:各种排序\n");
		printf("\t3:汉诺塔问题\n");
		printf("\t0:退出\n");
		printf("\t请选择0--3:\n");
//		while (1)
//		{
//			scanf("%d",&i);
//			if (i>=0 && i<=3)
//				break;
//		}
	while((status=scanf("%d",&i))!=1||(i>3||i<0))
	{
		if(status!=1)				//判断是否为字符 
			scanf("%*s");			//跳至下一个空白符 清除输入缓冲区中的非法输入
			printf("请输入0-3的数字\n");
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
