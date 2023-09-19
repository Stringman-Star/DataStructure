#include <stdio.h>
#include <stdlib.h>
#include"Queue.h"
#include"AdjList.h"
#include"MGragh.h"

bool visited[MaxVertexNum]={false};
void visit(int v){
	visited[v]=true;
	printf("%d ",v);
}

void CreateAdjList(int data[],int num,int arcs[][MaxVertexNum],AdjList &adj){
	int flag;
	ArcNode *arcnode,*last;
	for(int i=0;i<num;i++){
		//TODO
		adj[i].data=data[i];
		flag=0;
		last=NULL;
		for(int j=0;j<num;j++){
			//TODO
			if(arcs[i][j]==0){
				//TODO
				continue;
			}
			arcnode=(ArcNode*)malloc(sizeof(ArcNode));
			arcnode->adjVex=j;
			arcnode->next=NULL;
			if(!flag){
				//TODO
				flag=1;
				adj[i].fisrt=arcnode;
			}else{
				last->next=arcnode;
			}
			last=arcnode;
		}
	}
}

/*
 *@param u vertex u
 */
int FirstAdjVex(AdjList adj,int u){
	ArcNode* flag=adj[u].fisrt;
	while(flag!=NULL){
		//TODO
		if(visited[flag->adjVex]==false){
			//TODO
			break;
		}else{
			flag=flag->next;
		}
	}
	return flag==NULL?-1:flag->adjVex;
}

/*
 *this method are onto searching next adjacent vertex of u except w
 *if none return -1
 * 
 *@param vertex u
 *@param an adjacent vertex of u
 */
int NextAdjVex(AdjList adj,int u,int w){
	ArcNode* temp=adj[u].fisrt;
	int flag=0;
	while(temp!=NULL){
		//TODO
		if(flag&&visited[temp->adjVex]==false){
			//TODO
			return temp->adjVex;
		}
		if(temp->adjVex==w){
			//TODO
			flag=1;
		}
		temp=temp->next;
	}
	return -1;
}
void showAdj(AdjList adj,int num){
	for(int i=0;i<num;i++){
		ArcNode* arcnode=adj[i].fisrt;
		printf("data%d:     ",adj[i].data);
		//TODO
		for(int j=0;j<num;j++){
			//TODO
			if(arcnode!=NULL&&j==arcnode->adjVex){
				//TODO
				putchar('1');
				putchar(' ');
				arcnode=arcnode->next;
			}else{
				putchar('0');
				putchar(' ');
			}
		}
		putchar('\n');
	}
}

/*
 *广度优先遍历一个连通分量
 */
void BFS(AdjList adj,int v){
	Queue queue;
	Queueinitial(&queue);
	visit(v);
	EnQueue(&queue,v);
	while(isEmpty(queue)==false){
		//TODO
		int u=DeQueue(&queue);
		for(int w=FirstAdjVex(adj,u);w>=0;w=NextAdjVex(adj,u,w)){
			//TODO
			visit(w);
			EnQueue(&queue,w);
		}
	}
}

/*
 *广度遍历一张图中的所有连通分量
 */
void BFSTraverse(AdjList adj,int num){
	for(int i=0;i<num;i++){
		//TODO
		if(visited[i]==false){
			//TODO
			BFS(adj,i);
		}
	}
}

void DFSAdj(AdjList adj,int v){
	visit(v);
	for(ArcNode* w=adj[v].fisrt;w!=NULL;w=w->next){
		//TODO
		if(!visited[w->adjVex]){
			//TODO
			DFSAdj(adj,w->adjVex);
		}
	}
}

/*
 *深度遍历一张图中的所有连通分量
 */
void DFSTraverse(AdjList adj,int num){
	int count=0;
	for(int v=0;v<num;v++){
		//TODO
		if(!(visited[v])){
			//TODO
			count++;
			DFSAdj(adj,v);
		}
	}
	printf("\ncount=%d",count);
}

/*
 *将adj有向邻接表转化为inadj逆邻接表
 */
void convertAdj(AdjList adj,AdjList inadj,int num){
	for(int i=0;i<num;i++){
		//TODO
		inadj[i].data=adj[i].data;
	}
	for(int i=0;i<num;i++){
		ArcNode* temp=NULL;
		//TODO
		for(ArcNode* j=adj[i].fisrt;j!=NULL;j=j->next){
			//TODO
			temp=(ArcNode*)malloc(sizeof(ArcNode));
			temp->adjVex=i;
			temp->next=inadj[j->adjVex].fisrt;
			inadj[j->adjVex].fisrt=temp;//head insert
		}
	}
}

