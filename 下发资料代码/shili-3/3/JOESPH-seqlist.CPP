#include<stdio.h>
typedef int maxix[400];
void main()
{	maxix a;
	int count,d,i,m,n;
	do
	{	printf("input n and m:");
		scanf("%d%d",&n,&m);
	}while(n<=m);
	for(i=0;i<n;i++)
		a[i]=i+1;
	count=0;d=0;
	while(d<n)
		for(i=0;i<n;i++)
			if (a[i]!=0)
			{	count++;
				if (count==m)
				{	printf("%d\t",a[i]);
					a[i]=0;
					count=0;
					d++;
				}
			}
}
