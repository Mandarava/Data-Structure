#include<stdio.h>
#define L 10
void conversion(int N,int r)
{
	int s[L],top;
	int x;
	top=-1;
	while(N)
	{	s[++top]=N%r;
		N=N/r;
	}
	while(top!=-1)
	{
		x=s[top--];
		printf("%d",x);
	}
}
void main()
{
	int N,r;
	printf("Please input N & r:");
	scanf("%d%d",&N,&r);
	conversion(N,r);
}
