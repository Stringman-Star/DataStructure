#ifndef BIQUEUE_H
#define BIQUEUE_H
#include"BiTree.h"
typedef struct BiQueue{
	BiTNode* data[20];
	int rear,head;
}BiQueue;
void BiQueueInitial(BiQueue* q);
int isBiQEmpty(BiQueue* q);
void EnBiQueue(BiQueue* q,BiTNode* t);
BiTNode* DeBiQueue(BiQueue* q);

void BiQueueTest();
#endif
