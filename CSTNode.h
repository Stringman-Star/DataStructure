#ifndef CSTNODE_H
#define CSTNODE_H
#include"BiTree.h"
typedef struct CSTNode:BiTNode{
	BiTNode* &firstChild=lchild;
	BiTNode* &nextSibling=rchild;
}CSTNode,*CSTree;
#endif
