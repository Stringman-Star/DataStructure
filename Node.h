#ifndef NODE_H
#define NODE_H
typedef struct Node{
	int data;
	struct Node* next;
}Node,*LinkList;

void createLink(LinkList head,int data[],int N);
void showList(LinkList head);
void laMinusLb(LinkList La,LinkList Lb,LinkList &Lc);
int biggestNode(LinkList head);
int getNum(LinkList head);
void NodeTest();
#endif
