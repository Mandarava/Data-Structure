#include <string.h>
#include <stdio.h>
#define max 1024
int LenS;
char s[max];

void StrInsert(char *s,char *t,int i)
{
	int j=0,k=0;
	char S1[max],S2[max];
	LenS=strlen(s);
	if(i>LenS)
		printf("Not do it\n");
	else
	{
		for(j=0;j<i-1;j++)
			S1[j]=s[j];
		S1[j]='\0';
		for(k=i-1;k<=LenS;k++)
			S2[k-i+1]=s[k];
		S2[k]='\0';
		strcat(S1,t);
		strcat(S1,S2);
		strcpy(s,S1);
	}
}

void main()
{
	char s[max],t[max];
	int i;
	printf("Input s:");
	gets(s);
	printf("Input t:");
	gets(t);
	printf("Input insert location i:");
	scanf("%d",&i);
	StrInsert(s,t,i);
	printf("%s",s);
}