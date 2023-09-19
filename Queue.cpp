#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

void Queueinitial(Queue *q){
	q->rear=q->front=0;//队头指针指向当前节点，队尾指针指向下一个节点
}
int isEmpty(Queue q){
	return (q.front==q.rear);
}
int isFull(Queue q){
	return ((q.rear+1)%maxQueue==q.front);
}
int EnQueue(Queue* q,int data){
	if(isFull(*q))return 0;
	else{
		q->data[q->rear]=data;
		q->rear=(q->rear+1)%maxQueue;
		return 1;
	}
}
int DeQueue(Queue* q){
	if(isEmpty(*q))return 0;
	else{
		int result=q->data[q->front];
		q->front=(q->front+1)%maxQueue;
		return result;
	}
}
void QueueTest(){
	//TODO
}
