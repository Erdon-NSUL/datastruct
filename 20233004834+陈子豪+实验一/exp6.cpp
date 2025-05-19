#include<iostream>
using namespace std;
typedef int ElemType;


typedef struct Node{
	ElemType data;
	struct Node *next;
}LinkNode;


void CreateLinkNodeFromArr(LinkNode *&l,ElemType arr[],int len){	
	LinkNode *p,*r;
	l = new LinkNode;
	r = l;
	for(int i = 0;i<len;i++){
		p = new(nothrow) LinkNode;
		p->data = arr[i];
		r->next = p;
		r = p;
	}
	r->next = nullptr;
}

void DeleteNode(LinkNode *&p,LinkNode *&pre){
	pre->next = p->next;
	delete p;
	p = pre;
}

void Algo(LinkNode *&l){
	LinkNode *p = l->next,*q,*qpre;
	while(p != nullptr){
		q = p->next;
		qpre = p;
		while(q != nullptr){
			if(q->data == p->data){
				qpre->next = q->next;
				delete q;
				q = qpre->next;
			}else{
				qpre = q;
				q = q->next;
			}	
		}
		p = p->next;
	}

}

int main(){
	LinkNode *l = nullptr,*p;
	int arr[] = {1,1,2,2,3,3,4,4,5,7,6,7,5,4,3,2,1};
	size_t len = sizeof(arr)/sizeof(arr[0]);
	CreateLinkNodeFromArr(l,arr,len);
	Algo(l);
	p = l->next;
	cout << "处理过的链表长这样：" << endl;
	while(p!=NULL){
		cout << p->data << " ";
		p=p->next;
	}
	
}
