#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
void initShare(ShareStack* ss){
	ss->top1=0;
	ss->top2=maxStack-1;
}
int ss_Full(ShareStack* ss){
	return ss->top1+1==ss->top2;
}
void StackIntial(Stack *stack){
	stack->top=0;
}
int StackEmpty(Stack* stack){
	return !stack->top==0;
}

int Push(Stack *stack,int data){
	if(stack->top>=maxStack-1){
		return 0;
	}else{
		stack->data[stack->top++]=data;
		return 1;
	}
}
int Pop(Stack *stack){
	if(stack->top<=0){
		return 0;
	}else{
		return stack->data[--stack->top];	
	}
}

int GetTop(Stack stack){
	if(stack.top==0){
		return 0;
	}else{
		return stack.data[stack.top-1];
	}
}
void SetContent(Stack *stack,int nums[],int num){
	for(int i=0;i<num;i++){
		Push(stack,nums[i]);
	}
}
void StackTest(){
	//TODO
}
