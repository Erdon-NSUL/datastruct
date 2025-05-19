#include "stdio.h"
#include<iostream>
#define TRUE 1
#define FALSE 0
#define Stack_Size 50

#define StackElementType int

using namespace std;
/*˳��ջ*/

typedef struct
{
	StackElementType elem[Stack_Size]; /*�������ջ��Ԫ�ص�һά����*/
	int top;          		/*�������ջ��Ԫ�ص��±꣬topΪ-1��ʾ��ջ*/
}SeqStack;


/*��ʼ��*/
void InitStack(SeqStack *S)
{
	/*����һ����ջS*/
  	S->top = -1;
}

/*��ջ��*/
int IsEmpty(SeqStack *S) /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top==-1?TRUE:FALSE);
}

/*��ջ��*/
int IsFull(SeqStack *S)	/*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top==Stack_Size-1?TRUE:FALSE);
}

int Push(SeqStack *S,StackElementType x)
{
	if(IsFull(S)){
		cout << " ջ����";
		return 0;
	}else{
		S->elem[S->top+1] = x;
		S->top += 1;
		return 1;
	}
}

int Pop(SeqStack *S,StackElementType *x)
{  
	if(IsEmpty(S)){
			cout << " ջ�ѿ�";
			return 0;
		}else{
			*x = S->elem[S->top];
			S->top -=1;	
			return 1;
		}
}

/*ȡջ��Ԫ�ء�*/
int GetTop(SeqStack *S,StackElementType *x)
{  
	/* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��У���ջ��ָ�뱣�ֲ��� */
	if(S->top == -1)  /*ջΪ��*/
		return(FALSE);
	else
	{
  		*x = S->elem[S->top];
  		return(TRUE);
	}	
}

int D_to_B(SeqStack *S,StackElementType *x){
	InitStack(S);
	int  tmp,r;
	while((*x/2)+1 != 1){
		tmp = *x%2;
		Push(S,tmp);
		*x = (*x-tmp)/2;	
	}
	cout << "ת����1" ;
	for(int i = S->top;i > -1;i--){
		Pop(S,&r);
		cout << r;
	}
}

int main(){
	int e;
    SeqStack ss,sk;
    cout << "������Ҫ��ʮ����ת��Ϊ�����Ƶ�ֵ��" << endl;
    cin >> e;
    D_to_B(&sk,&e);
    /*InitStack(&ss);
    printf("input data:(Terminated by inputing a character)\n");
    while(scanf("%d",&e))
        Push(&ss,e);
    while(Pop(&ss,&e))
        printf("%3d",e);*/
    return 0;
}   
