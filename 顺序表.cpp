#include<iostream>
using namespace std;
typedef int et;

typedef struct{
	et *data;
	int length;
}SqList;

void CreateList(SqList *&L, et a[],int n){
	L = new SqList;
	L->data = new et[n];
	for(int i = 0;i < n;i++){
		L->data[i] = a[i];
	}
	L->length = n;
}

void DeleteList(SqList *&L){
	if(L != nullptr){
		delete[] L->data;
		delete L;
		l = nullptr;
	}	
}

void PrintList(SqList *L){
	if(L != nullptr){
		 
	} 
} 
