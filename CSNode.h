#ifndef CSTNODE_H
#define CSTNODE_H
#include"BiTree.h"
typedef struct CSNode:BiTNode{
	struct CSNode* firstChild;
	struct CSNode* nextSibling;
}CSNode,*CSTree;


void CSNodeTest();
#endif
