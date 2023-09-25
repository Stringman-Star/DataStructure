#include<stdio.h>
#include<stdlib.h>
#include"ThreadNode.h"
#include"ThQueue.h"
void init(ThreadNode* tnode){
	tnode->lchild=NULL;
	tnode->rchild=NULL;
	tnode->ltag=0;
	tnode->rtag=0;
}
void createUnThreadBiTree(ThreadTree T,char data,int* indexSeq,int n){
	ThreadNode* t=T;
	int a=0;//0为插入到左节点，1为右节点
	for(int i=0;i<n;i++){
		//TODO
		if(indexSeq[i]==0){
			//TODO
			if(t->lchild==NULL){
				a=0;
				break;
			}
			t=t->lchild;
		}else{
			if(t->rchild==NULL){
				a=1;
				break;
			}
			t=t->rchild;
		}
	}
	if(a){
		//TODO
		t->rchild=(ThreadNode*)malloc(sizeof(ThreadNode));
		t=t->rchild;
		t->data=data;
	}else{
		t->lchild=(ThreadNode*)malloc(sizeof(ThreadNode));
		t=t->lchild;
		t->data=data;
	}
	init(t);
}
ThreadTree generateAThTree(){
	int index[9][10] = { {}, {0}, {0, 1}, {1}, {1, 0}, {1, 1}, {1, 1, 0}, {1, 1, 0, 1}, {1, 1, 1} };
	int nums[9]={0,1,2,1,2,2,3,4,3};
	char data[9]={'A','B','C','D','E','F','G','H','I'};
	ThreadTree T=(ThreadNode*)malloc(sizeof(ThreadNode));
	T->data=data[0];
	init(T);
	for(int i=1;i<9;i++){
		//TODO
		createUnThreadBiTree(T,data[i],index[i],nums[i]);
	}
	return T;
}
void InThread(ThreadTree p,ThreadTree* pre){
	if(p!=NULL){
		//TODO
		InThread(p->lchild,pre);
		if(p->lchild==NULL){
			//TODO
			p->lchild=*pre;
			p->ltag=1;
		}
		if(*pre!=NULL&&(*pre)->rchild==NULL){
			//TODO
			(*pre)->rchild=p;
			(*pre)->rtag=1;
		}
		*pre=p;
		InThread(p->rchild,pre);
	}
}
void PreThread(ThreadTree p,ThreadTree *pre){
	if(p!=NULL){
		//TODO
		if(p->lchild==NULL){
			//TODO
			p->lchild=*pre;
			p->ltag=1;
		}
		if((*pre)!=NULL&&(*pre)->rchild==NULL){
			//TODO
			(*pre)->rchild=p;
			(*pre)->rtag=1;
		}
		(*pre)=p;
		if(p->ltag==0){
			PreThread(p->lchild,pre);
		}
		if(p->rtag==0){
			//TODO
			PreThread(p->rchild,pre);
		}
	}
}


/*
  lchild在遍历的时候仅有根节点在其之前访问过才需要判断是否被遍历过
  访问根节点是前驱+rtag，T加ltag
  所以如果T在lchild之前被访问，那么要判断
  
  访问rchild是否要判断要看T是否成为过pre
  因为仅有pre可能被更改rtag
  所以PreOrder访问rchild的时候要看，因为T成为过lchild的pre
  而InOrder中T是rchild的直接前驱，所以不需要判断
 */
void PostThread(ThreadTree T,ThreadNode* &pre){
	if(T!=NULL){
		//TODO
		PostThread(T->lchild,pre);
		PostThread(T->rchild,pre);
		if(T->lchild==NULL&&T->ltag==0){
			//TODO
			T->lchild=pre;
			T->ltag=1;
		}
		if(pre!=NULL&&pre->rchild==NULL&&pre->rtag==0){
			//TODO
			pre->rchild=T;
			pre->rtag=1;
		}
		pre=T;
	}
}

void CreateInThread(ThreadTree T){//alter a tree to a threaded tree
	ThreadTree p=NULL;
	ThreadTree* pre=&p;
	if(T!=NULL){
		//TODO
		InThread(T,pre);
		(*pre)->rchild=NULL;
		(*pre)->rtag=1;
	}
}
void CreatePreThread(ThreadTree T){
	ThreadNode* pre=NULL;
	PreThread(T,&pre);
	if(pre!=NULL){
		if(pre->rtag==0){
			//TODO 
			pre->rchild=NULL;
			pre->rtag=1;
		}
	}
}

void CreatePostThread(ThreadTree T){
	ThreadNode* pre=NULL;
	PostThread(T,pre);
}
ThreadNode* getFirstNode(ThreadTree T){
	ThreadTree p=T;
	while(p->ltag==0){
		//TODO
		p=p->lchild;
	}
	return p;
}
ThreadNode* getNextNode(ThreadTree T){
	if(T->rtag==1){
		//TODO
		return T->rchild;
	}else{
		return getFirstNode(T->rchild);//获取右子树中的第一个节点
	}
}
void inOrderTraverse(ThreadTree T){
	ThreadNode* firstnode=getFirstNode(T),*p;
	for(p=firstnode;p!=NULL;p=getNextNode(p)){
		//TODO
		printf("%c,p->ltag=%d,p-rtag=%d\n",p->data,p->ltag,p->rtag);
	}
}
void levelOrder(ThreadTree T){
	ThQueue *q=(ThQueue*)malloc(sizeof(ThQueue));
	ThQueueInitial(q);
	ThreadNode* p;
	EnThQueue(q,T);
	while(!isThQEmpty(q)){
		//TODO
		p=DeThQueue(q);
		//		printf("%c ltag=%d,rtag=%d",p->data,p->ltag,p->rtag);
		if(p->ltag!=1){
			//TODO
			EnThQueue(q,p->lchild);
		}
		if(p->rtag!=1){
			//TODO
			EnThQueue(q,p->rchild);
		}
	}
}
int NodeDepth=1;
void searchValueDepth(BiTree T,int Value,int curDepth){
	if(T==NULL)return;
	else if(T->data==Value){
		//TODO
		NodeDepth=curDepth;
	}else{
		searchValueDepth(T->lchild,Value,curDepth+1);
		searchValueDepth(T->rchild,Value,curDepth+1);
	}
}

bool preFind(BiTree T,char x){
	if(T==NULL)return false;
	else if(T->data==x)return true;
	else if(preFind(T->lchild,x)||preFind(T->rchild,x)){
		printf("%c ",T->data);
		return true;
	}
	return false;
}


ThreadTree getNext(ThreadTree T){
	if(T->ltag!=1){
		//TODO
		return T->lchild;
	}else{
		return T->rchild;
	}
}
void preTranverse(ThreadTree T){
	for(;T!=NULL;T=getNext(T)){
		//TODO
		printf("%c ",T->data);
	}
}


void ThreadATree(ThreadTree T,ThreadNode*& pre){
	if(T!=NULL){
		//TODO
		ThreadATree(T->lchild,pre);
		if(T->lchild==NULL){
			//TODO
			T->ltag=1;
			T->lchild=pre;
		}
		if(pre!=NULL&&pre->rchild==NULL){
			//TODO
			pre->rtag=1;
			pre->rchild=T;
		}
		pre=T;
		if(T->rchild!=NULL){
			//TODO
			ThreadATree(T->rchild,pre);
		}
	}
}



void ThreadNodeTest(){
	//TODO
	ThreadTree T=generateAThTree();//二叉树
	//	InOrder(T);
//	CreatePreThread(T);//线索二叉树
//	preTranverse(T);
	CreatePostThread(T);
	
	//	levelOrder(T);
}

