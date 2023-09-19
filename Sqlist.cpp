#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"Sqlist.h"
int initializer_Sqlist(Sqlink p){
	p->data=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!p->data)return 0;
	p->length=0;
	p->listsize=LIST_INIT_SIZE;
	return 1;
	
}
int ListInsert(int index,int data,Sqlink p){
	if(!p)return 0;
	else if(index>p->length+1||index<1)return 0;
	else if(p->length>=p->listsize){
		int* newbase=(int*)realloc(p->data, (p->listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase)return 0;
		p->listsize+=10;
	}
	if(p->length==index-1){
		p->data[p->length++]=data;
	}else{
		for(int i=p->length;i>=index-1;i--){
			p->data[i+1]=p->data[i];
		}	
		p->data[index]=p->data[index-1];
		p->data[index-1]=data;
		p->length++;
	}
	return 1;
}
int ListDelete(Sqlink p,int index){
	if(!p)return 0;
	else if(index<1||index>p->length+1)return 0;
	else{
		for(int i=index-1;i<=p->length-1;i++){
			p->data[i]=p->data[i+1];
		}
		p->length--;
	}
	return 1;
}
int LocateElem(int data,Sqlink p){
	for(int i=0;i<p->length;i++){
		if(p->data[i]==data){
			return i+1;
		}
	}
	return 0;
}
int update(Sqlink p,int index,int data){
	if(!p)return 0;
	else if(index<1||index>p->length)return 0;
	else{
		p->data[index-1]=data;
	}
	return 1;
}
void print_all(Sqlink p){
	printf("data:");
	for(int i=0;i<p->length;i++){
		printf("%d ",p->data[i]);
	}
	printf("\nlength=%d\nlistsize=%d\n",p->length,p->listsize);
}
void SetContent(Sqlink p){
	srand((int)time(NULL));
	int nums[10]{1,2,3,3,3,4,5,5,6,6};
//	for(int i=0;i<num;i++){
//		//TODO
//		nums[i]=rand()%101;
//	}
	//输入数据
	for(int i=0;i<10;i++){
		ListInsert(i,nums[i],p);
	}
}
void MergeList(Sqlist A,Sqlist B,Sqlink C){
	if(A.length==0&&B.length==0){
		return;
	}else{
		int i=0,j=0,min=0;
		while(i<A.length&&j<B.length){
			C->data[min++]=(A.data[i]<B.data[j]?A.data[i++]:B.data[j++]);
		}
		while(i<A.length){
			C->data[min++]=A.data[i++];
		}
		while(j<B.length){
			C->data[min++]=B.data[j++];
		}
		C->length=min;
		return ;
	}
}
void MergeB2A(Sqlink A,Sqlink B){
	int i=A->length-1;
	int j=0;
	A->length=A->length+B->length;
	int p=A->length-1;
	while(j<B->length&&i>=0){
		//TODO
		if(A->data[i]>B->data[j]){
			//TODO
			A->data[p]=A->data[i];
			i--;
			p--;
		}else if(A->data[i]<B->data[j]){
			//TODO
			A->data[p]=B->data[j];
			j++,p--;
		}else{
			A->data[p]=A->data[i];
			p--,i--,j++;
		}
	}
}
int deleteElem2(int s,int t,Sqlist* L){
	if(s>t)return -1;
	int Curlength=0,p=0;
	while(p<L->length){
		//TODO
		if(L->data[p]<s||L->data[p]>t){
			//TODO
			L->data[Curlength]=L->data[p];
			p++,Curlength++;
		}else{
			p++;
		}
	}
	L->length=Curlength;
	return 1;
} 

//example 6
void deleteElem(int s,int t,Sqlist *L){
	if(s>t)return;
	int i=0,j=L->length-1;
	int flag;
	while(1){
		flag=0;
		if(L->data[i]<s){
			i++;
			flag=1;
		}
		if(L->data[j]>t){
			j--;
			flag=1;
		}
		if(flag==0||i>j){//说明此时data[i]已经大于s并且data[j]小于t,要么里面所有元素都小于s大于t
			break;
		}
	}
	if(i>j){
		//TODO
		return;
	}
	j++;//j在第一个>t的元素上，i在第一个>s的元素上
	while(j<L->length){
		L->data[i]=L->data[j];
		i++,j++;
	}
	L->length=i;
}

void deleterep(Sqlink sql){
	int curLength=0;
	int p=1;
	while(p<sql->length){
		//TODO
		if(sql->data[curLength]!=sql->data[p]){
			//TODO
			sql->data[++curLength]=sql->data[p++];
		}else p++;
	}
	sql->length=curLength+1;
}

void SqlistTest(){//测试接口
	Sqlink sql=(Sqlink)malloc(sizeof(Sqlist));
	initializer_Sqlist(sql);
	SetContent(sql);
	print_all(sql);
	deleterep(sql);
	print_all(sql);
}
