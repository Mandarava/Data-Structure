#include<stdio.h>
#include<string.h>
#define Maxsize 100

int strIndex_BF(char *s,char *t)
{	int i=1,j=1;
	while(i<=s[0]&&j<=t[0])
		if(s[i]==t[j])
		{	i++;j++;}
		else
		{	i=i-j+2;j=1;}
	if(j>t[0])
		return(i-t[0]);
	else 	return 0;
}

void main()
{	int i,j=0,result;
	char s[Maxsize],t[Maxsize];

	printf("Please input string s:");
	for(i=1;(s[i]=getchar())!='\n';j++,i++);
	s[0]=j;
	j=0;
	printf("please input string t:");
	for(i=1;(t[i]=getchar())!='\n';j++,i++);
	t[0]=j;
	result=strIndex_BF(s,t);
	printf("Result=%d",result);
}

