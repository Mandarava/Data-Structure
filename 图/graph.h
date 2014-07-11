typedef int InfoType;
#define MAXV 6
#define INF 32767
typedef struct
{
	int no;
	InfoType info;
}VertexType;
typedef struct
{
	int edges[MAXV][MAXV];
	int n,e;
	VertexType vexs[MAXV];
}MGraph;
typedef struct ANode
{
	int adjvex;
	struct ANode *nextarc;
	InfoType info;
}ArcNode;
typedef int Vertex;
typedef struct Vnode
{
	Vertex data;
	ArcNode *firstarc;
}VNode;
typedef VNode AdjList[MAXV];
typedef struct
{
	AdjList adjlist;
	int n,e;
}ALGraph;
