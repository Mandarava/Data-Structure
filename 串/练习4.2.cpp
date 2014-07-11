#include<stdio.h>
#include<string.h> 
#define Maxsize 100
typedef struct
{	char data[Maxsize];
	int length;
}SqString;
void StrAssign(SqString &s,char cstr[])
{	int i;
	for(i=0;cstr[i]!='\0';i++)
	s.data[i]=cstr[i];
	s.length=i;
}
void DispStr(SqString s)
{	int i;
	if(s.length>0)
	{	for(i=0;i<s.length;i++)
			printf("%c",s.data[i]);
		printf("\n");
	}
}
SqString CommChar(SqString s1,SqString s2)
{	SqString s3;
	int i,j,k=0;
	for(i=0;i<s1.length;i++)
	{
		for(j=0;j<s2.length;j++)
		{	if(s2.data[j]==s1.data[i])
			{	
				break;
			} 
		} 
			if(j<s2.length)
			{
				s3.data[k]=s1.data[i];
				k++;
			}
	}
	s3.length=k;
	return s3;
}
int main()
{	SqString s1,s2,s3;
	StrAssign(s1,"abcdefghijklmn");
	StrAssign(s2,"acdfg12345");
	printf("´®s1£º");
	DispStr(s1);
	printf("´®s2£º"); 
	DispStr(s2);
	printf("¹«¹²´®s3£º"); 
	s3=CommChar(s1,s2);	 
	DispStr(s3);

}
