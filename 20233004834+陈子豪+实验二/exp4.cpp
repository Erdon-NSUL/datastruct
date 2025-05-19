#include<iostream>
#include<string>
#include <cctype>
#include<vector>
using namespace std;
typedef char ElemType;


typedef struct a{
	ElemType data;
	struct a *next = nullptr;
	struct a *prev = nullptr;
}_Stack;

int _Push(_Stack *p, _Stack *&r, ElemType e){
	_Stack *t ;

	if(p->next == nullptr){
		p->data = e;
	}
	else{
		t = new(nothrow) _Stack;
		t->data = e;
		t->prev = r;
		r->next = t;
		r = t;
	}
	return 0;
}

int _Pop(_Stack *p, _Stack *&r, ElemType e){
	_Stack *t;
	
	
	if(r == p){
		return 0;
	}
	else{
		t = r;
		e = r->data;
		r = r->prev;
		delete t;
		return 1;
	}
}

int _GetTop(_Stack *p, _Stack *r,ElemType &e){
	if ( r != p){
		e =  r->data;
	}
	return 0;
}

bool _IfEmpty(_Stack *p ,_Stack *r){
	if(r == p){return 0;}
	return 1;
}

void _Transform(string infix, string &postfix){
	_Stack *p,*r;
	ElemType e;
	int i = 0,j;
	p = new(nothrow) _Stack;
	r = p;
	
	while(i<infix.size()){
		switch (infix[i]) {
			case '(':
				_Push(p,r,'(');
				break;
			case ')':
				_GetTop(p,r,e);
				while(e!='('){
					_Pop(p,r,e);
					if(e != '('){postfix += e;}
				}
				break;
			case '+':
			case '-':
				_GetTop(p,r,e);
				if(e !='(' || _IfEmpty(p,r)){
					_Pop(p,r,e);
					if(e != '('){postfix += e;}
				}
				_Push(p,r,infix[i]);
				break;
			case '*':
			case '/':
				_GetTop(p,r,e);
				while(e !='(' ||e != '+' || e!= '-'|| _IfEmpty(p,r)){
					_Pop(p,r,e);
					if(e !='(' ||e != '+' || e!= '-'){postfix += e;}
				}
				_Push(p,r,infix[i]);
				break;
			default:
				j = i;
				while(isdigit(infix[j])){
					postfix += infix[j];
					j++;
				}
				postfix += '#';
				break;
		}
	}
	
	
}

int main(){
	string infix,postfix;
	cout << "请输入表达式：" ;
	getline(cin,infix);
	_Transform(infix,postfix);
	cout << postfix;
	return 0;
}
