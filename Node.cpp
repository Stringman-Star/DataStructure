#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include"Node.h"

void createLink(LinkList head,int data[],int N){
	LinkList p;
	p=head;
	for(int i=0;i<N;i++){
		//TODO
		p->next=(LinkList)malloc(sizeof(Node));
		p=p->next;
		p->data=data[i];
		p->next=NULL;
	}
}
void showList(LinkList head){
	while(head->next!=NULL){
		//TODO
		head=head->next;
		printf("%d ",head->data);
	}
	printf("\n");
}


/*
  Lc=La-Lb
  La增，Lb增
 */
void laMinusLb(LinkList La,LinkList Lb,LinkList &Lc){
	Lc=(LinkList)malloc(sizeof(Node));
	LinkList a=La->next,b=Lb->next,c=Lc;
	while(a!=NULL&&b!=NULL){
		//TODO
		if(a->data<b->data){
			//TODO
			c->next=(LinkList)malloc(sizeof(Node));
			c=c->next;
			c->data=a->data;
			c->next=NULL;
			a=a->next;
		}else if(a->data>b->data){
			//TODO
			b=b->next;
		}else{
			a=a->next;
			b=b->next;
		}
	}
}

int biggestNode(LinkList head){
	if(head==NULL) return -1;//假如传入的头指针节点为空则直接终止
	if(head->next==NULL){//判断是否为最后一个节点
		//TODO
		return 0;
	}else{
		int data=head->next->data;//获取当前节点的值
		return biggestNode(head->next)>data?biggestNode(head->next):data;
		//如果当前节点子链中有更大的节点，则返回更大的节点
	}
}

int getNum(LinkList head){
	if(head->next==NULL){
		//TODO
		return 0;
	}else{
		return getNum(head->next)+1;
	}
}
int getSum(LinkList head){
	if(head->next==NULL){
		//TODO
		return 0;
	}else{
		int data=head->next->data;
		return getSum(head->next)+data;
	}
}

void getAvg(LinkList head){
	printf("%d\n",getSum(head));
	printf("%lf",(1.0*getSum(head)/getNum(head)));
}

Node* getPre(LinkList head,int index){
	Node* p=head,*pre=head;
	for(int i=0;i<index;i++&&p!=NULL,pre=p,p=p->next){
		//TODO
	}
	return (p==NULL)?NULL:pre;
}


Node* getNode(LinkList L,int index){
	Node* p=L,*pre=NULL;
	int cnt=0;
	while(p!=NULL){
		//TODO
		if(index==cnt)break;
		cnt++;
		pre=p;
		p=p->next;
	}
	if(cnt==index)return pre;
	return NULL;
}

bool insert(int index,LinkList head,Node* e){
	if(index<1)return false;
	Node *p=head,*pre=NULL;
//	int cnt=0;
//	while(cnt<index&&p!=NULL){
//		//TODO
//		pre=p;
//		p=p->next;
//		cnt++;
//	}
	for(int i=0;i<index;i++,pre=p,p=p->next){
		//TODO
		if(!p)return false;
	}
	e->next=p;
	pre->next=e;
	return true;
}


/*
  算法思想：
	  先让rear进入链表，在rear到达第index个元素的时候，p才进入链表，之后和rear一起递归，直到rear到达尾部，
	  倘若链表中不存在倒数m个元素，则p为空
 */
