#include <string.h>
#include <stdio.h>
#define max 1024

void StrDelete(char *s,int i,int m)
{	int j=0,k=0,n;
	char s1[max],s2[max];

	if (i>strlen(s))
		printf("Not do\n");
	else
	{       k=strlen(s);
		for(j=i-1,n=1;n<=(k-i-m+1);j++,n++)
			s[j]=s[m+j];
		s[k-m]='\0';
	}
}


void main()
{
	char s[max];
	int i,m;
	printf("Input s:");
	gets(s);
	printf("Input delete location and length:");
	scanf("%d%d",&i,&m);
	StrDelete(s,i,m);
	printf("%s",s);
}