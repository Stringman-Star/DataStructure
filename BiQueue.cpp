#include<stdio.h>
#include"BiTree.h"
#include"BiQueue.h"
void BiQueueInitial(BiQueue* q){
	q->rear=q->head=0;
	for(int i=0;i<20;i++){
		//TODO
		q->data[i]=NULL;
	}
}
int isBiQEmpty(BiQueue* q){
	return q->rear==q->head;
}
void EnBiQueue(BiQueue* q,BiTNode* t){
	//TODO
	q->data[q->rear]=t;
	q->rear=(q->rear+1)%20;
}
BiTNode* DeBiQueue(BiQueue* q){
	if(!isBiQEmpty(q)){
		//TODO
		return q->data[(q->head++)%20];
	}else return NULL;
}
void BiQueueTest(){
	//TODO
}
