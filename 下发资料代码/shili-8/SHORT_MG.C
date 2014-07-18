/*图中一个源点到其它各点的最短路径*/
#include "stdio.h"
#include "alloc.h"
#define vextype int
#define adjtype int
#define maxlen 40
#define max 10000
typedef struct
{	vextype vexs[maxlen];
	adjtype arcs[maxlen][maxlen];
	int vexnum,arcnum;
	int kind;
}mgraph;

mgraph creat_mg()
{	int i,j,k,h;
	char b,t;
	mgraph mg;
	mg.kind=3;
	printf("input vex and arc:");
	scanf("%d,%d",&i,&j);
	mg.vexnum=i;		mg.arcnum=j;
	for (i=1;i<=mg.vexnum;i++)
	{	printf("number %d verinfo:",i);
		getchar();
		scanf("%d",&mg.vexs[i]);}
	for (i=1;i<=mg.vexnum;i++)
		for (j=1;j<=mg.vexnum;j++)
			mg.arcs[i][j]=max;
	for (k=1;k<=mg.arcnum;k++)
	{	printf("num %d adge:",k);
		scanf("%d,%d",&i,&j);
		while (i<1||i>mg.vexnum||j<1||j>mg.vexnum)
	  	{	printf("input error,repeat input:");
	  		scanf("%d,%d",&i,&j);}
		printf("the value is:");
		scanf("%d",&h);
		mg.arcs[i][j]=h;}
	return mg;
}

main()
{	int vexs[maxlen];
	int arcs[maxlen][maxlen];
	mgraph mg;
	int i,j,n,v0,min,u;
	int cost[maxlen][maxlen];
	int path[maxlen],s[maxlen];
	int dist[maxlen];
	mg=creat_mg();
	for(i=1;i<=mg.vexnum;i++)
	{	for (j=1;j<=mg.vexnum;j++)
			printf("%8d ",mg.arcs[i][j]);
		printf("\n");
	}
	printf("start ver number:");
	scanf("%d",&v0);
	n=mg.vexnum;
	for (i=1;i<=n;i++)
  	{	dist[i]=mg.arcs[v0][i];
   		if (dist[i]<max && dist[i]>0)
     			path[i]=v0;}
	for (i=1;i<=n;i++)
  		s[i]=0;
	s[v0]=1;
	for (i=1;i<n;i++)
  	{	min=max;
   		u=v0;
		for (j=1;j<=n;j++)
     			if (s[j]==0 && dist[j]<min)
        			{	min=dist[j];
         				u=j;}
    		s[u]=1;
		for (j=1;j<=n;j++)
    			 if (s[j]==0 && dist[u]+mg.arcs[u][j]<dist[j])
			{	dist[j]=dist[u]+mg.arcs[u][j];
				path[j]=u;}
   	}
	for (i=1;i<=n;i++)
		if (s[i]==1)
    		{	u=i;
			while (u!=v0)
			{	printf("%d<-   ",u);
        				u=path[u];
			}
			printf("%d   ",u);
     			printf("  d=%d    \n",dist[i]);
		}
  		else
			printf("%d<-   %d  d=x    \n",i,v0);
	printf("\n");
}
