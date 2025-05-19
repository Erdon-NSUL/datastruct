#include<stdio.h>
#define  TRUE 1
#define  FALSE 0
#define  QueueElementType int
#include<iostream>
using namespace std;
#define MAXSIZE 50  /*队列的最大长度*/

typedef struct
{
	QueueElementType  element[MAXSIZE];  /* 队列的元素空间*/
	int front;  /*头指针指示器*/
	int rear;  /*尾指针指示器*/
}SeqQueue;


/*初始化操作*/
void InitQueue(SeqQueue *Q)
{  
	/* 将*Q初始化为一个空的循环队列 */
	Q->front=Q->rear=0;
}

/*入队操作*/
int EnterQueue(SeqQueue *Q, QueueElementType x)
{	if ((Q->front+1)%MAXSIZE != Q->rear){
		Q->element[Q->front] = x;
		Q->front = (Q->front+1)%MAXSIZE;
		return 1;
	}
	else{
		cout << "队列已满" << endl;
		return 0;
	}
	
}

/*出队操作*/
int DeleteQueue(SeqQueue *Q, QueueElementType *x)
{ 
	if(Q->front==Q->rear){  
		cout << "队列为空";
		return 0;
	}
	else{
		*x = Q->element[Q->rear];
		Q->rear = (Q->rear+1)%MAXSIZE;
	}
}

int GetHead(SeqQueue *Q, QueueElementType *x)
{ 
	/*提取队列的队头元素，用x返回其值*/
	if(Q->front==Q->rear)  /*队列为空*/
		return(FALSE);
	*x=Q->element[Q->front];
	return(TRUE);  /*操作成功*/
}

int IsEmpty(SeqQueue *Q)
{ 
	/*提取队列的队头元素，用x返回其值*/
	if(Q->front==Q->rear)  /*队列为空*/
		return(TRUE);
	else
		return(FALSE);  /*操作成功*/
}
void PrintQueue(SeqQueue *Q)
{
    QueueElementType  f; 
    f=Q->front; 
    while(f!=Q->rear)
	{
        printf("%5d",Q->element[f]);
        f=(f+1)% MAXSIZE;
    }
}

void PrintTest(SeqQueue *Q)
{
    QueueElementType  f; 
    f=Q->rear; 
    while(f!=Q->front)
	{
        cout << Q->element[f];
        f=(f+1)% MAXSIZE;
    }
}
/*PrintList*/

int main(){
	SeqQueue q;
	int e,n,p;
	InitQueue(&q);
	for(int i = 0;i<11;i++){
		if(i%2 != 0){
			cout << "打印队列:" << endl;
		 	p = q.rear;
		 	while(p != q.front){
			 	cout <<q.element[p];
			 	if (p+1 != q.front){cout<<",";}
			 	p += 1;
			}
			cout << endl;
			cout << endl;
		}
		else{
			cout << "有几个数入队列？" << endl;
			cin >> n;
			if(n>0){
				cout << "请输入：";
				for(int i = 0;i<n;i++){
					cin >> e;
					EnterQueue(&q,e);
				}
			}
			else{
				cout << "有几个数出队列？" << endl;
				cin >> n;
				if(n>0){
					for(int i = 0;i<n;i++){
						DeleteQueue(&q,&e);
					}
				}
				else{
					cout << "你选择无动于衷" ;
					return 0;
					}	
			}
		}
	}
	return 0;
}
