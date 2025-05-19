
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0

#define ElemType int
#define	MAXSIZE  100   /*此处的宏定义常量表示线性表可能达到的最大长度*/
typedef  struct
{ 
	ElemType  elem[MAXSIZE];  /*线性表占用的数组空间*/
	int  last;    /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为-1*/
}SeqList;

/*在顺序表L中第i个数据元素之前插入一个元素e。 插入前表长n=L->last+1，
i的合法取值范围是 1≤i≤L->last+2  */
int  InsList(SeqList *L,int i,ElemType e)
{ 
	int k;
	if((i<1) || (i>L->last+2)) /*首先判断插入位置是否合法*/
	{
		printf("插入位置i值不合法");
		return(ERROR);
	}
	if(L->last>= MAXSIZE-1)
	{
		printf("表已满无法插入");
		return(ERROR);
	}
	for(k=L->last;k>=i-1;k--)   /*为插入元素而移动位置*/
		L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;   /*在C语言数组中，第i个元素的下标为i-1*/
	L->last++;
	return(OK);
}



int DelList(SeqList *&L, int i){
	if((i<1) || (i>L->last+1)) /*首先判断位置是否合法*/
	{
		printf("位置i值不合法\n");
		return(ERROR);
	}
	i--;
	for(int j = i;j<L->last;j++){
		L->elem[j] = L->elem[j+1];
	}	
	L->last--;
	return (OK);
}

int Locate(SeqList *L, ElemType e){
	int i=0;
	if(L->last < 0){
			printf("线性表为空/n");
			return(ERROR);
		}
	for(i;i<=L->last;i++){
		if(e == L->elem[i]){
			return i+1;
		}
	}
	if(i>L->last){
		return -1;
	}
}


int main(){
	SeqList *l;
	int p,q,r;
	int i;
	l=(SeqList*)malloc(sizeof(SeqList));
	printf("请输入线性表的长度:");
	scanf("%d",&r);
	l->last = r-1;
	printf("请输入线性表的各元素值:\n");
	for(i=0; i<=l->last; i++)
	{
		scanf("%d",&l->elem[i]);
	}
	
	//打印输出顺序表的数据元素
	printf("打印输出顺序表各个数据元素\n"); 
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
    //插入数据元素 
	printf("\n\n请输入要插入的位置:\n");
	scanf("%d",&p);
	printf("请输入要插入的元素值:\n");
	scanf("%d",&q);	
	InsList(l,p,q);	
	printf("打印输出顺序表各个数据元素\n"); 
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
	
	//删除数据元素 	
	printf("\n\n请输入要删除元素的位置:");
	scanf("%d",&r);	
	DelList(l,r);	
	printf("打印输出顺序表各个数据元素\n"); 
	
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
		
	printf("\n\n请输入要查找元素的值:");
	ElemType e;
	scanf("%d",&e);	
	int loc=Locate(l,e);
	printf("你要查找的数据元素位置为： %d ",loc);		
}
	

	

