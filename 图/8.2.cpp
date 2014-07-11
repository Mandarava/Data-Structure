#include<stdio.h>
#include<malloc.h>
#include"graph.h"
int visited[MAXV];						
void DFS(ALGraph *G,int v) 
{
	ArcNode *p;
	visited[v]=1;                   
	printf("%d",v); 					
	p=G->adjlist[v].firstarc;      	
	while (p!=NULL) 
	{	
		if (visited[p->adjvex]==0)		
			DFS(G,p->adjvex);    
		p=p->nextarc;              	
	}
}


void BFS(ALGraph *G,int v)  
{
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;			
	int visited[MAXV];            			
	int w,i;
	for (i=0;i<G->n;i++) visited[i]=0;		
	printf("%d",v); 						
	visited[v]=1;              				
	rear=(rear+1)%MAXV;
	queue[rear]=v;             				
	while (front!=rear)       				
	{	
		front=(front+1)%MAXV;
		w=queue[front];       				
		p=G->adjlist[w].firstarc; 			
		while (p!=NULL) 
		{	
			if (visited[p->adjvex]==0) 		
			{	
				printf("%d",p->adjvex);  	
				visited[p->adjvex]=1;		
				rear=(rear+1)%MAXV;			
				queue[rear]=p->adjvex; 		
           	}
           	p=p->nextarc;              	
		}
	}
	printf("\n");
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

void main()
{
	int i,j;
	MGraph g;
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
	G=(ALGraph *)malloc(sizeof(ALGraph));
	MatToList1(g,G);					
	printf("从顶点0开始的DFS:\n");
	DFS(G,0);printf("\n");
	printf("从顶点0开始的BFS:\n");
	BFS(G,0);printf("\n");
}
