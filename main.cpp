#include <iostream>
#include"main.h"


int show(int data[]){
	for(int i=0;i<10;i++){
		//TODO
		printf("%d ",data[i]);
	}
	putchar('\n');
}
int main(int argc, char** argv) {
//	SqlistTest();
//	NodeTest();
//	BiTreeTest();
//	BSNodeTest();
//	ThreadNodeTest();
//	Queue.Test();
//	CSTNodeTest();
	
	int data[10]={22,1,2,3,4,5,6,7,8,9};
	int *p=data;
	printf("%d\n",*(++p));
	show(data);
	printf("\n%d",*p);
}

