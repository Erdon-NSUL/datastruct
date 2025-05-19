#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0

typedef char ElemType;

typedef struct Node    /*������Ͷ���*/ 
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  /* LinkListΪ�ṹָ������*/


void init_linklist(LinkList *l)/*�Ե�������г�ʼ��*/
{
	*l=(LinkList)malloc(sizeof(Node)); 
	(*l)->next=NULL;
}


void CreateFromTail( LinkList  L)
{ 
	Node *r, *s;
	char c;
	int   flag =1; /*����һ����־����ֵΪ1��������"$"ʱ��flagΪ0���������*/
	r=L;      /*rָ�붯ָ̬������ĵ�ǰ��β���Ա�����β���룬���ֵָ��ͷ���*/
	while(flag)         /*ѭ���������Ԫ��ֵ���������½��s�����β*/
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
			r->next=NULL;   /*�����һ������next������Ϊ�գ���ʾ����Ľ���*/
		}
	}   
} 


Node *Get(LinkList  L, int i)
/*�ڴ�ͷ���ĵ�����L�в��ҵ�i����㣬���ҵ�(1��i��n)���򷵻ظý��Ĵ洢λ��; ���򷵻�NULL*/
{  
	int j;
	Node  *p;
	p=L;
	j=0;   /*��ͷ��㿪ʼɨ��*/ 
	while ((p->next!=NULL)&&(j<i))
	{ 
		p=p->next;    /* ɨ����һ���*/
		j++;   /* ��ɨ��������� */
	}
	if(i == j)		
		return p;   /* �ҵ��˵�i����� */
	else 
		return NULL;   /* �Ҳ�����i��0��i>n */
}   

int ListInsert(LinkList L){
	int i;
	char e;
	printf("������Ҫ����Ľ�����:\n");
		scanf("%d",&i);	
	Node *p,*ep;
	p = Get(L,i-1);
	if(p==NULL){
		printf("δ�ҵ��˽��!\n");
		return ERROR;
	}
	fflush(stdin);
	printf("������Ҫ�����ֵ��");
	scanf("%c",&e);
	ep = (Node *)malloc(sizeof(Node));
	ep->data = e;
	ep->next = p->next;
	p->next = ep;
	return OK;
}


int DeleteNode(LinkList L){
	int i;
	printf("������Ҫɾ���Ľ�����:");
	scanf("%d",&i);	
	Node *p,*del;
	p = Get(L,i-1);
	if(p==NULL || p->next == NULL){
		printf("δ�ҵ��˽��!\n");
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
	printf("��������������,��$����!\n");
	CreateFromTail(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	
	fflush(stdin);	
	printf("������Ҫ���ҵĽ�����:\n");
	scanf("%d",&j);
	p = Get(l,j);
	if(p!=NULL)
		printf("�ý���ֵΪ:%c\n",p->data);
	else
		printf("δ�ҵ��˽��!\n");
		
		
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
