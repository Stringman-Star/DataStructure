#include<stdio.h>
#include<stdlib.h>
#include"CSTNode.h"
#include"BiTree.h"
//tranvse a Tree

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


int getLeafsNum(CSTree T){
	if(T==NULL)return -1;
	if(T->firstChild==NULL){//如果没有孩子，则找到了叶子节点
		//TODO
		return 1;
	}else{//否则做先根遍历
		CSTNode* p=T->firstChild;
		int sum=0;
		while(p!=NULL){//循环遍历T的每个子树中的叶子节点数
			//TODO
			sum+=getLeafsNum(p);//把每一棵子树内的叶子节点数加起来
			p=p->nextSibling;
		}
		return sum;//返回自己的叶子节点数给上一层
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
		//访问根节点的度
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
		//对孩子节点进行遍历		
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
		return maxSubTreeHeight+1;//后序遍历
	}
}
void CSTNodeTest(){
	//TODO
//	char PreArr[]="ABCDE";
//	char InArr[]="DCBEA";
//	CSTree T=createByLelIn(PreArr,InArr,0,sizeof(PreArr)/sizeof(*PreArr)-2,sizeof(InArr)/sizeof(*InArr)-1);
	CSTree T=generate();
//	preOrderTravse(T);
//	PreOrder(T);
//	printf("\n");
//	PreForestTranvese(T);
	preOrderTravse(T);
}
