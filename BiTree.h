#ifndef BITREE_H
#define BITREE_H
#include "Queue.h"
typedef struct BiTNode{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;	
}BiTNode,*BiTree;
typedef struct QElemtype{
	BiTNode* pnode;
	int nodeLevel;
}QElemtype;

typedef struct LQueue:Queue{
	QElemtype nodes[maxQueue];
}LQueue;
void init(BiTNode* bitnode);
BiTree generate();
int createTree(BiTree T,char data,int* indexSeq,int n);
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
void levelOrder(BiTree T);
int getDepth(BiTree T);
int isCompletedTree(BiTree T);
void EnElemQueue(LQueue* l,QElemtype q);
QElemtype* DeElemQueue(LQueue* l);
int getWidth4BiTree(BiTree T);
void printLevelbyLevel(BiTree T);
void printAll(LQueue *l);
int numsOfnode1InLevel(int level,BiTree T);
int numOfLeafnode(BiTree T);
int isSimilar(BiTree A,BiTree B);
BiTNode *seekNode(BiTree T,int value);
void deleteBiTree(BiTree* T);
void delXTree(BiTree* T,char X);
BiTree getDad(BiTree T,char x);
void visit(BiTNode* p);

void BiTreeTest();
#endif