bool invertNode(LinkList head,int index,Node*& node){
	if(!head||index<1)return false;//若链表为空或者给定数字小于等于0则返回false;
	LinkList rear=head;//rear用于寻找尾节点
	node=head;//node指向目标节点
	int cnt=0;//计数器
	while(rear){//当rear指向Null的时候，node刚好指向倒数第index个数据节点
		//TODO
		if(cnt>=index){//仅当cnt>=index时候，node节点才会进入遍历,此时rear指向第m个数据节点
			//TODO
			node=node->next;//当rear已经指向第m个数据节点或者之后的时候，node进入或者跟从rear
		}
		rear=rear->next;//rear往后遍历
		cnt++;//节点编号+1
	}
	if(node==head){//如果没有倒数第m个节点，返回false
		//TODO
		return false;
	}else{//否则输出值并且返回true
		printf("%d",node->data);
		return true;
	}
}
//删除A中同时出现在C和D中的结点
void LAminusLbNLc(LinkList La,LinkList Lb,LinkList Lc){
	Node* pCurA=La->next,*pCurB=Lb->next,*pCurC=Lc->next;
	Node* pre=La;
	int a,b,c;
	while(pCurA!=NULL&&pCurB!=NULL&&pCurC!=NULL){
		a=pCurA->data,b=pCurB->data,c=pCurC->data;
		while(b>a){//保证B节点在前
			//TODO
			pCurB=pCurB->next;
			if(pCurB==NULL)return;
			b=pCurB->data;
		}
		while(c>a){//保证C节点在前
			//TODO
			pCurC=pCurC->next;
			if(pCurC==NULL)return;
			c=pCurC->data;
		}
		if(b>c){//保证B与C跑到了一个一样的值的地方
			//TODO
			pCurB=pCurB->next;
			continue;
		}else if(c>b){
			//TODO
			pCurC=pCurC->next;
			continue;
		}
		while(a>b&&a>c){//若此时A落后于B与C则开始追赶
			//TODO
			pre=pCurA;
			pCurA=pCurA->next;
			if(pCurA==NULL)return;
			a=pCurA->data;
		}
		while(a==b&&a==c){//假如追赶到了有一样的值则开始删除，删完后A大于B和C，以此实现BC的推动
			//TODO
			pre->next=pCurA->next;
			pCurA=pre->next;
			if(pCurA==NULL)return;
			a=pCurA->data;
		}
	}
}

void oper(LinkList &La,LinkList &Lb,int j,int len){
	LinkList heada=(LinkList)malloc(sizeof(Node));
	LinkList headb=(LinkList)malloc(sizeof(Node));
	heada->next=La;
	headb->next=Lb;
	La=heada,Lb=headb;
	showList(La);
	showList(Lb);
	LinkList aH,aR,bH,p;
	aH=getPre(La,j);
	aR=getPre(La,j+len);
	bH=getPre(Lb,j);
	p=aH->next;
	aH->next=aR->next;
	aR->next=bH->next;
	bH->next=p;
	showList(La);
	showList(Lb);
	p=La;
	La=La->next;
	free(p);
	p=Lb;
	Lb=Lb->next;
	free(p);
}

//插入到有序区
void insert(LinkList L,Node* p){
	LinkList pCur=L;
	while(1){
		if(pCur->next->data==p->data){
			//TODO
			free(p);
			return;
		}
		if(pCur->next->data>p->data){
			//TODO
			p->next=pCur->next;
			pCur->next=p;
			return;
		}
		pCur=pCur->next;
	}
}
void insertSort(LinkList L){
	LinkList pCur=L->next,pre=L;
	int max=-0xffff;
	while(pCur!=NULL){
		//TODO
		if(pCur->data>max){//若小于排列好的区间的最大值，即最右边的节点，就调用函数插入
			//TODO
			max=pCur->data;
			pre=pCur;
		}else{//若大于最大的值，则直接进行插入，且更新max值
			pre->next=pCur->next;
			insert(L,pCur);
		}
		pCur=pre->next;
	}
}

/*
  例18
  题中代码是看A中有没有B的子串
  BF算法
 */
bool match(LinkList La,LinkList Lb){
	LinkList index=La->next,moveA=index,moveB=Lb->next;
	/*
	  @param	index用来遍历母串
	  @param	moveA用于在第一个匹配到之后开始出发遍历后续是否相同
	  @param	moveB用于遍历子串
	 */
	while(moveA!=NULL&&moveB!=NULL){
		//TODO
		if(moveA->data!=moveB->data){
			//TODO
			index=index->next;//出现不匹配后，母串开始往后挪位
			moveA=index;
			moveB=Lb->next;//子串回到第一个节点
		}else{
			moveA=moveA->next;
			moveB=moveB->next;
		}
	}
	return moveB==NULL?true:false;
}


