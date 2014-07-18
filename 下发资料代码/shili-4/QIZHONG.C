#include <stdio.h>
#include <string.h>

void delete(char a[],char ch)
{	int i,j;
	int len;
	len=strlen(a);
	printf("len=%5d\n",len);
	for (i=0;a[i]!='\0';i++)
		if (a[i]==ch)
		{	for (j=i+1;a[j]!='\0';j++)
				a[j-1]=a[j];
			a[j-1]='\0';
			len--;
		}
	printf("len=%5d\n",len);
}

main()
{	char a[]="abcdabcdabcd";
	char ch;
	int i;
	printf("\ninput the delete element:");
	scanf("%c",&ch);
	delete(a,ch);
	for (i=0;a[i]!='\0';i++)
		printf("%c",a[i]);
}