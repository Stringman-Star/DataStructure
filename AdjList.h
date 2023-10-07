#ifndef ADJLIST_H
#define ADJLIST_H
#define MaxVertexNum 100
#include "MGragh.h"
#define empty 0
typedef enum mapKind{DM,UDM,DN,UDN}mapKind;

//struct
typedef struct ArcNode{
	int adjVex;
	int weight;
	struct ArcNode *next;
}ArcNode;
typedef struct VNode{
	int data;
	ArcNode* fisrt;
}VNode,AdjList[MaxVertexNum];//不是指针是数组

typedef struct ALGragh{
	AdjList adjlist;
	int vexNum;
	int arcNum;
	mapKind mk;
}ALGragh;

//function
void CreateAdjList(int data[],int num,int arcs[][MaxVertexNum],AdjList &adj);
void showAdj(AdjList adj,int num);
int FirstAdjVex(AdjList adj,int u);
int NextAdjVex(AdjList adj,int u,int w);
void BFSTraverse(AdjList adj,int num);
void DFSTraverse(AdjList adj,int num);
void convertAdj(AdjList adj,AdjList inadj,int num);
int delArc(AdjList adj,int head,int tail);
bool isConnected(AdjList adj,int num);
void AdjListTest();
#endif
