#include "stdio.h"
#include<iostream>
#define TRUE 1
#define FALSE 0
#define Stack_Size 50

#define StackElementType int

using namespace std;
/*顺序栈*/

typedef struct
{
	StackElementType elem[Stack_Size]; /*用来存放栈中元素的一维数组*/
	int top;          		/*用来存放栈顶元素的下标，top为-1表示空栈*/
}SeqStack;


/*初始化*/
void InitStack(SeqStack *S)
{
	/*构造一个空栈S*/
  	S->top = -1;
}

/*判栈空*/
int IsEmpty(SeqStack *S) /*判断栈S为空栈时返回值为真，反之为假*/
{
	return(S->top==-1?TRUE:FALSE);
}

/*判栈满*/
int IsFull(SeqStack *S)	/*判断栈S为满栈时返回值为真，反之为假*/
{
	return(S->top==Stack_Size-1?TRUE:FALSE);
}

int Push(SeqStack *S,StackElementType x)
{
	if(IsFull(S)){
		cout << " 栈已满";
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
			cout << " 栈已空";
			return 0;
		}else{
			*x = S->elem[S->top];
			S->top -=1;	
			return 1;
		}
}

/*取栈顶元素。*/
int GetTop(SeqStack *S,StackElementType *x)
{  
	/* 将栈S的栈顶元素弹出，放到x所指的存储空间中，但栈顶指针保持不变 */
	if(S->top == -1)  /*栈为空*/
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
	cout << "转换后：1" ;
	for(int i = S->top;i > -1;i--){
		Pop(S,&r);
		cout << r;
	}
}

int main(){
	int e;
    SeqStack ss,sk;
    cout << "请输入要从十进制转换为二进制的值：" << endl;
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