//例题17
void spiltAtX(LinkList L,int x){
	LinkList pdata=L->next,tmp;//剥离所有数据节点
	L->next=NULL;//create an empty Link
	Node* X=(LinkList)malloc(sizeof(Node));//make a Node X
	X->data=x;
	X->next=NULL;
	L->next=X;//insert the X to the tail of the new Link 
	Node* PreX=L;//a ptr points to the pre Node pointing at X
	while(NULL!=pdata){
		//TODO
		tmp=pdata;//every time get one stastic node from the link
		pdata=pdata->next;
		if(tmp->data==x){//if the node's data equal to x,then insert to the pre of X,
			//TODO
			tmp->next=PreX->next;
			PreX->next=tmp;
		}else if(tmp->data<x){//if less than x,insert to front of x,nearby the ptr L
			//TODO
			tmp->next=PreX->next;
			PreX->next=tmp;
			PreX=tmp;
		}else{//if more ,insert to behind of the x,nearby the node X
			tmp->next=X->next;
			X->next=tmp;
		}
	}
	while(PreX->next!=X){
		//TODO
		PreX=PreX->next;
	}
	PreX->next=X->next;
	free(X);
}

Node* getCommonNode(LinkList La,LinkList Lb){
	Node* p1=La,*p2=Lb;//辅助指针
	while(p1!=NULL&&p2!=NULL){
		//TODO
		p1=p1->next;
		p2=p2->next;
	}//短的遍历完，而长的还没
	Node* longLine=NULL,*shortLine=NULL;//长短两指针，一个指向长串，一个指向短串
	if(p1==NULL){
		//TODO
		longLine=Lb;
		while(p2!=NULL){
			//TODO
			p2=p2->next;
			longLine=longLine->next;
		}
		shortLine=La;
	}else if(p2==NULL){
		//TODO
		longLine=La;
		while(p1!=NULL){
			//TODO
			p1=p1->next;
			longLine=longLine->next;
		}
		shortLine=Lb;
	}
	//此时长指针和短指针指向离尾结点相同距离的位置
	while(longLine!=shortLine&&longLine!=NULL){//一起开始遍历,直到找到共同节点才停止
		//TODO
		longLine=longLine->next;
		shortLine=shortLine->next;
	}
	return longLine;//返回找到的共同节点
}

bool convert(LinkList L,int n){
	Node* top=NULL,*bottom=NULL;
	Node* pCur=L;
	//获取L链中的中间节点n/2
	for(int i=0;i<=n/2;i++&&pCur!=NULL,pCur=pCur->next);
	//如果链表长度小于n/2则直接退出
	if(pCur==NULL)return false;
	//分别获取前一半链和尾一半链
	top=L->next;
	bottom=pCur->next;
	pCur->next=NULL;
	//开始使用头插法对后一半进行逆置操作
	L->next=NULL;
	while(bottom!=NULL){
		//TODO
		pCur=bottom;
		bottom=bottom->next;
		pCur->next=L->next;
		L->next=pCur;
	}
	bottom=L->next;
	//开始用尾插的方式合并两表
	Node* tail=L,*tmp=NULL;
	while(top!=NULL&&bottom!=NULL){
		//TODO
		tmp=top;
		top=top->next;
		tail->next=tmp;
		tail=tail->next;
		
		tmp=bottom;
		bottom=bottom->next;
		tail->next=tmp;
		tail=tail->next;
	}
	if(top!=NULL){
		//TODO
		tail->next=top;
	}
	if(bottom!=NULL){
		//TODO
		tail->next=bottom;
	} 
	return true;
}

void NodeTest(){//测试接口
	LinkList La=(LinkList)malloc(sizeof(Node));
	int data1[]={1,2,3,4,5,6,7,8,9};
	createLink(La,data1,sizeof(data1)/sizeof(*data1));
	LinkList Lb=(LinkList)malloc(sizeof(Node));
	int data2[]={3,2,2};
	createLink(Lb,data2,sizeof(data2)/sizeof(*data2));
	LinkList Lc=(LinkList)malloc(sizeof(Node));
	int data3[]={1,2,2,1,2,3,5,7,9,4,4,33,7,2,3,666,11,3,3,2};
	createLink(La,data1,sizeof(data1)/sizeof(*data1));
	convert(La,sizeof(data1)/sizeof(*data1));
	showList(La);
}
