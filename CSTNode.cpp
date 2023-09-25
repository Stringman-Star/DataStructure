#include<stdio.h>
#include<stdlib.h>
#include"CSTNode.h"
#include"BiTree.h"
//tranvse a Tree


CSTree alterTree2CS(BiTree T,BiTNode* pre){
	return NULL;
}
CSTree alterTrees2CS(BiTree Ts[],int num){
	if(num==0)return NULL;
	CSTree CS;
	CS=alterTree2CS(Ts[0],NULL);//指向第一棵树
	CSTNode* curNode=CS;
	int index=1;
	while(index<num){
		//TODO
		curNode->nextSibling=alterTree2CS(Ts[index],NULL);
		curNode=curNode->nextSibling;
	}
	return CS;
}
void preOrderTravse(CSTree T){
	if(T!=NULL){
		//TODO
		visit(T);
		CSTNode *pCurchild=T->firstChild;
		while(pCurchild!=NULL){
			//TODO
			preOrderTravse(pCurchild);
			pCurchild=pCurchild->nextSibling;
		}
	}
}
/*
  1,往兄弟的方向循环，往孩子的方向递归
  2,先孩子递归，后兄弟循环
  3,递归往下走，循环平层次，先找到深度为2的子树的最右边的兄弟
 */

void postOrderTravse(CSTree T){
	if(T!=NULL){
		//TODO
		CSTNode *pCurchild=T->firstChild;
		while(pCurchild!=NULL){
			//TODO
			postOrderTravse(pCurchild);
			pCurchild=pCurchild->nextSibling;
		}
		visit(T);
	}
}

int num=0;
void leafsInCSTree(CSTree T){
	if(T->firstChild==NULL){
		//TODO
		num++;
	}else{
		for(CSTNode* p=T->firstChild;p!=NULL;p=p->nextSibling){
			//TODO
			leafsInCSTree(p);
		}
	}
}

/*
  @param degree Tree's degree number
  @param count Current node's degree number
 */

int degree=0;
void getDegreeInCSTree(CSTree T){
	if(T!=NULL){
		//TODO
		int count=0;
		CSTNode* pCurNode=T;
		while(pCurNode->nextSibling!=NULL){
			//TODO
			count++;
			pCurNode=pCurNode->nextSibling;
		}
		if(count>degree){
			//TODO
			degree=count;
		}
		CSTNode* pCurChildNode=T->firstChild;
		while(pCurChildNode!=NULL){
			//TODO
			getDegreeInCSTree(pCurChildNode);
			pCurChildNode=pCurChildNode->nextSibling;
		}
	}
}

int getDepthOfCSTree(CSTree T){
	if(T!=NULL)return 0;
	else{
		int maxSubTreeHeight=0;
		for(CSTNode *p=T->firstChild;p!=NULL;p=p->nextSibling){
			//TODO
			int subTreeHeight=getDepthOfCSTree(p);
			if(subTreeHeight>maxSubTreeHeight){
				//TODO
				maxSubTreeHeight=subTreeHeight;
			}
		}
		return maxSubTreeHeight+1;
	}
}

void CSTNodeTest(){
	//TODO
	CSTree T;
	T=generate();
}
