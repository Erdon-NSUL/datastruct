#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0

typedef char ElemType;

typedef struct Node    /*结点类型定义*/ 
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  /* LinkList为结构指针类型*/


void init_linklist(LinkList *l)/*对单链表进行初始化*/
{
	*l=(LinkList)malloc(sizeof(Node)); 
	(*l)->next=NULL;
}


void CreateFromTail( LinkList  L)
{ 
	Node *r, *s;
	char c;
	int   flag =1; /*设置一个标志，初值为1，当输入"$"时，flag为0，建表结束*/
	r=L;      /*r指针动态指向链表的当前表尾，以便于做尾插入，其初值指向头结点*/
	while(flag)         /*循环输入表中元素值，将建立新结点s插入表尾*/
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node));
			s->data=c;
			r->next=s;
			r=s;
		}
		else
		{
			flag=0;
			r->next=NULL;   /*将最后一个结点的next链域置为空，表示链表的结束*/
		}
	}   
} 


Node *Get(LinkList  L, int i)
/*在带头结点的单链表L中查找第i个结点，若找到(1≤i≤n)，则返回该结点的存储位置; 否则返回NULL*/
{  
	int j;
	Node  *p;
	p=L;
	j=0;   /*从头结点开始扫描*/ 
	while ((p->next!=NULL)&&(j<i))
	{ 
		p=p->next;    /* 扫描下一结点*/
		j++;   /* 已扫描结点计数器 */
	}
	if(i == j)		
		return p;   /* 找到了第i个结点 */
	else 
		return NULL;   /* 找不到，i≤0或i>n */
}   

int ListInsert(LinkList L){
	int i;
	char e;
	printf("请输入要插入的结点序号:\n");
		scanf("%d",&i);	
	Node *p,*ep;
	p = Get(L,i-1);
	if(p==NULL){
		printf("未找到此结点!\n");
		return ERROR;
	}
	fflush(stdin);
	printf("请输入要插入的值：");
	scanf("%c",&e);
	ep = (Node *)malloc(sizeof(Node));
	ep->data = e;
	ep->next = p->next;
	p->next = ep;
	return OK;
}


int DeleteNode(LinkList L){
	int i;
	printf("请输入要删除的结点序号:");
	scanf("%d",&i);	
	Node *p,*del;
	p = Get(L,i-1);
	if(p==NULL || p->next == NULL){
		printf("未找到此结点!\n");
		return ERROR;
	}
	del = p->next;
	p->next = del->next;
	del->next = NULL;
	free(del);
	return OK;
}


void DestroyList(LinkList L) {
    Node *p = L;
    while (p != NULL) {
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
}



int main()
{
	LinkList l;
	Node *p;
	int j;
	init_linklist(&l);
	printf("请输入链表数据,以$结束!\n");
	CreateFromTail(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	
	fflush(stdin);	
	printf("请输入要查找的结点序号:\n");
	scanf("%d",&j);
	p = Get(l,j);
	if(p!=NULL)
		printf("该结点的值为:%c\n",p->data);
	else
		printf("未找到此结点!\n");
		
		
	fflush(stdin);
    ListInsert(l);
    p = l->next;
    while(p!=NULL)
		{
			printf("%c\n",p->data);
			p=p->next;
		}
    

    fflush(stdin);
	DeleteNode(l);
	p = l->next;
	while(p!=NULL){
		printf("%c\n",p->data);
		p=p->next;
	}
    
    DestroyList(l);
}
