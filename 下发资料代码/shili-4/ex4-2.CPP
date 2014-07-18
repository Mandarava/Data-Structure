#include <string.h>
#include <stdio.h>
#define max 1024

void StrDelete(char *s,int i,int m)
{	int j=0,k=0;
	char s1[max],s2[max];

	if (i>strlen(s))
		printf("Not do\n");
	else
	{	for(j=0;j<i-1;j++)
			s1[j]=s[j];
		s1[j]='\0';
		for(j=i+m-1,k=0;j<strlen(s);j++)
			s2[k++]=s[j];
		s2[k]='\0';
		strcat(s1,s2);
		strcpy(s,s1);
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