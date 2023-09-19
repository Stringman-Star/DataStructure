#include"stdio.h"
#include"ThreadNode.h"
#include"ThQueue.h"
void ThQueueInitial(ThQueue* q){
	q->rear=q->head=0;
}
int isThQEmpty(ThQueue* q){
	return q->rear==q->head;
}
void EnThQueue(ThQueue* q,ThreadNode* t){
	//TODO
	q->data[q->rear++]=t;
}
ThreadNode* DeThQueue(ThQueue* q){
	if(!isThQEmpty(q)){
		//TODO
		return q->data[q->head++];
	}else return NULL;
}

void ThQueueTest(){
	//TODO
}
