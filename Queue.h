#ifndef QUEUE_H
#define QUEUE_H
const int maxQueue=20;
//const int nums[20]={1,43,76,24,76,3,9,10,543,8
//	,4,34,23,0,65,34,77,98,34,29};
//const int num=20;//装载的节点数
typedef struct Queue{
	int data[maxQueue];
	int front,rear;
}Queue;
void Queueinitial(Queue *q);
int isEmpty(Queue q);
int isFull(Queue q);
int EnQueue(Queue* q,int data);
int DeQueue(Queue* q);
void QueueTest();
#endif
