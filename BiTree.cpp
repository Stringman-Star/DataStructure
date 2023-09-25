#include<stdio.h>
#include<stdlib.h>
#include"BiTree.h"
#include"BiQueue.h"
void init(BiTNode* bitnode){
	bitnode->lchild=NULL;
	bitnode->rchild=NULL;
}
int createTree(BiTree T,char data,int* indexSeq,int n){
	BiTNode* t=T;
	int direction=0;//0为插入到左节点，1为右节点
	for(int i=0;i<n;i++){
		//TODO
		if(indexSeq[i]==0){
			//TODO
			if(t->lchild==NULL){
				direction=0;
				break;
			}
			t=t->lchild;
		}else{
			if(t->rchild==NULL){
				direction=1;
				break;
			}
			t=t->rchild;
		}
	}
	if(direction){
		//TODO
		t->rchild=(BiTNode*)malloc(sizeof(BiTNode));
		t=t->rchild;
		t->data=data;
	}else{
		t->lchild=(BiTNode*)malloc(sizeof(BiTNode));
		t=t->lchild;
		t->data=data;
	}
	init(t);
	return 1;
}
BiTree generate(){
	int index[9][10] = { {}, {0}, {0, 1}, {1}, {1, 0}, {1, 1}, {1, 1, 0}, {1, 1, 0, 1}, {1, 1, 1} };
	int nums[9]={0,1,2,1,2,2,3,4,3};
	char data[9]={'l','c','e','z','k','i','s','a','k'};
	BiTree T=(BiTNode*)malloc(sizeof(BiTNode));
	T->data=data[0];
	init(T);
	for(int i=1;i<9;i++){
		//TODO
		createTree(T,data[i],index[i],nums[i]);
	}
	return T;
}
void PreOrder(BiTree T){
	if(T!=NULL){
		//TODO
		printf("%c ",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree T){
	if(T!=NULL){
		//TODO
		InOrder(T->lchild);
		printf("%c ",T->data);
		InOrder(T->rchild);
	}
}
void PostOrder(BiTree T){
	if(T!=NULL){
		//TODO
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c ",T->data);
	}
}
void levelOrder(BiTree T){
	BiQueue *q=(BiQueue*)malloc(sizeof(BiQueue));
	BiQueueInitial(q);
	BiTNode* p;
	EnBiQueue(q,T);
	while(!isBiQEmpty(q)){
		//TODO
		p=DeBiQueue(q);
		printf("%c ",p->data);
		if(p->lchild!=NULL){
			//TODO
			EnBiQueue(q,p->lchild);
		}
		if(p->rchild!=NULL){
			//TODO
			EnBiQueue(q,p->rchild);
		}
	}
}
int isCompletedTree(BiTree T){
	BiQueue* Q=(BiQueue*)malloc(sizeof(BiQueue));
	BiQueueInitial(Q);
	EnBiQueue(Q,T);
	BiTNode* p=NULL;
	while(!isBiQEmpty(Q)){//所有的节点包括叶子节点的叶子节点即空节点都进去
		//TODO
		p=DeBiQueue(Q);
		if(p==NULL){//当第一个空节点出来时候就跳出来
			//TODO
			break;
		}
		EnBiQueue(Q,p->lchild);
		EnBiQueue(Q,p->rchild);
	}
	while(!isBiQEmpty(Q)){//只要后面不是非空，那么就一直运行下去
		//TODO
		p=NULL;
		p=DeBiQueue(Q);
		if(p!=NULL){//当第一个空节点出现，后续一旦出现非空，则代表不是完全树
			//TODO
			return 0;
		}
	}
	return 1;
	
}
int getDepth(BiTree T){
	if(T!=NULL){
		//TODO
		int l=getDepth(T->lchild);
		int r=getDepth(T->rchild);
		return l>r?l+1:r+1;//traceback
	}else{
		return 0;
	}
}
void EnElemQueue(LQueue* l,QElemtype* q){//层级遍历二叉树所用的队列
	if(isFull(*l))return;
	l->nodes[l->rear]=*q;
	l->rear=(l->rear+1)%maxQueue;
//	printAll(l);
}
QElemtype* DeElemQueue(LQueue* l){
	if(isEmpty(*l)){
		//TODO
		return NULL;
	}else{
		int a=l->front;
		l->front=(l->front+1)%maxQueue;
		return &(l->nodes[a]);
	}
}
void printAll(LQueue *l){
	printf("\n\nall elem:");
	for(int i=l->front;i<l->rear;i=(i+1)%maxQueue){
		//TODO
		printf("%c ",l->nodes[i].pnode->data);
	}
	printf("\n");
}
int getWidth4BiTree(BiTree T){
	if(T==NULL)return 0;
	LQueue *Q=(LQueue*)malloc(sizeof(LQueue));
	QElemtype* e=(QElemtype*)malloc(sizeof(QElemtype));
	e->pnode=T;
	e->nodeLevel=1;
	Queueinitial(Q);
	EnElemQueue(Q,e);
	int currentLevel=1;
	char MaxValue=e->pnode->data;
	while(!isEmpty(*Q)){
		//TODO
		e=DeElemQueue(Q);
		char data=e->pnode->data;
		if(currentLevel==e->nodeLevel){
			//TODO
			if(MaxValue<data){
				//TODO
				MaxValue=data;
			}
		}else{
			printf("the max of %c in the level of %d\n\n",MaxValue,currentLevel);
			currentLevel=e->nodeLevel;
			MaxValue=data;
		}
		QElemtype* tmp=(QElemtype*)malloc(sizeof(QElemtype));
		BiTNode* p=e->pnode;
		if(p->lchild!=NULL){
			//TODO
			tmp->pnode=p->lchild;
			tmp->nodeLevel=currentLevel+1;
//			printf("put in %c\n",tmp->pnode->data);
			EnElemQueue(Q,tmp);
		}
		if(p->rchild!=NULL){
			//TODO
			tmp->pnode=p->rchild;
			tmp->nodeLevel=currentLevel+1;
//			printf("put in %c\n",tmp->pnode->data);
			EnElemQueue(Q,tmp);
		}
	}
	printf("the max of %c in the level of %d\n\n",MaxValue,currentLevel);//收尾最后一行的节点
}
void printLevelbyLevel(BiTree T){
	LQueue* Q=(LQueue*)malloc(sizeof(LQueue));
	QElemtype* e=(QElemtype*)malloc(sizeof(QElemtype));
	e->pnode=T;
	e->nodeLevel=1;
	int currentLevel=1,count=0,widest=0,widelevel=0;
	Queueinitial(Q);
	EnElemQueue(Q,e);
	while(!isEmpty(*Q)){
		//TODO
		e=DeElemQueue(Q);
		BiTNode* p=e->pnode;
		if(currentLevel==e->nodeLevel){
			//TODO
			printf("%c ",p->data);
			count++;
		}else{
			printf("  count=%d\n%c ",count,p->data);
			if(count>widest){
				//TODO
				widelevel=currentLevel;
				widest=count;
			}
			count=1;
			currentLevel=e->nodeLevel;
		}
		QElemtype *q=(QElemtype*)malloc(sizeof(QElemtype));
		if(p->lchild!=NULL){
			//TODO
			q->pnode=p->lchild;
			q->nodeLevel=e->nodeLevel+1;
			EnElemQueue(Q,q);
		}
		if(p->rchild!=NULL){
			//TODO
			q->pnode=p->rchild;
			q->nodeLevel=e->nodeLevel+1;
			EnElemQueue(Q,q);
		}
	}
	printf("  count=%d\n ",count);
	if(count>widest){
		//TODO
		widest=count;
		widelevel=currentLevel;
	}
	printf("the widest level of the tree is %d,and the width is %d",widelevel,widest);
}
int isSingleChild(BiTNode b){
	if(b.lchild==NULL&&b.rchild!=NULL){
		//TODO
		return 1;
	}else if(b.rchild==NULL&&b.lchild!=NULL){
		//TODO
		return 1;
	}else return 0;
}

int numsOfnode1InLevel(int level,BiTree T){
	LQueue* Q=(LQueue*)malloc(sizeof(LQueue));
	QElemtype* e=(QElemtype*)malloc(sizeof(QElemtype));
	e->pnode=T;
	e->nodeLevel=1;
	Queueinitial(Q);
	EnElemQueue(Q,e);
	int count=0,curLevel=0;
	while(!isEmpty(*Q)){
		e=DeElemQueue(Q);
		curLevel=e->nodeLevel;
		//TODO
		if(curLevel!=level){
			//TODO
			if(curLevel>level)break;//meaning the level has passed
			QElemtype p;
			BiTNode* node=e->pnode;
			if(node->lchild!=NULL){
				//TODO
				p.pnode=node->lchild;
				p.nodeLevel=e->nodeLevel+1;
				EnElemQueue(Q,&p);
			}
			if(node->rchild!=NULL){
				//TODO
				p.pnode=node->rchild;
				p.nodeLevel=e->nodeLevel+1;
				EnElemQueue(Q,&p);
			}
		}else{
			if(isSingleChild(*e->pnode)){
				//TODO
				count++;
			}
		}
	}
	return curLevel>=level?count:-1;//when the level unreachable return -1
}

int numOfLeafnode(BiTree T){//count of single-child nodes` num;
	//TODO
	if(T!=NULL){
		//TODO
		int sum=0;
		if(T->lchild!=NULL&&T->rchild!=NULL){
			//TODO
			sum+=numOfLeafnode(T->lchild);
			sum+=numOfLeafnode(T->rchild);
		}else if(T->lchild==NULL&&T->rchild!=NULL){
			printf("%c ",T->data);
			sum=1+numOfLeafnode(T->rchild);
		}else if(T->rchild==NULL&&T->lchild!=NULL){
			printf("%c ",T->data);
			sum=1+numOfLeafnode(T->lchild);
		}
		return sum;
	}else return 0;
}

int isSimilar(BiTree A,BiTree B){//identify 2 BiTree similarity
	int result=1;
	if(A!=NULL&&B!=NULL){
		//TODO
		result=isSimilar(A->lchild,B->lchild);
		result=isSimilar(A->rchild,B->rchild);
	}else if(A==NULL&&B==NULL){
		//TODO
		result=1;
	}else{
		result=0;
	}
	return result;
}
BiTNode *seekNode(BiTree T,int value){
	if(T!=NULL){
		//TODO
		if(T->data==value){
			//TODO
			return T;
		}else{
			if(seekNode(T->lchild,value)){
				//TODO
				return seekNode(T->lchild,value);
			}else if(seekNode(T->rchild,value)){
				//TODO
				return seekNode(T->rchild,value);
			}
		}
	}else return NULL;
}

void deleteBiTree(BiTree* T){
	if((*T)!=NULL){
		//TODO
		deleteBiTree(&((*T)->lchild));
		deleteBiTree(&((*T)->rchild));
		(*T)->lchild=NULL;
		(*T)->rchild=NULL;
		free((*T));
		*T=NULL;
	}
}
void visit(BiTNode* p){
	printf("%c ",p->data);
}
void delXTree(BiTree* T,char X){
	if((*T)!=NULL){
		//TODO
		delXTree(&((*T)->lchild),X);
		delXTree(&((*T)->rchild),X);
		if((*T)->data==X){
			//TODO
			deleteBiTree(T);
		}
	}
}
BiTree getDad(BiTree T,char x){
	if(T==NULL) return NULL;
	if(T->lchild==NULL&&T->rchild==NULL) return NULL;
	else{	
		if((T->lchild!=NULL&&T->lchild->data==x)||(T->rchild!=NULL&&T->rchild->data==x)){
			return T;
		}else{
			BiTNode* l=getDad(T->lchild,x);
			BiTNode* r=getDad(T->rchild,x);
			if(l||r){
				//TODO
				return l==NULL?r:l;
			}
			return NULL;
		}
	}
}


/*
  @param PreArr 先序序列
  @param PreStart 先序序列开始的索引号
  @param PreEnd 先序序列结束的索引号
 */
BiTree createByPreIn(char PreArr[],int PreStart,int PreEnd,char InArr[],int InStart,int InEnd){
	//递归边界
	if(InStart>InEnd){
		//TODO
		return NULL;
	}
	//创建节点
	BiTNode* node=(BiTNode*)malloc(sizeof(BiTNode));
	node->data=PreArr[PreStart];//先序序列第一个一定是根节点
	int root;
	for(root=InStart;root<=InEnd;root++){
		//TODO
		if(InArr[root]==node->data){
			//TODO
			break;
		}
	}
	//在中序序列中，第root是根节点，则左子树是[InStart,root-1],右子树[root+1,InEnd]
	//在先序序列中左子树就应该为[PreStart+1,PreStart+leftNum],右子树[PreStart+leftNum+1,PreEnd]
	int leftNum=root-InStart;
	node->lchild=createByPreIn(PreArr,PreStart+1,PreStart+leftNum,InArr,InStart,root-1);
	node->rchild=createByPreIn(PreArr,PreStart+leftNum+1,PreEnd,InArr,root+1,InEnd);
	return node;
}

//算法思想，树的算法在于每次只确定根节点，则每次从层次序列中依次拿出节点在InArr中进行匹配，
//第一个匹配到的就是根节点

bool isExist(char InArr[],int start,int end,char e,int &index){
	for(int j=start;j<=end;j++){
		//TODO
		if(e==InArr[j]){
			//TODO
			index=j;
			return true;
		}
	}
	return false;
}
bool Used[30]={0};
BiTree createByLelIn(char leArr[],char InArr[],int start,int end,int num){
	BiTNode* T=NULL;
	if(start>end)return T;//此时代表该树为空
	else{
		int i,index=-1;
		for(i=0;i<num;i++){
			//TODO
			if(Used[leArr[i]-'A']){
				//TODO
				continue;
			}
			if(isExist(InArr,start,end,leArr[i],index)){
				Used[leArr[i]-'A']=1;
				break;	
			}//层次遍历中第一个在该树的中序遍历出现的节点就是根节点
		}
		//定义该子树的根节点
		T=(BiTNode*)malloc(sizeof(BiTNode));
		T->data=leArr[i];
		T->lchild=createByLelIn(leArr,InArr,start,index-1,num);
		T->rchild=createByLelIn(leArr,InArr,index+1,end,num);
	}
	return T;
}
/*
  算法说明：
	  找到一棵树里面所有的叶子节点，并且串成一个带有头结点的双向链表
 */
void convert(BiTree T,BiTNode* pre){
	if(T!=NULL){
		if(T->lchild==NULL&&T->rchild==NULL){
			//TODO
			T->rchild=pre->rchild;
			if(pre->rchild!=NULL){
				//TODO
				pre->rchild->lchild=T;
			}
			T->lchild=pre;
			pre->rchild=T;
		}else{
			convert(T->lchild,pre);
			convert(T->rchild,pre);
		}
	}
}

BiTNode* leafLink(BiTree T){
	BiTNode *head=(BiTNode*)malloc(sizeof(BiTNode));
	head->rchild=NULL;
	head->lchild=NULL;
	convert(T,head);
	return head;
}
  
int oper(int a,int b,char op){
	switch (op) {
	case '+':
		//TODO
		return a+b;
	case '-':
		//TODO
		return a-b;
	case '*':
		return a*b;
	default:
		//TODO
		return a/b;
	}
}

#define error -0xffff
int Calculate(BiTree T){
	if(T==NULL){
		//TODO
		return error;
	}else if(T->lchild!=NULL&&T->rchild!=NULL){
		//TODO
		return oper(Calculate(T->lchild),Calculate(T->rchild),T->data);
	}else{
		return T->data;
	}
}

void BiTreeTest(){
	//TODO
	char PreArr[]="ABCDE";
	char InArr[]="DCBEA";
//	char LeArr[]="ABCDEFG";
//	BiTree T=generate();
	BiTree T=createByLelIn(PreArr,InArr,0,sizeof(PreArr)/sizeof(*PreArr)-2,sizeof(InArr)/sizeof(*InArr)-1);
	PreOrder(T);
}
