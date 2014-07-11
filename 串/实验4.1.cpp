#include<stdio.h>
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
void StrCopy(SqString &s,SqString t)
{	int i;
	for(i=0;i<t.length;i++)
		s.data[i]=t.data[i];
	s.length=t.length;
}
bool StrEqual(SqString s,SqString t)
{	bool same=true;
	int i;
	if(s.length!=t.length)
		same=false;
	else
		for(i=0;i<s.length;i++)
			if(s.data[i]!=t.data[i]) 
			{	same=false;
				break;
			}
		return same;
}
int StrLength(SqString s)
{
	return s.length;
}
SqString Concat(SqString s,SqString t)
{
	SqString str;
	int i;
	str.length=s.length+t.length;
	for(i=0;i<s.length;i++)
		str.data[i]=s.data[i];
	for(i=0;i<t.length;i++)
		str.data[s.length+i]=t.data[i];
	return str;
}
SqString SubStr(SqString s,int i,int j)
{	SqString str;
	int k;
	str.length=0;
	if(i<=0||i>s.length||j<0||i+j-1>s.length)
		return str;
	for(k=i-1;k<i+j-1;k++)
		str.data[k-i+1]=s.data[k];
		str.length=j;
		return str;
}
SqString InsStr(SqString s1,int i,SqString s2)
{	int j;
	SqString str;
	str.length=0;
	if(i<=0||i>s1.length+1)
		return str;
	for(j=0;j<i-1;j++)
		str.data[j]=s1.data[j];
	for(j=0;j<s2.length;j++)
		str.data[i+j-1]=s2.data[j];
	for(j=i-1;j<s1.length;j++)
		str.data[s2.length+j]=s1.data[j];
	str.length=s1.length+s2.length;
	return str;
}
SqString DelStr(SqString s,int i,int j)
{	int k;
	SqString str;
	str.length=0;
	if(i<=0||i>s.length||i+j>s.length+1)
		return str;
	for(k=0;k<i-1;k++)
		str.data[k]=s.data[k];
	for(k=i+j-1;k<s.length;k++)
		str.data[k-j]=s.data[k];
	str.length=s.length-j;
	return str;
}
SqString RepStr(SqString s,int i,int j,SqString t)
{
	int k;
	SqString str;
	str.length=0;
	if(i<=0||i>s.length||i+j-1>s.length)
		return str;
	for(k=0;k<i-1;k++)
		str.data[k]=s.data[k];
	for(k=0;k<t.length;k++)
		str.data[i+k-1]=t.data[k];
	for(k=i+j-1;k<s.length;k++)
		str.data[t.length+k-j]=s.data[k];
	str.length=s.length-j+t.length;
	return str;
}
void DispStr(SqString s)
{	int i;
	if(s.length>0)
	{	for(i=0;i<s.length;i++)
			printf("%c",s.data[i]);
		printf("\n");
	}
}
void main()
{	SqString s,s1,s2,s3,s4;
	printf("顺序串的基本运算如下:\n");
	printf("   (1)建立串S和串S1\n");
	StrAssign(s,"abcdefghefghijklmn");
	StrAssign(s1,"xyz");
	printf("   (2)输出串s：");DispStr(s);
	printf("   (3)串S的长度:%d\n",StrLength(s));
	printf("   (4)在串S的第9个字符位置插入串S1而产生串S2\n");
	s2=InsStr(s,9,s1);
	printf("   (5)输出串s2:");DispStr(s2);
	printf("   (6)删除串s第2个字符开始的5个字符而产生串S2\n");
	s2=DelStr(s,2,5);
	printf("   (7)输出串S2：");DispStr(s2);
	printf("   (8)将串S第2个字符开始的5个字符替换成串s1而产生串s2\n");
	s2=RepStr(s,2,5,s1);
	printf("   (9)输出串S2：");DispStr(s2);
	printf("   (10)提取串S的第二个字符开始的10个字符而产生串s3\n");
	s3=SubStr(s,2,10);
	printf("   (11)输出串S3：");DispStr(s3);
	printf("   (12)将串s1和串s2连接起来而产生串S4\n");
	s4=Concat(s1,s2);
	printf("   (13)输出串S4：");DispStr(s4);
}
