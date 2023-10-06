#ifndef MGRAGH_H
#define MGRAGH_H
#define MaxVertexNum 100
#define vexValue int

bool visited[MaxVertexNum]={false};
typedef struct MGragh{
	int vexList[MaxVertexNum];//the value of vertex
	int arcMatrix[MaxVertexNum][MaxVertexNum];//the value of arcs
	int vexNum;
	int arcNum;
}MGragh;

typedef enum mapKind{DM,UDM,DN,UDN}mapKind;
/*
  DM Directed Map
  UDM UnDirected Map
  DN Directed Net with weight
  UDN UnDirected Net with weight
 */

typedef struct VertexType{
	vexValue value;
	//other info
}Vertex,VexList[MaxVertexNum];

typedef struct ArcPoint{
	int weight;
}Arc,ArcMatrix[MaxVertexNum][MaxVertexNum];


typedef struct Gragh{
	VexList vexlist;
	ArcMatrix arcmatrix;
	int vexsNum;
	int arcsNum;
	mapKind kind;
}Gragh;

void CreateMGragh(int data[],int num,int arcs[][MaxVertexNum],MGragh &mg);
void showMG(MGragh mg);

void MGraghTest();
#endif
