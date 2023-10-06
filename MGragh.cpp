#include <stdio.h>
#include <stdlib.h>
#include"MGragh.h"

void CreateMGragh(int data[],int num,int arcs[][MaxVertexNum],MGragh &mg){
	mg.vexNum=num;
	mg.arcNum=0;
	for(int i=0;i<num;i++){
		//TODO
		mg.vexList[i]=data[i];
		for(int j=0;j<=num;j++){
			//TODO
			mg.arcMatrix[i][j]=arcs[i][j];
			mg.arcNum++;
		}
	}
}

void showMG(MGragh mg){
	for(int i=0;i<mg.vexNum;i++){
		//TODO
		printf("data%d:     ",mg.vexList[i]);
		for(int j=0;j<mg.vexNum;j++){
			//TODO
			printf("%d ",mg.arcMatrix[i][j]);
		}
		putchar('\n');
	}
}
void DFS(VertexType vertex){
	if(visited[vertex]==false){
		//TODO
	}
};

void DFSTranvers(MGragh mg){
	for(int i=0;i<mg.vexNum;i++){
		//TODO
		
		
	}
}

void MGraghTest(){
	//TODO
}
