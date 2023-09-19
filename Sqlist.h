#ifndef SQLIST_H
#define SQLIST_H
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef struct{
	int *data;
	int length;
	int listsize;
}Sqlist,*Sqlink;//sqlink为指针变量
int update(Sqlink p,int index,int data);
void print_all(Sqlink p);
void MergeList(Sqlist A,Sqlist B,Sqlink C);
int LocateElem(int data,Sqlink p);
void SetContent(Sqlink p,int nums[],int num);
int update(Sqlink p,int index,int data);
int initializer_Sqlist(Sqlink p);
int ListInsert(int index,int data,Sqlink p);
int ListDelete(Sqlink p,int index);
void SqlistTest();//测试接口
#endif
