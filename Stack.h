#ifndef STACK_H
#define STACK_H
const int maxStack=50;
typedef struct{
	int data[maxStack];
	int top;
}Stack; 
typedef struct{ 
	int data[maxStack];
	int top1;
	int top2;
}ShareStack;

void initShare(ShareStack* ss);
int ss_Full(ShareStack* ss);
void StackIntial(Stack *stack);
int StackEmpty(Stack* stack);
int Push(Stack *stack,int data);
int Pop(Stack *stack);
int GetTop(Stack stack);
void SetContent(Stack *stack,int nums[],int num);

void StackTest();
#endif
