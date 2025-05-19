
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0

#define ElemType int
#define	MAXSIZE  100   /*�˴��ĺ궨�峣����ʾ���Ա���ܴﵽ����󳤶�*/
typedef  struct
{ 
	ElemType  elem[MAXSIZE];  /*���Ա�ռ�õ�����ռ�*/
	int  last;    /*��¼���Ա������һ��Ԫ��������elem[ ]�е�λ�ã��±�ֵ�����ձ���Ϊ-1*/
}SeqList;

/*��˳���L�е�i������Ԫ��֮ǰ����һ��Ԫ��e�� ����ǰ��n=L->last+1��
i�ĺϷ�ȡֵ��Χ�� 1��i��L->last+2  */
int  InsList(SeqList *L,int i,ElemType e)
{ 
	int k;
	if((i<1) || (i>L->last+2)) /*�����жϲ���λ���Ƿ�Ϸ�*/
	{
		printf("����λ��iֵ���Ϸ�");
		return(ERROR);
	}
	if(L->last>= MAXSIZE-1)
	{
		printf("�������޷�����");
		return(ERROR);
	}
	for(k=L->last;k>=i-1;k--)   /*Ϊ����Ԫ�ض��ƶ�λ��*/
		L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;   /*��C���������У���i��Ԫ�ص��±�Ϊi-1*/
	L->last++;
	return(OK);
}



int DelList(SeqList *&L, int i){
	if((i<1) || (i>L->last+1)) /*�����ж�λ���Ƿ�Ϸ�*/
	{
		printf("λ��iֵ���Ϸ�\n");
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
			printf("���Ա�Ϊ��/n");
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
	printf("���������Ա�ĳ���:");
	scanf("%d",&r);
	l->last = r-1;
	printf("���������Ա�ĸ�Ԫ��ֵ:\n");
	for(i=0; i<=l->last; i++)
	{
		scanf("%d",&l->elem[i]);
	}
	
	//��ӡ���˳��������Ԫ��
	printf("��ӡ���˳����������Ԫ��\n"); 
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
    //��������Ԫ�� 
	printf("\n\n������Ҫ�����λ��:\n");
	scanf("%d",&p);
	printf("������Ҫ�����Ԫ��ֵ:\n");
	scanf("%d",&q);	
	InsList(l,p,q);	
	printf("��ӡ���˳����������Ԫ��\n"); 
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
	
	//ɾ������Ԫ�� 	
	printf("\n\n������Ҫɾ��Ԫ�ص�λ��:");
	scanf("%d",&r);	
	DelList(l,r);	
	printf("��ӡ���˳����������Ԫ��\n"); 
	
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
		
	printf("\n\n������Ҫ����Ԫ�ص�ֵ:");
	ElemType e;
	scanf("%d",&e);	
	int loc=Locate(l,e);
	printf("��Ҫ���ҵ�����Ԫ��λ��Ϊ�� %d ",loc);		
}
	

	

