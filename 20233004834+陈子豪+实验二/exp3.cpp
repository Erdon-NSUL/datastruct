#include<stdio.h>
#define  TRUE 1
#define  FALSE 0
#define  QueueElementType int
#include<iostream>
using namespace std;
#define MAXSIZE 50  /*���е���󳤶�*/

typedef struct
{
	QueueElementType  element[MAXSIZE];  /* ���е�Ԫ�ؿռ�*/
	int front;  /*ͷָ��ָʾ��*/
	int rear;  /*βָ��ָʾ��*/
}SeqQueue;


/*��ʼ������*/
void InitQueue(SeqQueue *Q)
{  
	/* ��*Q��ʼ��Ϊһ���յ�ѭ������ */
	Q->front=Q->rear=0;
}

/*��Ӳ���*/
int EnterQueue(SeqQueue *Q, QueueElementType x)
{	if ((Q->front+1)%MAXSIZE != Q->rear){
		Q->element[Q->front] = x;
		Q->front = (Q->front+1)%MAXSIZE;
		return 1;
	}
	else{
		cout << "��������" << endl;
		return 0;
	}
	
}

/*���Ӳ���*/
int DeleteQueue(SeqQueue *Q, QueueElementType *x)
{ 
	if(Q->front==Q->rear){  
		cout << "����Ϊ��";
		return 0;
	}
	else{
		*x = Q->element[Q->rear];
		Q->rear = (Q->rear+1)%MAXSIZE;
	}
}

int GetHead(SeqQueue *Q, QueueElementType *x)
{ 
	/*��ȡ���еĶ�ͷԪ�أ���x������ֵ*/
	if(Q->front==Q->rear)  /*����Ϊ��*/
		return(FALSE);
	*x=Q->element[Q->front];
	return(TRUE);  /*�����ɹ�*/
}

int IsEmpty(SeqQueue *Q)
{ 
	/*��ȡ���еĶ�ͷԪ�أ���x������ֵ*/
	if(Q->front==Q->rear)  /*����Ϊ��*/
		return(TRUE);
	else
		return(FALSE);  /*�����ɹ�*/
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
			cout << "��ӡ����:" << endl;
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
			cout << "�м���������У�" << endl;
			cin >> n;
			if(n>0){
				cout << "�����룺";
				for(int i = 0;i<n;i++){
					cin >> e;
					EnterQueue(&q,e);
				}
			}
			else{
				cout << "�м����������У�" << endl;
				cin >> n;
				if(n>0){
					for(int i = 0;i<n;i++){
						DeleteQueue(&q,&e);
					}
				}
				else{
					cout << "��ѡ���޶�����" ;
					return 0;
					}	
			}
		}
	}
	return 0;
}
