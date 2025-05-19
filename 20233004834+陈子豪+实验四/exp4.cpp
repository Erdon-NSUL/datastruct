#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	bool tag;
	char value;
	node *subh,*nxt;
	node(char v): tag(1),value(v),subh(nullptr),nxt(nullptr){}
	node(node* p): tag(0),value('\0'),subh(p),nxt(nullptr){}
}Node,*PNODE;

PNODE create(PNODE l,string D,int &index){
	while(index < D.size()){
		if(isspace(D[index]) || D[index] == ','){
			cout<<"space: "<<index<<endl;
			index++;
			continue;
		}
			if(D[index]== '('){
				cout<<index<<endl;
				l->tag = true;
				PNODE p = new(nothrow) Node;
				l->subh = p;
				index++;
				cout<<"++: "<<index<<endl;
				p = create(p,D,index);
			}
			else if( D[index]==')'){
				cout<<index<<endl;
				index++;
				cout<<"++: "<<index<<endl;
				return l;
			}
			else{
				cout<<index<<endl;
				l->tag = false;
				cout<<index<<endl;
				l->value = D[index];
				cout<<index<<endl;
				l->subh = nullptr;
				cout<<index<<endl;
				PNODE p = new(nothrow) Node;//构建下一个节点
				l->nxt = p;
				index++;
				cout<<"++: "<<index<<endl;
				p = create(p,D,index);
			}
		}
	}

int main(){
	string input;
	getline(cin,input);
	int index = 0;
	PNODE p;
	p = create(p,input,index);
	return 0;
}
