#ifndef BSNODE_H
#define BSNODE_H
#include"BiTree.h"
typedef BiTNode BSNode,*BSTree;
int BST_Insert(BSTree &T,char key);
void createBST(char data[],int num,BSNode *&T);
int searchBSnode(BSTree T,int data,BSNode *&node);
int delBSNode(BSTree &T,char x);

void BSNodeTest();
#endif
