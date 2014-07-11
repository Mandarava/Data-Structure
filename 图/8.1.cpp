#include <stdio.h>
#include <malloc.h>
#include "graph.h"
void MatToList(MGraph g,ALGraph *&G)
{
	int i,j;
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<g.n;i++)				
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)				
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0)		
			{   
			   	p=(ArcNode *)malloc(sizeof(ArcNode));	
				p->adjvex=j;
				p->nextarc=G->adjlist[i].firstarc;		
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;
	G->e=g.e;
}
void ListToMat(ALGraph *G,MGraph &g)
{
	int i,j;
	ArcNode *p;
	for (i=0;i<G->n;i++)      	
	   	for (j=0;j<G->n;j++)
			g.edges[i][j]=0;
	for (i=0;i<G->n;i++) 
	{	
		p=G->adjlist[i].firstarc;
	    while (p!=NULL) 
		{	
			g.edges[i][p->adjvex]=1;
		    p=p->nextarc;
		}
	}
	g.n=G->n;
	g.e=G->e;
}
void DispMat(MGraph g)		
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj(ALGraph *G)	
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}

void MatToList1(MGraph g,ALGraph *&G)
{
	int i,j;
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<g.n;i++)				
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)				
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)
			{   
			   	p=(ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->info=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;		
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}
void ListToMat1(ALGraph *G,MGraph &g)
{
	int i,j;
	ArcNode *p;
	for (i=0;i<G->n;i++)      
	   	for (j=0;j<G->n;j++)
			if (i==j)
				g.edges[i][j]=0;
			else
				g.edges[i][j]=INF;
	for (i=0;i<G->n;i++) 
	{	
		p=G->adjlist[i].firstarc;
	    while (p!=NULL) 
		{	
			g.edges[i][p->adjvex]=p->info;
		    p=p->nextarc;
		}
	}
	g.n=G->n;g.e=G->e;
}
void DispMat1(MGraph g)
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("%3s","∞");
			else
				printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj1(ALGraph *G)
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d %d",p->adjvex,p->info);
			p=p->nextarc;
		}
		printf("\n");
	}
}

void main()
{
	int i,j;
	MGraph g,g1;
	ALGraph *G;
	int A[MAXV][6]={
		{0,5,INF,7,INF,INF},
		{INF,0,4,INF,INF,INF},
		{8,INF,0,INF,INF,9},
		{INF,INF,5,0,INF,6},
		{INF,INF,INF,5,0,INF},
		{3,INF,INF,INF,1,0}};
	g.n=6;g.e=10;			
	for (i=0;i<g.n;i++)	
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	printf("有向图G的邻接矩阵:\n");
	DispMat1(g);
	G=(ALGraph *)malloc(sizeof(ALGraph));
	printf("图G的邻接矩阵转换成邻接表:\n");
	MatToList1(g,G);
	DispAdj1(G);
	printf("图G的邻接表转换成邻接邻阵:\n");
	ListToMat1(G,g1);
	DispMat1(g1);
} 
