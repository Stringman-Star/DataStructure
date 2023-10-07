#include <stdio.h>
#include <stdlib.h>
#include"Queue.h"
#include"AdjList.h"
bool visited[MaxVertexNum]={false};

void visit(int v){
	visited[v]=true;
	printf("%d ",v);
}

void headInsert(VNode* vnode,int dest,int weight){
	ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));
	p->adjVex=dest;
	p->weight=weight;
	p->next=vnode->fisrt;
	vnode->fisrt=p;
}

void createAdjList(ALGragh &alg,char *file1,char* file2){
	FILE *fp=fopen(file1,"r");
	int source,dest,weight;//点和边坐标
	if(!fp)return;
	int num=0;
	while(!feof(fp)){
		//TODO
		fscanf(fp,"%d",&alg.adjlist[num].data);//读取数据节点文件
		num++;
	}
	alg.vexNum=num;
	fclose(fp);
	//读取边节点文件
	fp=fopen(file2,"r");
	if(!fp)return;
	mapKind kind=alg.mk;
	switch (kind) {//根据不同类型选择不同的创建方式
	case DM:
		//TODO
		while(!feof(fp)){
			//TODO
			fscanf(fp,"%d %d\n",&source,&dest);
			headInsert(&alg.adjlist[source],dest,0);
			alg.arcNum++;
		}
		fclose(fp);
		break;
	case UDM:
		//TODO
		while(!feof(fp)){
			//TODO
			fscanf(fp,"%d %d\n",&source,&dest);
			headInsert(&alg.adjlist[source],dest,empty);
			headInsert(&alg.adjlist[dest],source,empty);
			alg.arcNum+=2;
		}
		fclose(fp);
		break;
	case DN:
		//TODO
		while(!feof(fp)){
			//TODO
			fscanf(fp,"%d %d %d\n",&source,&dest,&weight);
			headInsert(&alg.adjlist[source],dest,weight);
			alg.arcNum++;
		}
		fclose(fp);
		break;
	default:
		//TODO
		while(!feof(fp)){
			//TODO
			fscanf(fp,"%d %d %d\n",&source,&dest,&weight);
			headInsert(&alg.adjlist[source],dest,weight);
			headInsert(&alg.adjlist[dest],source,weight);
			alg.arcNum+=2;
		}
		fclose(fp);
		break;
	}
}

void CreateALGragh(ALGragh &alg,char *file1,char* file2,mapKind kind){
	alg.mk=kind;
	alg.arcNum=0;
	alg.vexNum=0;
	for(int i=0;i<MaxVertexNum;i++){
		//TODO
		alg.adjlist[i].fisrt=NULL;
	}
	createAdjList(alg,file1,file2);
	
}

//void CreateAdjList(int data[],int num,int arcs[][MaxVertexNum],AdjList &adj){
//	int flag;
//	ArcNode *arcnode,*last;
//	for(int i=0;i<num;i++){
//		//TODO
//		adj[i].data=data[i];
//		flag=0;
//		last=NULL;
//		for(int j=0;j<num;j++){
//			//TODO
//			if(arcs[i][j]==0){
//				//TODO
//				continue;
//			}
//			arcnode=(ArcNode*)malloc(sizeof(ArcNode));
//			arcnode->adjVex=j;
//			arcnode->next=NULL;
//			if(!flag){
//				//TODO
//				flag=1;
//				adj[i].fisrt=arcnode;
//			}else{
//				last->next=arcnode;
//			}
//			last=arcnode;
//		}
//	}
//}

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
void showALGragh(ALGragh alg){
	printf("vexnum:%d\narcnum:%d\n",alg.vexNum,alg.arcNum);
	for(int i=0;i<alg.vexNum;i++){
		//TODO
		printf("%d->",alg.adjlist[i].data);
		ArcNode* p=alg.adjlist[i].fisrt;
		while(p!=NULL){
			//TODO
			printf("%d(%d)",p->adjVex,p->weight);
			if(p->next!=NULL){
				//TODO
				printf("->");
			}else printf("\n");
			p=p->next;
		}
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

void replace(char* p){
	int index=0;
	while(p[index]!='\0'){
		//TODO
		if(p[index]=='\\'){
			//TODO
			p[index]='/';
		}
		index++;
	}
}

void professionalProcess(){
	ALGragh alg;
	char file1[100],file2[100];
	mapKind kind;
	printf("输入节点文件:\n");
	scanf("%s",file1);
	replace(file1);
	printf("输入边节点文件:\n");
	scanf("%s",file2);
	replace(file2);
	printf("选择图类型:\nA.DM	B.UDM	C.DN	D.UDN\n");
	getchar();
	char in;
	scanf("%c",&in);
	switch (in) {
	case 'A':
		//TODO
		kind=DM;
		break;
	case 'B':
		//TODO
		kind=UDM;
		break;
	case 'C':
		kind=DN;
		break;
	default:
		//TODO
		kind=UDN;
		break;
	}
	CreateALGragh(alg,file1,file2,kind);
	showALGragh(alg);
}
void AdjListTest(){
	//TODO
}
