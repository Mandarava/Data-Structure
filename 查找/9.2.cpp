#include <stdio.h>
#define MAXL 100					
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{	
	KeyType key;                	
    InfoType data;              	
} NodeType;
typedef NodeType SeqList[MAXL];				
int BinSearch(SeqList R,int n,KeyType k)
{
	int low=0,high=n-1,mid,count=1;
	while (low<=high) 
	{	
		mid=(low+high)/2;
		printf("第%d次：在第%d~%d个元素中查找\n",count++,low,high);
			if (R[mid].key==k)   	
			return mid;
		if (R[mid].key>k)     
			high=mid-1;
		else
			low=mid+1;       
	}
	return -1;
}
void main()
{
	SeqList R;
	KeyType k=9;
	int a[]={1,2,3,4,5,6,7,8,9,10},i,n=10;
	for (i=0;i<n;i++)				
		R[i].key=a[i];
	printf("关键字如下:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
	printf("查找过程如下:\n");
	if ((i=BinSearch(R,n,k))!=-1)
		printf("元素%d的位置是第%d个\n",k,i);
	else
		printf("查无此字\n");
}
