#include<iostream>
using namespace std;
typedef int ElemType;


typedef struct Node{
	ElemType data;
	ElemType number;
	struct Node *next;
}LinkNode;


void InitLinkNode(LinkNode *&l){
	l = new LinkNode;
	l->number = 0;
	l->next = nullptr;
}


void CreateCirLinkNode(LinkNode *&l,int n){
	if (n<=0) {
	    cout << "错误：输入值越界(>0,Z)" << endl;
	    return;
	}
	
	LinkNode *p,*r;
	ElemType e;
	l = new LinkNode;
	l->data = 0;
	l->number = 0;
	r = l;
	for(int i = 0;i<n;i++){
		cout << "请输入第" << i+1 << "个节点值:" << endl;
		cin >> e;
		p = new(nothrow) LinkNode;
		p->data = e;
		p->number = i+1;
		r->next = p;
		r = p;
	}
	r->next = l->next;
}


int YSF(LinkNode *&n, int m,int t){
	LinkNode *p = n->next,*pre = p;
	int c = 1,r;
	if(m>1){
		for(;c<m;c++){
			pre = p;
			p = p->next;
		}
	}else{
		for(;c<m+t;c++){
			pre = p;
			p = p->next;
		}	
	}
	r = p->data;
	cout << p->number << " -> ";
	pre->next = p->next;
	n = pre;
	delete p;
	return r;
}


int main(){
	LinkNode *L = nullptr;
	int n,m;
	cout << "请输入链表长度：";
	cin >> n;
	CreateCirLinkNode(L,n);
	cout << "任选一个整数作为报数上限值m(m>0):";
	cin >> m ;
	if(m <= 0){
		cout <<"大傻春你要干嘛？" << endl;
	}
	cout << "出列顺序:" << endl;
	for(int i = n;i>1;i--){
		m = YSF(L,m,i);
	}
	cout << L->next->number;
	return 0;
}
