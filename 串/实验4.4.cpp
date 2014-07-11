#include<stdio.h>
#include<string.h>
#define MaxSize 100
typedef struct
{	char data[MaxSize];
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
SqString A,B;

SqString EnCrypt(SqString p)
{ 	int i=0,j;
	SqString q;
	while(i<p.length)
	{ for(j=0;p.data[i]!=A.data[j];j++);
	if(j>=A.length)      
	q.data[i]=p.data[i];
	else                    
	q.data[i]=B.data[j];
	i++;
	}
	q.length=p.length;
	return q;
}
SqString UnEncrypt(SqString q)
{
 	int i=0,j;
 	SqString p;
 		while(i<q.length)
 	{ for(j=0;q.data[i]!=B.data[j];j++);
 	if(j>=B.length)
 	 p.data[i]=q.data[i];
 	else      
    	p.data[i]=A.data[j];
	 i++;
 	}
	 p.length=q.length;
 	return p;
}
void main()
{
	SqString p,q;
	int ok=1;
	StrAssign(A,"a b c d e f g h i j k l m n o p q r s t u v w x y z");
	StrAssign(B,"n g z q t c o b m u h e l k p d a w x f y i v r s j");
	char str[MaxSize];
	printf("\n");
	printf("输入原文串：");
	gets(str);
	StrAssign(p,str);
	printf("加密解密如下:\n");
	printf("原文串：");DispStr(p);
	q=EnCrypt(p);
	printf("加密串:");DispStr(q); 
	p=UnEncrypt(q);
	printf("解密串：");DispStr(p);
	printf("\n");
}
