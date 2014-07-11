#include <stdio.h>
#define MaxSize 100
#include<stdlib.h> 
typedef int KeyType;  	/*����ؼ�������*/
typedef char InfoType[10];
typedef struct       	/*��¼����*/
{
	KeyType key;   		/*�ؼ�����*/
	InfoType data; 		/*����������,����ΪInfoType*/
} RecType3;				/*����ļ�¼���Ͷ���*/
void SelectSort(RecType3 R[],int n)
{
	int i,j,k,l;
	RecType3 temp;
	for (i=0;i<n-1;i++)    	 	/*����i������*/
	{
		k=i;
		for (j=i+1;j<n;j++)  	/*�ڵ�ǰ������R[i..n-1]��ѡkey��С��R[k]*/
			if (R[j].key<R[k].key)
				k=j;           	/*k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��*/
			if (k!=i)          		/*����R[i]��R[k]*/
			{
				temp=R[i];
				R[i]=R[k];
				R[k]=temp;  
			}
		printf("i=%d: ",i);
		for (l=0;l<n;l++)
			printf("%d ",R[l].key);
		printf("\n");
	}
}
void main2()
{	system("cls");
	int i,n;
	int a[1000]; 
	RecType3 R[MaxSize];
	printf("Ҫ������ٸ�����");
	scanf("%d",&n);
	printf("����Ҫ���������\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]); 
//	KeyType a[]={6,8,7,9,0,1,3,2,4,5};
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("����ǰ:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
	SelectSort(R,n);
	printf("�����:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
	system("pause");
}


