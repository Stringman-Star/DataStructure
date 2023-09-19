#ifndef THREADNODE_H
#define THREADNODE_H
#include"BiTree.h"
typedef struct ThreadNode:BiTNode{
	struct ThreadNode* lchild;
	struct ThreadNode* rchild;
	int ltag;
	int rtag;
}ThreadNode,*ThreadTree;
void init(ThreadNode* tnode);
void createUnThreadBiTree(ThreadTree T,char data,int* indexSeq,int n);
ThreadTree generateATree();//generate a sample of UnThreadTree
void PreThread(ThreadTree p,ThreadTree pre);//PreThreading
void CreateInThread(ThreadTree T);
void CreatePreThread(ThreadTree T);
ThreadNode* getFirstNode(ThreadTree T);
ThreadNode* getNextNode(ThreadTree T);
void inOrderTraverse(ThreadTree T);
void levelOrder(ThreadTree T);
void InThread(ThreadTree p,ThreadTree* pre);//InThreading an unThreadTree

void ThreadNodeTest();
#endif