void Adj2Mg(AdjList adj,MGragh *mg,int num){
	mg->vexNum=num;
	for(int i=0;i<num;i++){
		//TODO
		mg->vexList[i]=adj[i].data;
	}
	mg->arcNum=0;
	for(int i=0;i<num;i++){
		//TODO
		for(ArcNode* w=adj[i].fisrt;w!=NULL;w=w->next){
			//TODO
			mg->arcNum++;
			mg->arcMatrix[i][w->adjVex]=1;
		}
	}
}

//双指针遍历的时候移动的是p，*p为访问的内容(父指针本针)
int delArc(AdjList adj,int head,int tail){
	int flag=-1;
	ArcNode** p;
	//p为边节点的父节点内部的指针，该指针指向要删除的边结点
	p=&(adj[head].fisrt);
	ArcNode* del;
	while((*p)!=NULL){
		//TODO
		if((*p)->adjVex==tail){
			flag=1;
			//TODO
			del=(*p);
			*p=del->next;
			free(del);
			del=NULL;
			break;
		}
		p=&((*p)->next);
		
	}
	p=&(adj[tail].fisrt);
	while((*p)!=NULL){
		//TODO
		if((*p)->adjVex==head){
			flag=1;
			//TODO
			del=(*p);
			*p=del->next;
			free(del);
			del=NULL;
			break;
		}
		p=&((*p)->next);
		
	}
	return flag;
}
#define WHITE 0
#define RED 1
#define BLACK 2
int colorVisit[MaxVertexNum]={0};

bool getRing(AdjList adj,int v){
	if(colorVisit[v])return true;
	else{
		colorVisit[v]=RED;
		ArcNode* nextArc=adj[v].fisrt;
		while(nextArc!=NULL){
			//TODO
			bool ret=false;
			int neighborVertex=nextArc->adjVex;
			if(colorVisit[v]!=BLACK){
				//TODO
				ret=getRing(adj,neighborVertex);
			}
			if(ret==true) return ret;
			else nextArc=nextArc->next;
		}
	}//else
	colorVisit[v]=BLACK;
	return false;
}
void isExistRing(AdjList adj,int num){
	for(int v=0;v<num;v++){
		//TODO
		bool ret=false;
		if(colorVisit[v]!=BLACK){
			//TODO
			ret=getRing(adj,v);
		}
		if(ret==true){
			//TODO
			printf("There is a ring from %d\n",v);
			break;
		}
	}
}

void printVertexList(int vertexList[],int verrexListLength){
	for(int i=0;i<verrexListLength;i++){
		//TODO
		printf("%d",vertexList[i]);
	}
}

int vertexList[MaxVertexNum]={0};
int vertexListLength=0;
int visits[MaxVertexNum]={0};
void DFSTraverse(AdjList adj,int v,int destV){
	visits[v]=1;
	vertexList[vertexListLength]=v;
	vertexListLength++;
	if(destV==v){
		//TODO
		printVertexList(vertexList,vertexListLength);
	}else{
		ArcNode *p=adj[v].fisrt;
		while(p!=NULL){
			//TODO
			int w=p->adjVex;
			if(visits[w]!=1){
				//TODO
				DFSTraverse(adj,w,destV);
			}
			p=p->next;
		}
	}
	visits[v]=0;
	vertexListLength--;
}
void getPaths(AdjList adj,int srcV,int destV){
	DFSTraverse(adj,srcV,destV);
	
}


void DFS(AdjList adj,int v){
	if(visited[v]==true){
		//TODO
		return;
	}else{
		visited[v]=true;
		printf("access %d\n",v);
		ArcNode* node=adj[v].fisrt;
		while(node!=NULL){
			//TODO
			if(visited[node->adjVex]==false){
				//TODO
				DFS(adj,node->adjVex);
			}
			node=node->next;
		}
		return;
	}
}
bool isConnected(AdjList adj,int num){
	DFS(adj,1);
	for(int i=0;i<num;i++){
		//TODO
		if(visited[i]==false){
			//TODO
			return false;
		}
	}
	return true;
}

int nums[20]={1,43,76,24,76,3,9,10,543,8
	,4,34,23,0,65,34,77,98,34,29};
const int num=20;//装载的节点数
/*
 *@param arcs 一张图的所有边
 *@param vertexs 一张图的所有节点的值
 */
int arcs[MaxVertexNum][MaxVertexNum]={
{0,1,1,1,0},
{1,0,1,1,1},
{1,1,0,1,0},
{1,1,1,0,1},
{0,1,0,1,0}
};
int empty[MaxVertexNum][MaxVertexNum]={0};
int vertexs[5]={0,1,2,3,4};
void AdjListTest(){
	//TODO
}
