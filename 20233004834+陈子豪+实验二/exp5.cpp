#include<iostream>
using namespace std;
typedef int ElemType;


typedef struct Node{
	ElemType data;
	struct Node *next = nullptr;
	struct Node *prev = nullptr;
}LinkNode;

int _Push(LinkNode *l, LinkNode *&r, ElemType e){
	LinkNode *p ;
	p = new(nothrow) LinkNode;
	p->data = e;
	if (l->next == nullptr){
		p->next = p;
	    p->prev = p;
	    l->next = p;
	}
	else{
		r->next = p;
		p->prev = r;
		p->next = l->next;
		l->next->prev = p;
	}
	r = p;
	return 0;
}

int _Pop(LinkNode *l, LinkNode *&r,ElemType &e){
	LinkNode *p;
	p = r;
	
	if(l->next == nullptr){ 
		cout << "队列已空" << endl;
	    return -1; 
	}
	
	if(l->next == r){
		e = r->data;
		r = nullptr;
		l->next = nullptr;
		delete p;
	}
	else{
		e = r->data;
		r->prev->next = r->next;
		r->next->prev = r->prev;
		r = r->prev;
		delete p;
	}
	return 0;
}

int _Empty(LinkNode *l, LinkNode *&r){
	LinkNode *p;
	if(r == nullptr){ 
		cout << "队列已为空" << endl;
	    return -1; 
	}
	else{
		while(r->prev != r){
			p = r;
			r = r->prev;
			r->next = l->next;
			l->next->prev = r;	
			delete p;
		}
		p = r;
		r = nullptr;
		delete p;
		l->next = nullptr; 
		return 0;
	}
}

void _Print(LinkNode *l){
	LinkNode *p;
	p = l->next;
	if(p == nullptr){
		cout << "队列为空";
	}else{
		while(p->next != l->next){
			cout << p->data;
			p = p->next;
		}
	cout << p->data << endl;
	}
}

int main(){
	LinkNode *l,*r = nullptr;
	l = new(nothrow) LinkNode;
	ElemType e;
	_Push(l,r,3);
	_Push(l,r,4);
	_Pop(l,r,e);
	_Pop(l,r,e);
	_Pop(l,r,e);
	_Push(l,r,3);
	_Push(l,r,4);
	_Empty(l,r);
	_Print(l);
	return 0;
}
