#ifndef THQUEUE_H
#define THQUEUE_H
#include "ThreadNode.h"
typedef struct ThQueue{
	ThreadNode* data[20];
	int rear,head;
}ThQueue;
void ThQueueInitial(ThQueue* q);
int isThQEmpty(ThQueue* q);
void EnThQueue(ThQueue* q,ThreadNode* t);
ThreadNode* DeThQueue(ThQueue* q);

void ThQueueTest();
#endif
