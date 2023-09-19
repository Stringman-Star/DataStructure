#include<stdio.h>
#include<stdlib.h>
#include "BSNode.h"
#include "BiTree.h"
int BST_Insert(BSTree &T,char key){
	if(T==NULL){
		BSNode* node=(BSTree)malloc(sizeof(BSNode));
		node->data=key;
		node->lchild=NULL;
		node->rchild=NULL;
		T=node;
		return 1;
	}else{
		if(T->data==key){
			return 0;
		}else if(T->data<key){
			//TODO
			if(T->rchild==NULL){
				//TODO
				T->rchild=(BSTree)malloc(sizeof(BSNode));
				T->rchild->data=key;
				T->rchild->lchild=NULL;
				T->rchild->rchild=NULL;
				return 1;
			}else{
				return BST_Insert(T->rchild,key);
			}
		}else{
			//TODO
			if(T->lchild==NULL){
				//TODO
				T->lchild=(BSTree)malloc(sizeof(BSNode));
				T->lchild->data=key;
				T->lchild->lchild=NULL;
				T->lchild->rchild=NULL;
				return 1;
			}else{
				return BST_Insert(T->lchild,key);
			}
		}
	}
}

void createBST(char data[],int num,BSNode *&T){
	T=NULL;
	for(int i=0;i<num;i++){
		//TODO
		BST_Insert(T,data[i]);
	}
}
/*
 "*&"符号代表的是对某一类指针的引用，既可以改变指针所指向的内容，也可以改变指针自身
  而"**"代表的是指向一个指针的指针，即**B:B->_1_->_2_;这样的话就可以通过*B来获取1的内容(指向2的指针)
  也可通过**B来获取2的内容，最主要是可以通过(*B)来改变1的指向
  综上，"*&"要更方便
 */
int searchBSnode(BSTree T,int data,BSNode *&node){
	node=T;
	while(1){
		if(node==NULL){
			return 0;
		}else {
			int curData=node->data;
			if(curData<data){
				//TODO
				node=node->rchild;
				continue;
			} 
			if(curData>data){
				//TODO
				node=node->lchild;
				continue;
			}
			return 1;
		}
	}
}

int delBSNode(BSTree &T,char x){
	//q->node1,T->node1,p->T->node1
	BSNode *q=T,**p=&T;
	while(q!=NULL){
		//TODO
		if(q->data==x){
			break;
		}else if(q->data<x){
			//此时p获取了指向q的来自父节点的右孩子指针
			p=&(q->rchild);
			q=q->rchild;
		}else{
			//此时p获取了指向q的来自父节点的左孩子指针
			p=&(q->lchild);
			q=q->lchild;
		}
	}
	if(q==NULL){
		return 0;
	}
	if(q->lchild==NULL&&q->rchild==NULL){
		//TODO
		free(q);
		*p=NULL;
	}else if(q->lchild==NULL){
		//TODO
		*p=q->rchild;
		free(q);
		q=NULL;
	}else if(q->rchild==NULL){
		//TODO
		*p=q->lchild;
		free(q);
		q=NULL;
	}else{
		BSNode* suc=q->lchild;
		while(suc->rchild!=NULL){
			//TODO
			suc=suc->rchild;
		}
		q->data=suc->data;
		delBSNode(q->lchild,suc->data);
	}
	return 1;
}

void insertNode(BSTree& T,BSTree t){
	if(T==NULL){
		//TODO
		T=t;
	}else{
		if(T->data<t->data){
			//TODO
			insertNode(T->rchild,t);
		}else{
			insertNode(T->lchild,t);
		}
	}
}

/*
  算法思想:
	  把一棵BST分解为两棵树，一棵全大于key一棵全小于key
 */
void splitBST(BSTree& T,char key,BSTree& smlT,BSTree& bigT){
	if(T!=NULL){
		//TODO
		if(T->data==key){
			//TODO
			insertNode(smlT,T->lchild);
			insertNode(bigT,T->rchild);
			free(T);
			T=NULL;
		}else if(T->data<key){
			//TODO
			BSTree p=T->rchild;
			T->rchild=NULL;
			insertNode(smlT,T);
			splitBST(p,key,smlT,bigT);
		}else{
			BSTree p=T->lchild;
			T->lchild=NULL;
			insertNode(bigT,T);
			splitBST(p,key,smlT,bigT);
		}
	}
}

void deleteTree(BSTree& T){
	if(T!=NULL){
		//TODO
		deleteTree(T->lchild);
		deleteTree(T->rchild);
		free(T);
		T=NULL;
	}
}

/*
  算法思想:
	  删除BST中所有小于Key的节点
 */

//void deleteSmalKey(BSTree& T,char key){
//	if(T!=NULL){
//		//TODO
//		if(T->data==key){
//			//TODO
//			deleteTree(T->lchild);
//			T->lchild=NULL;
//			return;
//		}else if(T->data>key){
//			//TODO
//			deleteSmalKey(T->lchild,key);
//		}else{
//			BSTree p=T->rchild;
//			T->rchild=NULL; 
//			deleteTree(T);
//			T=p;
//			deleteSmalKey(T,key);
//		}
//	}
//}

void deleteSmalKey(BSTree& T,char key){
	if(T!=NULL){
		//TODO
		deleteSmalKey(T->lchild,key);
		BSTree p;
		if(T->data<key){
			//TODO
			p=T->rchild;
			T->rchild=NULL;
			deleteTree(T);
			T=p;
			deleteSmalKey(T,key);
		}else if(T->data==key){
			//TODO
			deleteTree(T->lchild);
		}else{
			deleteSmalKey(T->lchild,key);
		}
	}
}


int getInbalancePoints(BiTree T){
	if(T!=NULL){
		//TODO
		int flag=getDepth(T->lchild)-getDepth(T->rchild);
		if(flag<-1||flag>1){
			//TODO
			flag=1;
		}else flag=0;
		return getInbalancePoints(T->lchild)+getInbalancePoints(T->rchild)+flag;
	}
}

void hello(char *string){
	for(int i=0;string[i]!='\0';i++){
		//TODO
		printf("%c",string[i]);
	}
}



void BSNodeTest(){
	//TODO
	char datas[10]={'F','B','I','A','C','H','J','D','G','E'};
	BSTree T=NULL;
	createBST(datas,10,T);	
//	InOrder(T);
	printf("%d",getInbalancePoints(T));
}
