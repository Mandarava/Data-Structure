#include <stdio.h>
#define MaxSize 100
#include<stdlib.h> 
typedef int KeyType;  	/*����ؼ�������*/
typedef char InfoType[10];
typedef struct       	/*��¼����*/
{
	KeyType key;   		/*�ؼ�����*/
	InfoType data; 		/*����������,����ΪInfoType*/
} RecType2;				/*����ļ�¼���Ͷ���*/

void InsertSort(RecType2 R[],int n) /*��R[0..n-1]�������������ֱ�Ӳ�������*/
{
	int i,j,k;
	RecType2 tmp;
	for (i=1;i<n;i++) 
	{
		tmp=R[i];
		j=i-1;            /*����������������R[0..i-1]����R[i]�Ĳ���λ��*/
		while (j>=0 && tmp.key<R[j].key) 
		{
			R[j+1]=R[j]; /*���ؼ��ִ���R[i].key�ļ�¼����*/
			j--;
		}
		R[j+1]=tmp;      /*��j+1������R[i]*/
		printf("i=%d: ",i);
		for (k=0;k<n;k++)
			printf("%d ",R[k].key);
		printf("\n");
	}
}
void main1()
{	system("cls");
	int i,n;
	int a[1000]; 
	RecType2 R[MaxSize];
	printf("Ҫ������ٸ�����");
	scanf("%d",&n);
	printf("����Ҫ���������\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]); 
//	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("����ǰ:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
	InsertSort(R,n);
	printf("�����:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
	system("pause");
}


