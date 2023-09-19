#ifndef MGRAGH_H
#define MGRAGH_H
#define MaxVertexNum 100
typedef struct MGragh{
	int vexList[MaxVertexNum];//the value of vertex
	int arcMatrix[MaxVertexNum][MaxVertexNum];//the value of arcs
	int vexNum;
	int arcNum;
}MGragh;
void CreateMGragh(int data[],int num,int arcs[][MaxVertexNum],MGragh &mg);
void showMG(MGragh mg);

void MGraghTest();
#endif
