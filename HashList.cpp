#include"HashList.h"
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"Node.h"
#define MAX 100
#define empty 10000
#define error -100
int HashSeq[MAX]={1000};
Node HashLink[MAX];
static const int linerD[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
static const int quadraD[20]={1,-1,4,-4,9,-9,16,-16,25,-25,36,-36,49,-49,64,-64,81,-81,100,-100};
static int tlength=0;
static int p=0;
void initialHash(){
	for(int i=0;i<MAX;i++){
		//TODO
		HashSeq[i]=empty;
		HashLink[i].next=NULL;
	}
}
int Hash(int data){return data%p;}
int linerDetect(int Hbase,int index){
	if(index>=20||linerD[index]>=tlength)return error;
	else return (Hbase+linerD[index])%tlength; 
}
int quardraDetect(int Hbase,int index){
	if(index>20)return error;
	else{
		int k;
		if(quadraD[index]<0){
			//TODO
			k=sqrt(-quadraD[index]);
		}else k=sqrt(quadraD[index]);
		if(k>tlength/2){
			//TODO
			return error;
		}else{
			int result=(Hbase+quadraD[index])%tlength;
			while(result<0){
				//TODO
				result+=tlength;
			}
			return result;
		}
	}
}

bool insertSeq(int data,enum Type type){
	int Hbase=Hash(data);
	if(HashSeq[Hbase]==empty){
		//TODO
		HashSeq[Hbase]=data;
		return true;
	}else{//非空开始探测
		int index=0;
		while(index<20){
			//TODO
			int result;
			if(type==liner){
				//TODO
				result=linerDetect(Hbase,index);
			}else{
				result=quardraDetect(Hbase,index);
			}
			if(result==error){
				//TODO
				return false;
			}else{
				if(HashSeq[result]==empty){
					//TODO
					HashSeq[result]=data;
					return true;
				}else{
					index++;
				}
			}
		}
		return false;
	}
}
void insertLink(int data){
	Node* p;
	int Hbase=Hash(data);
	if(HashLink[Hbase].next==NULL){
		//TODO
		p=(Node*)malloc(sizeof(Node));
		p->data=data;
		p->next=NULL;
		HashLink[Hbase].next=p;
	}else{
		p=HashLink[Hbase].next;
		while(p->next!=NULL){
			//TODO
			p=p->next;
		}
		p->next=(Node*)malloc(sizeof(Node));
		p=p->next;
		p->data=data;
		p->next=NULL;
	}
}
void showHashSeq(){
	printf("开放地址法哈希表：\n");
	for(int i=0;i<tlength;i++){
		//TODO
		printf("index %3d:%d\n",i,HashSeq[i]);
	}
	putchar('\n');
}
void showHashLink(){
	printf("链接地址法哈希表：\n");
	for(int i=0;i<tlength;i++){
		//TODO
		printf("index %2d:",i);
		Node* p=&HashLink[i];
		p=p->next;
		while(p!=NULL){
			//TODO
			printf("%2d ",p->data);
			p=p->next;
		}
		putchar('\n');
	}
	putchar('\n');
}
bool CreateHashSeq(int data[],int num,Type type){
	for(int i=0;i<num;i++){
		//TODO
		if(insertSeq(data[i],type)==false)return false;
	}
	return true;
}
void CreateHashLink(int data[],int num){
	for(int i=0;i<num;i++){
		//TODO
		insertLink(data[i]);
	}
}

int searchHashSeq(int data,Type type){
	int Hbase=Hash(data);
	int index=Hbase;
	if(HashSeq[Hbase]==data)return Hbase;
	else{
		if(type==liner){
			//TODO
			for(int i=0;i<tlength&&HashSeq[index]!=empty;i++){
				//TODO
				index=linerDetect(Hbase,i);
				if(HashSeq[index]==data)return index;
			}
		}else{
			for(int i=0;index!=error&&HashSeq[index]!=empty;i++){
				//TODO
				index=quardraDetect(Hbase,i);
				if(HashSeq[index]==data&&index!=error)return index;
			}
		}
	}
	return -1;
}
int searchHashLink(int data){
	int Hbase=Hash(data);
	Node* p=&HashLink[Hbase];
	p=p->next;
	while(p!=NULL){
		//TODO
		if(p->data==data){
			//TODO
			return Hbase;
		}
		p=p->next;
	}
	return -1;
}
void HashListTest(){
	initialHash();
	tlength=10;
	p=7;
	int data[]={7,14,28,35,42};
	CreateHashSeq(data,5,quadratic);
	showHashSeq();
	printf("%d",searchHashSeq(36,quadratic));
	
}
