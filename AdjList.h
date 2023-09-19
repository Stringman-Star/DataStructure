#ifndef ADJLIST_H
#define ADJLIST_H
#define MaxVertexNum 100
#include "MGragh.h"

//struct
typedef struct ArcNode{
	int adjVex;
	struct ArcNode *next;
}ArcNode;
typedef struct VNode{
	int data;
	ArcNode* fisrt;
}VNode,AdjList[MaxVertexNum];//不是指针是数组

//function
void CreateAdjList(int data[],int num,int arcs[][MaxVertexNum],AdjList &adj);
void showAdj(AdjList adj,int num);
int FirstAdjVex(AdjList adj,int u);
int NextAdjVex(AdjList adj,int u,int w);
void BFSTraverse(AdjList adj,int num);
void DFSTraverse(AdjList adj,int num);
void convertAdj(AdjList adj,AdjList inadj,int num);
void Adj2Mg(AdjList adj,MGragh *mg,int num);
int delArc(AdjList adj,int head,int tail);
bool isConnected(AdjList adj,int num);
void AdjListTest();
#endif
