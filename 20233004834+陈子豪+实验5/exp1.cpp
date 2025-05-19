#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include<bits/stdc++.h>

typedef char DataType;

typedef struct Node
{
	DataType data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;


void CreateBiTree(BiTree *bt)
{
	char ch;
	ch = getchar();
    if(ch=='#') *bt=NULL;
    else 
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); //����һ���½��
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild)); //����������
        CreateBiTree(&((*bt)->RChild)); //����������
	}
}
void  PreOrder(BiTree root) 
/*�������������, rootΪָ�������������ָ��*/
{
	if (root!=NULL)
	{
		printf("%c  ",root ->data);  /*������*/
		PreOrder(root ->LChild);  /*�������������*/
		PreOrder(root ->RChild);  /*�������������*/
	}
}

void  InOrder(BiTree root)  
/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
{
	if(root->LChild != NULL){
		InOrder(root->LChild);
	}
	printf("%c  ",root->data);
	if(root->RChild != NULL){
		InOrder(root->RChild);
	}
}

void  PostOrder(BiTree root)  
/* ���������������rootΪָ�������(��ĳһ����)������ָ��*/
{
	if (root->LChild != NULL){
		PostOrder(root->LChild);
	}
	if (root->RChild != NULL){
		PostOrder(root->RChild);
	}
	printf("%c  ",root->data);
}


int count[10010] = {0};
void PrintTree(BiTree bt,int nLayer)  /*��������״��ӡ�Ķ�����*/
{
	if(bt!=NULL){
		count[nLayer] += 1;
		PrintTree(bt->LChild,nLayer+1);
		PrintTree(bt->RChild,nLayer+1);
	}
}

void  Pre_Count(BiTree root,int &cnt) 
{
	if (root!=NULL)
	{
		cnt += 1;
		Pre_Count(root ->LChild,cnt);  /*�������������*/
		Pre_Count(root ->RChild,cnt);  /*�������������*/
	}
}

void Count_leaves(BiTree root,int &cnt){
	if(root->LChild == NULL && root->RChild == NULL){
		cnt += 1;
	}else if(root != NULL){
		Count_leaves(root->LChild,cnt);
		Count_leaves(root->RChild,cnt);
	}
}

int main()
{
	BiTree T;
	int layer=0,cnt = 0,cnt_2 = 0;
	printf("����չ����������н���������������������:\n");
    CreateBiTree(&T);
	printf("��������������Ϊ:");
	PreOrder(T);
	printf("\n���ڵ���Ϊ:");
	Pre_Count(T,cnt);
	printf("%d",cnt);
	printf("\nҶ�ӽڵ���Ϊ:");
	Count_leaves(T,cnt_2);
	printf("%d",cnt_2);	
	printf("\n��������������Ϊ:");
	InOrder(T);
	printf("\n��������������Ϊ:");
	PostOrder(T);
    printf("\n��������״��ӡ������:\n");
	PrintTree(T,layer);
	return 0;
}
