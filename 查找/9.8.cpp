#include <stdio.h>
#include <stdafx.h>
#include <windows.h>
#define MaxSize 100			
#define NULLKEY -1			
typedef int KeyType;		
typedef char *InfoType;	
typedef struct
{
	KeyType key;			
	InfoType data;			
	int count;				
} HashTable[MaxSize]	;	

void InsertHT(HashTable ha,int &n,KeyType k,int p)  //���ؼ���k���뵽��ϣ����
{
	int i,adr;
	adr=k % p;
	if (ha[adr].key==NULLKEY)	
	{
		ha[adr].key=k;
		ha[adr].count=1;
	}
	else					
	{
		i=1;			
		do 
		{
			adr=(adr+1) % p;
			i++;
		} while (ha[adr].key!=NULLKEY);
		ha[adr].key=k;
		ha[adr].count=i;
	}
	n++;
}
void CreateHT(HashTable ha,KeyType x[],int n,int m,int p)  //������ϣ��
{
	int i,n1=0;
	for (i=0;i<m;i++)			
    {
        ha[i].key=NULLKEY;
	    ha[i].count=0;
    }
	for (i=0;i<n;i++)
		InsertHT(ha,n1,x[i],p);
}
int SearchHT(HashTable ha,int p,KeyType k)		//�ڹ�ϣ�� �в��ҹؼ���k
{
	int i=0,adr;
	adr=k % p;
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
	{
		i++;				
		adr=(adr+1) % p;
	}
	if (ha[adr].key==k)		
		return adr;
	else				
		return -1;
}

void DispHT(HashTable ha,int n,int m)    //�����ϣ��
{
	float avg=0;
	int i;
	printf("��ϣ���ַ:\t");
	for (i=0;i<m;i++) 
		printf(" %3d",i);
	printf(" \n");
    printf("��ϣ��ؼ���:\t");
	for (i=0;i<m;i++) 
		if (ha[i].key==NULLKEY)
			printf("    ");			
		else
			printf(" %3d",ha[i].key);
	printf("\n");
	printf("��������:\t");
	for (i=0;i<m;i++)
		if (ha[i].key==NULLKEY)
			printf("    ");			
		else
			printf("%3d",ha[i].count);
	printf(" \n");

}
void main()
{
	int x[]={16,74,60,43,54,90,46,31,29,88,77};
	int n=11,m=13,p=13,i,k=29;
	HashTable ha;
	CreateHT(ha,x,n,m,p);
	DispHT(ha,n,m);
	i=SearchHT(ha,p,k);
	if (i!=-1)
		printf(" ha[%d].key=%d\n",i,k);
	else
		printf(" ��ʾ:δ�ҵ�%d\n",k);
	
	system("pause");
}