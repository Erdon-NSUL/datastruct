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
		*bt=(BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild)); //生成左子树
        CreateBiTree(&((*bt)->RChild)); //生成右子树
	}
}
void  PreOrder(BiTree root) 
{
	if (root!=NULL)
	{
		printf("%c  ",root ->data);  
		PreOrder(root ->LChild);  
		PreOrder(root ->RChild);  
	}
}

void  InOrder(BiTree root)  
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
void PrintTree(BiTree bt,int nLayer)  /*按竖向树状打印的二叉树*/
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
		Pre_Count(root ->LChild,cnt);  /*先序遍历左子树*/
		Pre_Count(root ->RChild,cnt);  /*先序遍历右子树*/
	}
}

void Count_leaves(BiTree root,int &cnt){
	if(root == NULL)return;
		if (root->LChild  == NULL && root->RChild == NULL)
		{
			cnt++;	
			return;
		}else{
			Count_leaves(root ->LChild,cnt);  
			Count_leaves(root ->RChild,cnt);  
		}
		
	}

int main()
{
	//ABC##DE#G##F###
	BiTree T;
	int layer=0,cnt = 0,cnt_2 = 0;
	printf("按扩展先序遍历序列建立二叉树，请输入序列:\n");
    CreateBiTree(&T);
	printf("先序遍历输出序列为:");
	PreOrder(T);
	printf("\n树节点数为:");
	Pre_Count(T,cnt);
	printf("%d",cnt);
	printf("\n叶子节点数为:");
	Count_leaves(T,cnt_2);
	printf("%d",cnt_2);	
	printf("\n中序遍历输出序列为:");
	InOrder(T);
	printf("\n后序遍历输出序列为:");
	PostOrder(T);
    printf("\n按竖向树状打印二叉树:\n");
	PrintTree(T,layer);
	return 0;
}
